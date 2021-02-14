#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(std::unique_ptr<QWidget> parent) :
    QMainWindow(parent.get()),
    ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);

    //TO DO:make function
    ui->lineEditN->setValidator(new QRegExpValidator(QRegExp("0|(^[1-9][0-9]?$|^100$)"), this));
    ui->lineEditAddPoints->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
    ui->lineEditA->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
    ui->lineEditB->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
    ui->lineEditML->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
    ui->lineEditMU->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));

    connect(ui->pushButtonStep1, &QPushButton::released, this, &MainWindow::SelectButtonStep1);
    connect(ui->pushButtonAddPoints, &QPushButton::released, this, &MainWindow::AddPointsButton);
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
    result = generateFk(mathParser, k, x0, y0);

    return result;
}

void MainWindow::plotting(int n)
{

    ui->potWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->potWidget->legend->setVisible(true);

    QFont legendFont = font();  // start out with MainWindow's font..
    legendFont.setPointSize(9); // and make a bit smaller for legend
    ui->potWidget->legend->setFont(legendFont);
    ui->potWidget->legend->setBrush(QBrush(QColor(255,255,255,230)));

    //ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->potWidget->graph(0)->setLineStyle(QCPGraph::lsNone);

    // generate data, just playing with numbers, not much to learn here:
    QVector<double> x4, y4;


    auto readFile=[&](int start,std::string fileName)
    {
        for (std::ifstream in(fileName); !in.eof();)
            {
                std::string line;
                std::getline(in, line);
                if (std::regex_match(line, std::regex(R"(\d*.\d* \d*.\d*)"))) {
                    std::stringstream ss(line);
                    std::string item;

                    std::getline(ss, item, ' ');
                    x4.push_back( std::move(std::stod(item)));
                    std::getline(ss, item, ' ');
                    y4.push_back(std::move(std::stod(item)));
                    ++start;
                }
            }
    };

    readFile(0, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file1.txt");
    readFile(n/4, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file2.txt");
    readFile(n*2/4, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file3.txt");
    readFile(n*3/4, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file4.txt");


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
    // set labels:
    ui->potWidget->xAxis->setLabel("Bottom axis with outward ticks");
    ui->potWidget->yAxis->setLabel("Left axis label");
    ui->potWidget->xAxis2->setLabel("Top axis label");
    ui->potWidget->yAxis2->setLabel("Right axis label");

    ui->potWidget->replot();

}

void MainWindow::SelectButtonStep1()
{
    int n = 10000;
    CMathParser parser;
    ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    auto generate =[&](int start, int stop, std::string fileName){
        std::ofstream out(fileName);
        for (int i=start; i < stop; ++i) // data for graphs 2, 3 and 4
            {
                QCPGraphData temp = generate2DPoints(parser);
                out<< temp.key<<" "<< temp.value<<"\n";
            }
    out.close();
    };
    std::thread t1{generate, 0, n/4, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file1.txt"};
    std::thread t2{generate, n/4, n*2/4, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file2.txt"};
    std::thread t3{generate, n*2/4, n*3/4, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file3.txt"};
    std::thread t4{generate, n*3/4, n, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file4.txt"};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    plotting(n);

}


void MainWindow::AddPointsButton()
{
    static int add=10000;
    int n = ui->lineEditAddPoints->text().toInt();
    CMathParser parser;
    ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    auto generate =[&](int start, int stop, std::string fileName){
        std::ofstream out(fileName,std::ios_base::app);
        for (int i=start; i < stop; ++i) // data for graphs 2, 3 and 4
            {
                QCPGraphData temp = generate2DPoints(parser);
                out<< temp.key<<" "<< temp.value<<"\n";
            }
    out.close();
    };
    std::thread t1{generate, add, n/4+add, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file1.txt"};
    std::thread t2{generate, n/4+add, n*2/4+add, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file2.txt"};
    std::thread t3{generate, n*2/4+add, n*3/4+add, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file3.txt"};
    std::thread t4{generate, n*3/4+add, n+add, "D:\\Info Unitbv 2020-2021\\Semestrul I\\Modern C++\\QtApplication\\QtExample\\QtExample\\Step1\\file4.txt"};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    plotting(n);
    add+=n;
}

MainWindow::~MainWindow()
{
    //EMPTY
}
