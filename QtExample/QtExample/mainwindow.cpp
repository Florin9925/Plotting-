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
std::string replaceConstant(const QString& input,const std::string& token,const std::string& token_value)
{
    std::string ecuation = input.toStdString();
    while (ecuation.find(token) != std::string::npos)
    {
        ecuation.replace(ecuation.find(token), token.size(), token_value);
    }

    return ecuation;

}

double MainWindow::calculateExpression(CMathParser& mathParser,const std::string& line)
{
    double result;

    if (mathParser.Calculate(line.c_str(), &result) != CMathParser::ResultOk)
    {
        return result;
    }

    return NAN;
}

double&& MainWindow::generateKthTerm(CMathParser& mathParser,const QString& line, uint8_t k)
{
   std::string ecuation((replaceConstant(line,"n",std::move(std::to_string(k)))));

   return calculateExpression(mathParser, ecuation);

}

double MainWindow::generateFComp(CMathParser& mathParser,const QString& line, uint8_t k)
{
    double comp_k = generateKthTerm(mathParser, line, k);
    double comp_k1 = generateKthTerm(mathParser, line, k -1);//Xn-1


    std::string ecuationX((replaceConstant(line,"XN",std::move(std::to_string(k)))));
    ecuationX((replaceConstant(line,"XN-1",std::move(std::to_string(k)))));
    ecuationX((replaceConstant(line,"YN",std::move(std::to_string(k)))));
    ecuationX((replaceConstant(line,"YN-1",std::move(std::to_string(k)))));
    ecuationX((replaceConstant(line,"n",std::move(std::to_string(k)))));
    ecuationX((replaceConstant(line,"n",std::move(std::to_string(k)))));
    ecuationX((replaceConstant(line,"n",std::move(std::to_string(k)))));

}


QPoint&& MainWindow::generateFk(CMathParser& mathParser, uint8_t k)
{
    std::string ecuationX((replaceConstant(line,"n",std::move(std::to_string(k)))));


    std::string ecuationY((replaceConstant(line,"n",std::move(std::to_string(k)))));
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

    std::array<double, 101> XN;
    std::array<double, 101> YN;

    std::array<bool, 101> generated;
    generated.fill(false);

    //double x_n;
    //double x_n1;//Xn-1

    //double y_n;
    //double y_n1;//Yn-1

    if(generated[k] == false)
    {
        generated[k] = true;
        XN[k] = std::move(generateKthTerm(mathParser, ui->lineEditXn->text(), k));
        YN[k] = std::move(generateKthTerm(mathParser, ui->lineEditYn->text(), k));
    }
    if(generated[k-1] == false)
    {
        generated[k-1] = true;
        XN[k-1] = std::move(generateKthTerm(mathParser, ui->lineEditXn->text(), k-1));
        YN[k-1] = std::move(generateKthTerm(mathParser, ui->lineEditYn->text(), k-1));
    }

     vector.emplace_back(QVector2D(std::move(disDouble(gen)),std::move(disDouble(gen))));

}

bool MainWindow::CheckConstraintN()
{
    //ui->lineEditN->setValidator( new QIntValidator(0, 100, this) );
    //ui->lineEditN->text().toStdString().c_str());

    return true;
}

void MainWindow::SelectButtonStep1()
{
    //TO DO:calculate ecuation function
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


    //TO DO: initialize generate vector function
    std::vector<QVector2D> points;
    generate2DPoints(static_cast<uint8_t>(ui->lineEditN->text().toUShort()), points);


    //
    QMessageBox qm;

    qm.setText(QString::number(points[0].x()));

    qm.exec();
}

MainWindow::~MainWindow()
{
    //EMPTY
}
