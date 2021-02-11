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
    double comp_k1 = generateKthTerm(mathParser, seriesLine, k -1);//Xn-1


    std::string ecuationComp;
    ecuationComp = replaceConstant(lineToEdit.toStdString(),"(XN)",std::move(std::to_string(comp_k)));
    ecuationComp = replaceConstant(ecuationComp,"(XN-1)",std::move(std::to_string(comp_k1)));
    ecuationComp = replaceConstant(ecuationComp,"(DN)",ui->lineEditDN->text().toStdString());
    ecuationComp = replaceConstant(ecuationComp,"X",std::move(std::to_string(x)));
    ecuationComp = replaceConstant(ecuationComp,"Y",std::move(std::to_string(y)));

    ui->lineEditMU->setText(QString::fromStdString(ecuationComp));

    double result = calculateExpression(mathParser, ecuationComp);

    ui->lineEditDN->setText(QString::number(result));

    return calculateExpression(mathParser, ecuationComp);

}


QVector2D MainWindow::generateFk(CMathParser& mathParser, uint8_t k, double x, double y)
{
    QVector2D resultPoint;

    resultPoint.setX(generateFComp(mathParser, ui->lineEditFx->text(),ui->lineEditXn->text(), k, x, y));

    resultPoint.setY(generateFComp(mathParser, ui->lineEditFy->text(),ui->lineEditXn->text(), k, x, y));


    return resultPoint;
}


void MainWindow::generate2DPoints(CMathParser& mathParser,uint8_t n,std::vector<QVector2D>& vector)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disDouble(0.0, 1.0);

    std::uniform_int_distribution<> disInt(1,100);

    uint8_t k = disInt(gen);

    double x0 = disDouble(gen);
    double y0 = disDouble(gen);


    ui->lineEditA->setText(QString::number(x0));

    ui->lineEditB->setText(QString::number(y0));

    ui->lineEditML->setText(QString::number(k));
    //std::array<double, 101> XN;
    //std::array<double, 101> YN;

    //std::array<bool, 101> generated;
    //generated.fill(false);

    //double x_n;
    //double x_n1;//Xn-1

    //double y_n;
    //double y_n1;//Yn-1

    double result = generateFComp(mathParser, ui->lineEditFx->text(), ui->lineEditXn->text(), k, x0, y0);//generateKthTerm(mathParser, ui->lineEditXn->text(), k);
    //ui->lineEditMU->setText(QString::number(result));

    //vector.emplace_back(QVector2D(generateFk(mathParser,k,x0,y0)));

}

bool MainWindow::CheckConstraintN()
{
    //ui->lineEditN->setValidator( new QIntValidator(0, 100, this) );
    //ui->lineEditN->text().toStdString().c_str());

    return true;
}

void MainWindow::SelectButtonStep1()
{

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
    std::vector<QVector2D> points;
    CMathParser parser;

    generate2DPoints(parser,static_cast<uint8_t>(ui->lineEditN->text().toUShort()), points);


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
