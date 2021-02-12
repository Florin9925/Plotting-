#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(std::unique_ptr<QWidget> parent) :
    QMainWindow(parent.get()),
    ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);

    //TO DO:make function
    QRegExp rx("0|(^[1-9][0-9]?$|^100$)");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEditN->setValidator(validator);

    connect(ui->pushButtonStep1, &QPushButton::released, this, &MainWindow::SelectButtonStep1);
    //connect(ui->pushButtonStep2, &QPushButton::released, this, &MainWindow::SelectButtonStep2);

}

std::string MainWindow::replaceConstant(const std::string& input,const std::string& token,const std::string& token_value)
{
    std::string ecuation = input;
    while (ecuation.find(token) != std::string::npos)
    {
        ecuation.replace(ecuation.find(token), token.size(), token_value);
    }

    return ecuation;

}

double MainWindow::calculateExpression(CMathParser& mathParser,const std::string& line)
{
    double result;

    if (mathParser.Calculate(line.c_str(), &result) == CMathParser::ResultOk)
    {
        return result;
    }

    return NAN;
}

double MainWindow::generateKthTerm(CMathParser& mathParser,const QString& line, uint8_t k)
{
   std::string ecuation((replaceConstant(line.toStdString(),"n",std::move(std::to_string(k)))));

   return calculateExpression(mathParser, ecuation);

}

double MainWindow::generateFComp(CMathParser& mathParser,const QString& lineToEdit,const QString& seriesLine, uint8_t k, double x, double y)
{
    double comp_k = generateKthTerm(mathParser, seriesLine, k);
    double comp_k1 = generateKthTerm(mathParser, seriesLine, k - 1);//Xn-1


    std::string ecuationComp;
    ecuationComp = replaceConstant(lineToEdit.toStdString(),"(XN)",std::move(std::to_string(comp_k)));
    ecuationComp = replaceConstant(ecuationComp,"(XN-1)",std::move(std::to_string(comp_k1)));
    ecuationComp = replaceConstant(ecuationComp,"(YN)",std::move(std::to_string(comp_k)));
    ecuationComp = replaceConstant(ecuationComp,"(YN-1)",std::move(std::to_string(comp_k1)));
    ecuationComp = replaceConstant(ecuationComp,"(M)",ui->lineEditMU->text().toStdString());
    ecuationComp = replaceConstant(ecuationComp,"m",ui->lineEditML->text().toStdString());
    ecuationComp = replaceConstant(ecuationComp,"a",ui->lineEditA->text().toStdString());
    ecuationComp = replaceConstant(ecuationComp,"b",ui->lineEditB->text().toStdString());
    ecuationComp = replaceConstant(ecuationComp,"(DN)",ui->lineEditDN->text().toStdString());
    ecuationComp = replaceConstant(ecuationComp,"X",std::move(std::to_string(x)));
    ecuationComp = replaceConstant(ecuationComp,"Y",std::move(std::to_string(y)));

    return calculateExpression(mathParser, ecuationComp);

}


QCPGraphData MainWindow::generateFk(CMathParser& mathParser, uint8_t k, double x, double y)
{
    QCPGraphData resultPoint;

    resultPoint.key = generateFComp(mathParser, ui->lineEditFx->text(),ui->lineEditXn->text(), k, x, y);

    resultPoint.value = generateFComp(mathParser, ui->lineEditFy->text(),ui->lineEditYn->text(), k, x, y);

    return resultPoint;
}


QCPGraphData MainWindow::generate2DPoints(CMathParser& mathParser)
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disDouble(0.0, 1.0);
    std::uniform_int_distribution<> disInt(1,100);
    QCPGraphData result;
    uint8_t k = disInt(gen);

    double x0 = disDouble(gen);
    double y0 = disDouble(gen);

    //ui->lineEditX0->setText(QString::number(x0));

    //ui->lineEditY0->setText(QString::number(y0));

    //ui->lineEditK->setText(QString::number(k));

    //std::array<double, 101> XN;
    //std::array<double, 101> YN;
    //std::array<bool, 101> generated;
    //generated.fill(false);

    //double x_n;
    //double x_n1;//Xn-1

    //double y_n;
    //double y_n1;//Yn-1

    result = generateFk(mathParser, k, x0, y0);

    //ui->lineEditXnPrint->setText(QString::number(result.key));
    //ui->lineEditYnPrint->setText(QString::number(result.value));

    return result;
}

void MainWindow::plotting(CMathParser& mathParser,uint8_t n)
{

    ui->potWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->potWidget->legend->setVisible(true);
    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->potWidget->legend->setFont(legendFont);
    ui->potWidget->legend->setBrush(QBrush(QColor(255,255,255,230)));
    // by default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement:
    //ui->potWidget->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

    // setup for graph 4: key axis right, value axis top
    // will contain parabolically distributed data points with some random perturbance
    //ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->potWidget->graph(0)->setLineStyle(QCPGraph::lsNone);
    //ui->potWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));
    //ui->potWidget->graph(0)->setName("Some random data around\na quadratic function");

    // generate data, just playing with numbers, not much to learn here:
    QVector<double> x4(10000), y4(10000);

    //float Sx=0.5;
    //float Sy=2.0;

    QString Xs("");
    QString Ys("");
    for (int i=0; i<10000; ++i) // data for graphs 2, 3 and 4
    {
      QCPGraphData temp = generate2DPoints(mathParser);

      x4[i] = temp.key;//CONVERTOR.LatitudeToPx(temp.key);
      y4[i] = temp.value;//CONVERTOR.LongitudeToPx(temp.value);

      Xs += QString::number(x4[i]) + " ";
      Ys += QString::number(y4[i]) + " ";

      ui->potWidget->replot();
    }
    ui->lineEditX0->setText(Xs);
    ui->lineEditY0->setText(Ys);

    //ui->potWidget->graph(0)->antialiased();
    //ui->potWidget->graph(0)->rescaleAxes(true);
    // pass data points to graphs:
    ui->potWidget->graph(0)->setData(y4, x4);
    // activate top and right axes, which are invisible by default:
    ui->potWidget->xAxis2->setVisible(true);
    ui->potWidget->yAxis2->setVisible(true);
    // set ranges appropriate to show data:
    ui->potWidget->xAxis->setRange(-0.5, 1.5);
    ui->potWidget->xAxis2->setRange(-0.5, 1.5);
    ui->potWidget->yAxis->setRange(-0.5, 1.5);
    ui->potWidget->yAxis2->setRange(-0.5, 1.5);
    // set pi ticks on top axis:
    //ui->potWidget->xAxis2->setTicker(QSharedPointer<QCPAxisTickerPi>(new QCPAxisTickerPi));
    // add title layout element:
    //ui->potWidget->plotLayout()->insertRow(0);
    //ui->potWidget->plotLayout()->addElement(0, 0, new QCPTextElement(ui->potWidget, "Way too many graphs in one plot", QFont("sans", 12, QFont::Bold)));
    // set labels:
    ui->potWidget->xAxis->setLabel("Bottom axis with outward ticks");
    ui->potWidget->yAxis->setLabel("Left axis label");
    ui->potWidget->xAxis2->setLabel("Top axis label");
    ui->potWidget->yAxis2->setLabel("Right axis label");
    // make ticks on bottom axis go outward:
   // ui->potWidget->xAxis->setTickLength(0, 5);
   // ui->potWidget->xAxis->setSubTickLength(0, 3);
    // make ticks on right axis go inward and outward:
   // ui->potWidget->yAxis2->setTickLength(3, 3);
   // ui->potWidget->yAxis2->setSubTickLength(1, 1);

    ui->potWidget->replot();

}

void MainWindow::SelectButtonStep1()
{

    CMathParser parser;
    ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));
    plotting(parser, ui->lineEditN->text().toUInt());


    /*
    QString lineA = ui->lineEditA->text();

    CMathParser parser;
    double result;

    std::string token = "n";
    std::string token_value = ui->lineEditN->text().toStdString();

    std::string ecuation = lineA.toStdString();

    while (ecuation.find(token) != std::string::npos)
    {
        ecuation.replace(ecuation.find(token), token.size(), token_value);
    }

    if (parser.Calculate(ecuation.c_str(), &result) != CMathParser::ResultOk)
    {
        printf("Error in Formula: [%s].\n", parser.LastError()->Text);
    }
    */


    //TO DO: initialize generate vector function

    //generate2DPoints(parser,static_cast<uint8_t>(ui->lineEditN->text().toUShort()), points);


    //QMessageBox qm;

    //QString result;
    //result = QString::number(points[0].x()) + QString::number(points[0].y());

    //qm.setText(result);

    //qm.exec();
}

MainWindow::~MainWindow()
{
    //EMPTY
}
