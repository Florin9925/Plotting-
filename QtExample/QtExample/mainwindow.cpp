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
    connect(ui->pushButtonStep2, &QPushButton::released, this, &MainWindow::SelectButtonStep2);
    connect(ui->pushButtonAddPoints, &QPushButton::released, this, &MainWindow::AddPointsButton);
    //connect(ui->pushButtonStep2, &QPushButton::released, this, &MainWindow::SelectButtonStep2);

}

std::string MainWindow::replaceConstant(const std::string& input,const std::string& token,const std::string& token_value)
{
    std::string ecuation = input;
    std::size_t start = input.find(token);

    while (start != std::string::npos)
      {
         ecuation.replace(start, token.size(), token_value);

         start = ecuation.find(token);

    }

    return ecuation;

}

void MainWindow::replaceConstant(std::string& input,const std::unordered_map<std::string,std::string>& tokens)
{

    std::size_t start = std::string::npos;

    for (auto itr : tokens)
      {
        start = input.find(itr.first);
        while (start != std::string::npos)
          {
             input.replace(start, itr.first.size(), itr.second);

             start = input.find(itr.first);

        }

    }

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
   std::string ecuation = line.toStdString();

   ecuation = replaceConstant(ecuation, "n", std::to_string(k));

   return calculateExpression(mathParser, ecuation);


   //replaceConstant(line, constants);

}

double MainWindow::generateFComp(CMathParser& mathParser,std::string& lineToEdit,double xComp_k, double xComp_k1,double yComp_k, double yComp_k1, double x, double y)
{

    /*
    std::string ecuationComp(lineToEdit.toStdString());
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
    */

    std::string ecuationComp(lineToEdit);

    std::unordered_map<std::string,std::string> constants;
    constants.insert({"(XN)", std::to_string(xComp_k)});
    constants.insert({"(XN-1)", std::to_string(xComp_k1)});
    constants.insert({"(YN)", std::to_string(yComp_k)});
    constants.insert({"(YN-1)", std::to_string(yComp_k1)});
    constants.insert({"X", std::to_string(x)});
    constants.insert({"Y", std::to_string(y)});

    replaceConstant(ecuationComp, constants);

    return calculateExpression(mathParser, ecuationComp);
}

QCPGraphData MainWindow::generateFk(CMathParser& mathParser, uint8_t k, double x, double y,std::string& fX,std::string& fY)
{
    QCPGraphData resultPoint;

    resultPoint.key = generateFComp(mathParser, fX, xK[k], xK[k-1], yK[k], yK[k-1],x,y);

    resultPoint.value = generateFComp(mathParser, fY, xK[k], xK[k-1], yK[k], yK[k-1],x,y);

    return resultPoint;
}


QCPGraphData MainWindow::generate2DPoints(CMathParser& mathParser,std::string& fX,std::string& fY)
{

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disDouble(0.0, 1.0);
    std::uniform_int_distribution<> disInt(1,100);
    QCPGraphData result;
    uint8_t k = disInt(gen);

    double x0 = disDouble(gen);
    double y0 = disDouble(gen);

    return generateFk(mathParser, k, x0, y0, fX, fY);;
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

    readFile(0, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file1.txt");
    readFile(n/4, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file2.txt");
    readFile(n*2/4, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file3.txt");
    readFile(n*3/4, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file4.txt");


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

void MainWindow::replaceFunction(std::string& line)
{
    std::unordered_map<std::string,std::string> constants;
    constants.insert({"(M)", ui->lineEditMU->text().toStdString()});
    constants.insert({"m", ui->lineEditML->text().toStdString()});
    constants.insert({"a", ui->lineEditA->text().toStdString()});
    constants.insert({"b", ui->lineEditB->text().toStdString()});
    constants.insert({"(DN)", ui->lineEditDN->text().toStdString()});

    replaceConstant(line, constants);
}

void MainWindow::generateKthTerms(CMathParser& parser)
{
    for(uint8_t index = 0; index <= 100; ++index)
    {
        xK.at(index) = generateKthTerm(parser, ui->lineEditXn->text(), index);
        yK.at(index) = generateKthTerm(parser, ui->lineEditYn->text(), index);
    }
}

void MainWindow::SelectButtonStep1()
{
    int n = 10;
    CMathParser parser;


    //Generez toti xn,yn
    generateKthTerms(parser);

    ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

    std::string fX(ui->lineEditFx->text().toStdString()), fY(ui->lineEditFy->text().toStdString());

    replaceFunction(fX);
    replaceFunction(fY);

    auto generate =[&](int start, int stop, std::string fileName){
        std::ofstream out(fileName);
        for (int i=start; i < stop; ++i) // data for graphs 2, 3 and 4
            {
                QCPGraphData temp = generate2DPoints(parser,fX,fY);
                out<< temp.key<<" "<< temp.value<<"\n";
            }
    out.close();
    };


    std::thread t1{generate, 0, n/4, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file1.txt"};
    std::thread t2{generate, n/4, n*2/4, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file2.txt"};
    std::thread t3{generate, n*2/4, n*3/4, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file3.txt"};
    std::thread t4{generate, n*3/4, n, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file4.txt"};
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    plotting(n);

}

void MainWindow::SelectButtonStep2()
{
    CMathParser parser;

    generateKthTerms(parser);

    /*
    for(int index = 0; index < 10000; index++)
    {

    QCPGraphData temp = generate2DPoints(parser,fX,fY);
    s += QString::number(temp.key) + QString::number(temp.value);

    }
    ui->lineEditX0->setText(s);
    */

}

void MainWindow::AddPointsButton()
{
    static int add=10000;
    int n = ui->lineEditAddPoints->text().toInt();
    CMathParser parser;

    generateKthTerms(parser);
    ui->potWidget->addGraph(ui->potWidget->yAxis2, ui->potWidget->xAxis2);
    ui->potWidget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 1));

     std::string fX(ui->lineEditFx->text().toStdString()), fY(ui->lineEditFy->text().toStdString());

    replaceFunction(fX);
    replaceFunction(fY);

    auto generate =[&](int start, int stop, std::string fileName){
        std::ofstream out(fileName,std::ios_base::app);
        for (int i=start; i < stop; ++i) // data for graphs 2, 3 and 4
            {
                QCPGraphData temp = generate2DPoints(parser, fX, fY);
                out<< temp.key<<" "<< temp.value<<"\n";
            }
    out.close();
    };
    std::thread t1{generate, add, n/4+add, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file1.txt"};
    std::thread t2{generate, n/4+add, n*2/4+add, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file2.txt"};
    std::thread t3{generate, n*2/4+add, n*3/4+add, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file3.txt"};
    std::thread t4{generate, n*3/4+add, n+add, "C:\\Users\\Dinu\\Desktop\\Proiect Baico\\QtExample\\QtExample\\Step1\\file4.txt"};
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
