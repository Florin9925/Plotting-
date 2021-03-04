#include "mainwindow.h"
#include <QMessageBox>



MainWindow::MainWindow(std::unique_ptr<QWidget> parent) : QMainWindow(parent.get()),
ui(new Ui::MainWindowClass)
{
	ui->setupUi(this);


	ui->lineEditAddPoints->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditA->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditB->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditML->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditMU->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditInitialPoints->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditK->setValidator(new QRegExpValidator(QRegExp("(^[1-9][1-9]?$|^100$)"), this));
	ui->lineEditN->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));
	ui->lineEditP->setValidator(new QRegExpValidator(QRegExp("^[0-9]+$"), this));

	connect(ui->pushButtonStep1, &QPushButton::clicked, this, &MainWindow::SelectButtonStep1);
	connect(ui->pushButtonStep2, &QPushButton::released, this, &MainWindow::SelectButtonStep2);
	connect(ui->pushButtonAddPoints, &QPushButton::released, this, &MainWindow::AddPointsButton);
	connect(ui->pushButtonDefaultStep1, &QPushButton::released, this, &MainWindow::DefaultStep1);
	connect(ui->pushButtonDefaultStep2, &QPushButton::released, this, &MainWindow::DefaultStep2);
	connect(ui->pushButtonClean, &QPushButton::released, this, &MainWindow::Clean);
	connect(ui->pushButtonReadXML, &QPushButton::clicked, this, &MainWindow::ReadXML);
	connect(ui->actionExit, &QAction::triggered, this, &MainWindow::ActionExit);
    connect(ui->actionHelp, &QAction::triggered, this, &MainWindow::ActionHelp);
    std::ofstream f1(Data::Defaults::PATH_STEP1+"Hello.txt");
    f1.close();
    std::ofstream f2(Data::Defaults::PATH_STEP2+"Hello.txt");
    f2.close();

    help->setStyleSheet("QWidget{ background-color: #19232D;border: 0px solid #32414B;padding: 0px;color: #F0F0F0;selection - background - color: #1464A0;selection - color: #F0F0F0;}");
}

std::string MainWindow::replaceConstant(const std::string& input, const std::string& token, const std::string& token_value)
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

void MainWindow::replaceConstant(std::string& input, const std::unordered_map<std::string, std::string>& tokens)
{

	std::size_t start = std::string::npos;

	for (auto& itr : tokens)
	{
		start = input.find(itr.first);
		while (start != std::string::npos)
		{
			input.replace(start, itr.first.size(), itr.second);

			start = input.find(itr.first);
		}
	}
}

double MainWindow::calculateExpression(CMathParser& mathParser, const std::string& line)
{
	double result;

	if (mathParser.Calculate(line.c_str(), &result) == CMathParser::ResultOk)
	{
		result = ((int)(result * precision)) / precision;
		return result;
	}

	return NAN;
}

double MainWindow::generateKthTerm(CMathParser& mathParser, const QString& line, uint8_t k)
{
	std::string ecuation = line.toStdString();

	ecuation = replaceConstant(ecuation, "n", std::to_string(k));

	return calculateExpression(mathParser, ecuation);

}

double MainWindow::generateFComp(CMathParser& mathParser, std::string& lineToEdit, double xComp_k, double xComp_k1, double yComp_k, double yComp_k1, double x, double y, uint8_t k)
{
	std::string ecuationComp(lineToEdit);

	std::unordered_map<std::string, std::string> constants;
	constants.insert({ "(XN)", std::to_string(xComp_k) });
	constants.insert({ "(XN-1)", std::to_string(xComp_k1) });
	constants.insert({ "(YN)", std::to_string(yComp_k) });
	constants.insert({ "(YN-1)", std::to_string(yComp_k1) });
	constants.insert({ "X", std::to_string(x) });
	constants.insert({ "Y", std::to_string(y) });
	constants.insert({ "n", std::to_string(k) });

	replaceConstant(ecuationComp, constants);

	return calculateExpression(mathParser, ecuationComp);
}

QCPGraphData MainWindow::generateFk(CMathParser& mathParser, uint8_t k, double x, double y, std::string& fX, std::string& fY)
{
	QCPGraphData resultPoint;

	resultPoint.key = generateFComp(mathParser, fX, xK[k], xK[k - 1], yK[k], yK[k - 1], x, y, k);

	resultPoint.value = generateFComp(mathParser, fY, xK[k], xK[k - 1], yK[k], yK[k - 1], x, y, k);

	return resultPoint;
}

QCPGraphData MainWindow::generate2DPoints(CMathParser& mathParser, std::string& fX, std::string& fY, const double& x, const double& y, int k)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> disInt(1, 100);
	QCPGraphData result;
	if (k == -1) k = disInt(gen);

	return generateFk(mathParser, k, x, y, fX, fY);
}

void MainWindow::plotting(int numberFile)
{
    ui->potWidget->clearGraphs();
    ui->potWidget->clearItems();
	ui->potWidget->legend->clearItems();
	ui->potWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
	ui->potWidget->legend->setVisible(true);

	QFont legendFont = font();  // start out with MainWindow's font..
	legendFont.setPointSize(9); // and make a bit smaller for legend
	ui->potWidget->addGraph();
	ui->potWidget->graph(0)->setPen(QPen(Qt::black)); // line color blue for first graph
	set k;

	auto readFile = [&](std::string fileName) {
		for (std::ifstream in(fileName); !in.eof();)
		{
			std::string line;
			std::getline(in, line);
			if (std::regex_match(line, std::regex(R"([+-]?(\d*.\d*) [+-]?(\d*.\d*))")))
			{
				std::stringstream ss(line);
				std::string item;
				std::getline(ss, item, ' ');

				double x = std::stod(item);
				std::getline(ss, item, ' ');
				double y = std::stod(item);
				k.insert({ x,y });
			}
		}
	};

	for (int index = 1; index <= numberFile; ++index)
	{
		readFile(Data::Defaults::PATH_STEP1 + "file" + std::to_string(index) + ".txt");
	}

	QVector<double> xVector;
	QVector<double> yVector;

	for (auto& item : k)
	{
		xVector.push_back(std::move(item.first));
		yVector.push_back(std::move(item.second));
	}

	ui->potWidget->xAxis2->setVisible(true);
	ui->potWidget->xAxis2->setTickLabels(false);
	ui->potWidget->yAxis2->setVisible(true);
	ui->potWidget->yAxis2->setTickLabels(false);
	// make left and bottom axes always transfer their ranges to right and top axes:
	connect(ui->potWidget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->potWidget->xAxis2, SLOT(setRange(QCPRange)));
	connect(ui->potWidget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->potWidget->yAxis2, SLOT(setRange(QCPRange)));
	// pass data points to graphs:
	ui->potWidget->graph(0)->setData(xVector, yVector);
	// activate top and right axes, which are invisible by default:
	ui->potWidget->graph(0)->rescaleAxes();
	// set ranges appropriate to show data:
	// set labels:
	ui->potWidget->xAxis->setLabel("Bottom axis label");
	ui->potWidget->yAxis->setLabel("Left axis label");
	ui->potWidget->xAxis2->setLabel("Top axis label");
	ui->potWidget->yAxis2->setLabel("Right axis label");
	ui->potWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	ui->potWidget->replot();
}

void MainWindow::plottingStep2(const int& n, const int& p)
{
	// set locale to english, so we get english month names:
	QVector<Qt::GlobalColor> colors;
	colors.push_back(Qt::red);
	colors.push_back(Qt::gray);
	colors.push_back(Qt::blue);
	colors.push_back(Qt::yellow);
	colors.push_back(Qt::cyan);
	colors.push_back(Qt::magenta);
	colors.push_back(Qt::green);
	colors.push_back(Qt::black);

    ui->potWidget->clearGraphs();
    ui->potWidget->clearItems();
    ui->potWidget->legend->clearItems();
    ui->potWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom)); // period as decimal separator and comma as thousand separator
    ui->potWidget->legend->setVisible(true);

	QVector<double> xVectorK0;
	QVector<double> yVectorK0;

	for (std::ifstream in(Data::Defaults::PATH_STEP2 + "K0\\f1.txt"); !in.eof();)
	{
		std::string line;
		std::getline(in, line);
		if (std::regex_match(line, std::regex(R"([+-]?(\d*.\d*) [+-]?(\d*.\d*))")))
		{
			std::stringstream ss(line);
			std::string item;
			std::getline(ss, item, ' ');

			double x = std::stod(item);
			std::getline(ss, item, ' ');
			double y = std::stod(item);
			xVectorK0.push_back(x);
			yVectorK0.push_back(y);
		}
	}
	ui->potWidget->addGraph();
	//ui->potWidget->graph()->setLineStyle(QCPGraph::lsLine);
	ui->potWidget->graph(0)->setPen(QPen(colors[0]));
	ui->potWidget->graph(0)->setData(xVectorK0, yVectorK0);
	ui->potWidget->graph()->setLineStyle(QCPGraph::lsLine);
	//ui->potWidget->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 3));

	for (int indexDir = 1; indexDir <= p; ++indexDir)
	{
		set K;
		for (int indexFile = 1; indexFile <= n; ++indexFile)
		{
			for (std::ifstream in(Data::Defaults::PATH_STEP2 + "K" + std::to_string(indexDir) + "\\f" + std::to_string(indexFile) + ".txt"); !in.eof();)
			{
				std::string line;
				std::getline(in, line);
				if (std::regex_match(line, std::regex(R"([+-]?(\d*.\d*) [+-]?(\d*.\d*))")))
				{
					std::stringstream ss(line);
					std::string item;
					std::getline(ss, item, ' ');

					double x = std::stod(item);
					std::getline(ss, item, ' ');
					double y = std::stod(item);
					K.insert({ x,y });


				}
			}

		}
		QVector<double> xVector;
		QVector<double> yVector;
		for (auto& it : K)
		{
			xVector.push_back(it.first);
			yVector.push_back(it.second);
		}
		ui->potWidget->addGraph();
		//QColor color(20 + 200 / 4.0 * (indexDir - 1), 70 * (1.6 - (indexDir - 1) / 4.0), 150, 255);
		//ui->potWidget->graph()->setLineStyle(QCPGraph::lsLine);
		if (indexDir < colors.size())
			ui->potWidget->graph(indexDir)->setPen(QPen(colors[indexDir]));
		else
		{
			QColor color(20 + 200 / 4.0 * (indexDir - 1), 70 * (1.6 - (indexDir - 1) / 4.0), 150, 255);
			ui->potWidget->graph(indexDir)->setPen(QPen(color));
		}
		ui->potWidget->graph(indexDir)->setData(xVector, yVector);
		ui->potWidget->graph()->setLineStyle(QCPGraph::lsLine);
	}



	//std::unique_ptr<QCPSelectionDecorator> decorator = std::make_unique<QCPSelectionDecorator>();
	//decorator->setPen(QPen(Qt::green, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

	//ui->potWidget->graph()->setSelectionDecorator(nullptr);
	//ui->potWidget->graph()->setSelectable(QCP::SelectionType::stSingleData);
	//ui->potWidget->graph(p - 1)->setVisible(false);
	ui->potWidget->graph()->rescaleAxes();
	//connect(ui->potWidget->graph(), SIGNAL(QCPGraph::selectionChanged), SLOT(MainWindow::facing));
	ui->potWidget->xAxis->setVisible(true);
	ui->potWidget->xAxis2->setVisible(true);
	//ui->potWidget->xAxis2->setTickLabels(false);
	ui->potWidget->yAxis->setVisible(true);
	ui->potWidget->yAxis2->setVisible(true);
	//ui->potWidget->yAxis2->setTickLabels(false);
	// make left and bottom axes always transfer their ranges to right and top axes:
	connect(ui->potWidget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->potWidget->xAxis2, SLOT(setRange(QCPRange)));
	connect(ui->potWidget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->potWidget->yAxis2, SLOT(setRange(QCPRange)));
	// set labels:
	ui->potWidget->xAxis->setLabel("Bottom axis label");
	ui->potWidget->yAxis->setLabel("Left axis label");
	ui->potWidget->xAxis2->setLabel("Top axis label");
	ui->potWidget->yAxis2->setLabel("Right axis label");
	ui->potWidget->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
	ui->potWidget->replot();
}

void MainWindow::replaceFunction(std::string& line)
{
	std::unordered_map<std::string, std::string> constants;
	constants.insert({ "(M)", ui->lineEditMU->text().toStdString() });
	constants.insert({ "m", ui->lineEditML->text().toStdString() });
	constants.insert({ "a", ui->lineEditA->text().toStdString() });
	constants.insert({ "b", ui->lineEditB->text().toStdString() });
	constants.insert({ "(DN)", ui->lineEditDN->text().toStdString() });

	replaceConstant(line, constants);
}

void MainWindow::generateKthTerms(CMathParser& parser)
{
	for (uint8_t index = 0; index <= 100; ++index)
	{
		xK.at(index) = generateKthTerm(parser, ui->lineEditXn->text(), index);
		yK.at(index) = generateKthTerm(parser, ui->lineEditYn->text(), index);
	}
}

void MainWindow::GenerateKPoints(set& k, const int& numberPoints)
{
	while (k.size() < numberPoints)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<> disDouble(0.0, 1.0);
		QCPGraphData result;
		k.insert({ disDouble(gen),disDouble(gen) });
	}
}

void MainWindow::facing()
{

	for (int index = 1; index <= ui->lineEditP->text().toInt(); ++index)
	{
		if (ui->potWidget->graph(index)->selected() == false)
			ui->potWidget->graph(index)->setVisible(false);
	}
}

void MainWindow::SelectButtonStep1()
{
    if (!CleanDir(Data::Defaults::PATH_STEP1))
	{
		error->setWindowTitle("Error");
		error->setText(QString::fromStdString(Data::Errors::ANOTHER_ERROR));
		error->show();
		return;
	}
	else 
	{
		ui->labelWait->setText("");
		ui->labelWaitMakePoint->setText("");
		ui->labelWaitPlotting->setText("");
		stopwatch time;
		time.tick();
		precision = pow(10, ui->spinBoxPrecision->value()) * 1.0;
		if (CheckData()) {
			stopwatch timeMakePoint;
			timeMakePoint.tick();

			int numberPoint = std::stoi(ui->lineEditInitialPoints->text().toStdString());
			int numberThread;
			if (std::thread::hardware_concurrency() > 0) numberThread = std::thread::hardware_concurrency();
			else numberThread = 4;
			CMathParser parser;

			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> disDouble(0.0, 1.0);
			QCPGraphData result;

			x0 = disDouble(gen);
			y0 = disDouble(gen);

			//Generez toti xn,yn
			generateKthTerms(parser);

			std::string fX(ui->lineEditFx->text().toStdString()), fY(ui->lineEditFy->text().toStdString());

			replaceFunction(fX);
			replaceFunction(fY);

			auto generate = [&](int start, int stop, std::string fileName) {
				std::ofstream out(fileName);
				for (int i = start; i < stop; ++i) // data for graphs 2, 3 and 4
				{
					QCPGraphData temp = generate2DPoints(parser, fX, fY, x0, y0);
					out << temp.key << " " << temp.value << "\n";
					x0 = temp.key;
					y0 = temp.value;
				}
				out.close();
			};



			auto spawnThreads = [&]()
			{
				std::vector<std::thread> threads;
				for (int i = 1; i < numberThread; i++) {
					threads.push_back(std::thread(generate, 0, numberPoint / numberThread, Data::Defaults::PATH_STEP1 + "file" + std::to_string(i) + ".txt"));
				}
				threads.push_back(std::thread(generate, 0, numberPoint - numberPoint / numberThread * (numberThread - 1), Data::Defaults::PATH_STEP1 + "file" + std::to_string(numberThread) + ".txt"));
				for (auto& th : threads) {
					th.join();
				}
			};


			spawnThreads();
			timeMakePoint.tock();
			std::string convertor = std::to_string(timeMakePoint.report_ms() / 1000.0);
			convertor = convertor.substr(0, convertor.size() - 3);

			ui->labelWaitMakePoint->setText(std::move(QString::fromStdString("Time for make points: " + convertor + " seconds")));

			stopwatch timePlottingPoints;
			timePlottingPoints.tick();

			plotting(numberThread);

			timePlottingPoints.tock();
			convertor = std::to_string(timePlottingPoints.report_ms() / 1000.0);
			convertor = convertor.substr(0, convertor.size() - 3);

			ui->labelWaitPlotting->setText(std::move(QString::fromStdString("Time for plotting points: " + convertor + " seconds")));
		}
		else
		{
			error->setWindowTitle("Error");
			error->setText(QString::fromStdString(Data::Errors::NO_FUNCTION));
			error->show();
			return;
		}

		time.tock();

		std::string convertor = std::to_string(time.report_ms() / 1000.0);
		convertor = convertor.substr(0, convertor.size() - 3);
		ui->labelWait->setText(std::move(QString::fromStdString("Total time: " + convertor + " seconds")));
	}
}

void MainWindow::SelectButtonStep2()
{
    if (!CleanDir(Data::Defaults::PATH_STEP2))
	{
		error->setWindowTitle("Error");
		error->setText(QString::fromStdString(Data::Errors::ANOTHER_ERROR));
		error->show();
		return;
	}
	else 
	{
		ui->labelWait->setText("");
		ui->labelWaitMakePoint->setText("");
		ui->labelWaitPlotting->setText("");
		precision = pow(10, ui->spinBoxPrecision->value()) * 1.0;
		stopwatch time;
		time.tick();

		if (CheckData())
		{
			stopwatch timeMakePoint;
			timeMakePoint.tick();
			int numberPointsK = std::stoi(ui->lineEditK->text().toStdString());
			set K;
			GenerateKPoints(K, numberPointsK);
			int p = std::stoi(ui->lineEditP->text().toStdString());
			int n = std::stoi(ui->lineEditN->text().toStdString());

			// for (const auto& entry : std::filesystem::directory_iterator("dir_path"))
			  //       std::filesystem::remove_all(entry.path());

			for (int index = 0; index <= p; ++index)
			{
				std::string nameDir = Data::Defaults::PATH_STEP2 + "K" + std::to_string(index);
				_mkdir(nameDir.c_str());
			}
			CMathParser parser;
			generateKthTerms(parser);
			std::string fX(ui->lineEditFx->text().toStdString()), fY(ui->lineEditFy->text().toStdString());

			replaceFunction(fX);
			replaceFunction(fY);

			auto generate = [&](std::string fileName, set K0, int index)
			{
				std::ofstream out(fileName);
				for (auto& point : K0)
				{
					QCPGraphData temp = generate2DPoints(parser, fX, fY, point.first, point.second, index);
					out << temp.key << " " << temp.value << "\n";
				}
			};

			int numberThread;
			if (std::thread::hardware_concurrency() > 0) numberThread = std::thread::hardware_concurrency();
			else numberThread = 4;

			auto spawnThreads = [&](std::string fileName, set K0)
			{
				int start = 0;
				for (int i = 1; i <= n - numberThread; i = i + numberThread)
				{
					std::vector<std::thread> threads;
					for (int index = 0; index < numberThread; ++index)
					{
						threads.push_back(std::thread(generate, fileName + "f" + std::to_string(i + index) + ".txt", std::ref(K0), i + index));
						++start;
					}
					for (auto& th : threads) {
						th.join();
					}

				}

				if (start == 0)
					start = 1;
				std::vector<std::thread> threadsSecond;

				for (int index = start; index <= n; ++index)
				{
					threadsSecond.push_back(std::thread(generate, fileName + "f" + std::to_string(index) + ".txt", std::ref(K0), index));
				}
				for (auto& th : threadsSecond) {
					th.join();
				}

			};


			auto read = [&K, &n](std::string fileName)
			{
				set newK;

				for (int index = 1; index <= n; ++index)
				{
					for (std::ifstream in(fileName + "f" + std::to_string(index) + ".txt"); !in.eof();)
					{
						std::string line;
						std::getline(in, line);
						if (std::regex_match(line, std::regex(R"([+-]?(\d*.\d*) [+-]?(\d*.\d*))")))
						{
							std::stringstream ss(line);
							std::string item;
							std::getline(ss, item, ' ');

							double x = std::stod(item);
							std::getline(ss, item, ' ');
							double y = std::stod(item);
							newK.insert({ x,y });
						}
					}
				}

				K = newK;
			};

			std::ofstream out(Data::Defaults::PATH_STEP2 + "K0\\f1.txt");
			for (auto& point : K)
			{
				out << point.first << " " << point.second << "\n";
			}
			out.close();

			for (int index = 1; index <= p; ++index)
			{
				spawnThreads(Data::Defaults::PATH_STEP2 + "K" + std::to_string(index) + "\\", K);
				if (index < p)
					read(Data::Defaults::PATH_STEP2 + "K" + std::to_string(index) + "\\");
			}
			timeMakePoint.tock();
			std::string convertor = std::to_string(timeMakePoint.report_ms() / 1000.0);
			convertor = convertor.substr(0, convertor.size() - 3);

			ui->labelWaitMakePoint->setText(std::move(QString::fromStdString("Time for make points: " + convertor + " seconds")));


			stopwatch timePlottingPoints;
			timePlottingPoints.tick();

			plottingStep2(std::stoi(ui->lineEditN->text().toStdString()), std::stoi(ui->lineEditP->text().toStdString()));

			timePlottingPoints.tock();
			convertor = std::to_string(timePlottingPoints.report_ms() / 1000.0);
			convertor = convertor.substr(0, convertor.size() - 3);

			ui->labelWaitPlotting->setText(std::move(QString::fromStdString("Time for plotting points: " + convertor + " seconds")));

		}
		else
		{
			error->setWindowTitle("Error");
			error->setText(QString::fromStdString("Insert function!"));
			error->show();
			return;
		}
		time.tock();

		std::string convertor = std::to_string(time.report_ms() / 1000.0);
		convertor = convertor.substr(0, convertor.size() - 3);
		ui->labelWait->setText(std::move(QString::fromStdString("Total time: " + convertor + " seconds")));
	}
}


void MainWindow::AddPointsButton()
{
	int numberPoint = ui->lineEditAddPoints->text().toInt();
	int numberThread;
	if (std::thread::hardware_concurrency() > 0) numberThread = std::thread::hardware_concurrency();
	else numberThread = 4;
	CMathParser parser;
	generateKthTerms(parser);

	std::string fX(ui->lineEditFx->text().toStdString()), fY(ui->lineEditFy->text().toStdString());

	replaceFunction(fX);
	replaceFunction(fY);

	auto generate = [&](int start, int stop, std::string fileName) {
		std::ofstream out(fileName, std::ios_base::app);
		for (int i = start; i < stop; ++i) // data for graphs 2, 3 and 4
		{
			QCPGraphData temp = generate2DPoints(parser, fX, fY, x0, y0);
			out << temp.key << " " << temp.value << "\n";
			x0 = temp.key;
			y0 = temp.value;
		}
		out.close();
	};
	std::vector<std::thread> threads;

	auto spawnThreads = [&]()
	{
		for (int i = 1; i < numberThread; i++) {
			threads.push_back(std::thread(generate, 0, numberPoint / numberThread, Data::Defaults::PATH_STEP1 + "file" + std::to_string(i) + ".txt"));
		}
		threads.push_back(std::thread(generate, 0, numberPoint - numberPoint / numberThread * (numberThread - 1), Data::Defaults::PATH_STEP1 + "file" + std::to_string(numberThread) + ".txt"));
		for (auto& th : threads) {
			th.join();
		}
	};

	spawnThreads();
	plotting(numberThread);
}

void MainWindow::ActionExit()
{
	exit(1);
}

void MainWindow::ActionHelp()
{
    QLabel* label = new QLabel(tr("Name:"));

        QHBoxLayout* layout = new QHBoxLayout();

        QString textLayout(QString::fromStdString(Data::Info::GENERAL_HELP));
        label->setText(textLayout);

        Qt::Alignment alignment;
        alignment.setFlag(Qt::AlignmentFlag::AlignCenter);
        layout->setAlignment(alignment);

        help->setMinimumWidth(800);
        help->setMinimumHeight(600);

        layout->addWidget(label);
        help->setLayout(layout);

        help->show();
}

void MainWindow::DefaultStep1()
{
	ReadQDomNode((Data::Defaults::PATH_DEFAULT + "default.xml").c_str(), "step1");
}

void MainWindow::DefaultStep2()
{
	ReadQDomNode((Data::Defaults::PATH_DEFAULT + "default.xml").c_str(), "step2");
}

void MainWindow::ReadQDomNode(const QString& fileName, const QString& elementTagName)
{
	QFile file(fileName);
	file.open(QFile::ReadOnly | QFile::Text);

	QDomDocument dom;
	QString error;

	int line, column;

	if (!dom.setContent(&file, &error, &line, &column)) {
		qDebug() << "Error:" << error << "in line " << line << "column" << column;
		return;
	}

	QDomNodeList nodes = dom.elementsByTagName(elementTagName);
	QDomNode node = nodes.at(0);


	if (node.lastChildElement("FnY").isElement())
	{
		ui->lineEditFy->setText(node.lastChildElement("FnY").text());
	}
	if (node.lastChildElement("FnX").isElement())
	{
		ui->lineEditFx->setText(node.lastChildElement("FnX").text());
	}
	if (node.lastChildElement("Xn").isElement())
	{
		ui->lineEditXn->setText(node.lastChildElement("Xn").text());
	}
	if (node.lastChildElement("Yn").isElement())
	{
		ui->lineEditYn->setText(node.lastChildElement("Yn").text());
	}
	if (node.lastChildElement("a").isElement())
	{
		ui->lineEditA->setText(node.lastChildElement("a").text());
	}
	if (node.lastChildElement("b").isElement())
	{
		ui->lineEditB->setText(node.lastChildElement("b").text());
	}
	if (node.lastChildElement("m").isElement())
	{
		ui->lineEditML->setText(node.lastChildElement("m").text());
	}
	if (node.lastChildElement("M").isElement())
	{
		ui->lineEditMU->setText(node.lastChildElement("M").text());
	}
	if (node.lastChildElement("dn").isElement())
	{
		ui->lineEditDN->setText(node.lastChildElement("dn").text());
	}
}

void MainWindow::Clean()
{
	ui->lineEditA->setText("");
	ui->lineEditB->setText("");
	ui->lineEditML->setText("");
	ui->lineEditMU->setText("");
	ui->lineEditDN->setText("");
	ui->lineEditXn->setText("");
	ui->lineEditYn->setText("");
	ui->lineEditFx->setText("");
	ui->lineEditFy->setText("");
	ui->lineEditReadXML->setText("");
	ui->labelWaitMakePoint->setText("");
	ui->labelWaitPlotting->setText("");
}

void MainWindow::ReadXML()
{
	QString aux = QFileDialog::getOpenFileName(this, tr("Open Directory"), "D:\\", "*.xml");

	ui->lineEditReadXML->setText(aux);

	ReadQDomNode(aux, "function");
}

bool MainWindow::CheckData()
{
	if (ui->lineEditFx->text().size() == 0)
		return false;
	if (ui->lineEditFy->text().size() == 0)
		return false;
	if (ui->lineEditXn->text().size() == 0)
		return false;
	if (ui->lineEditYn->text().size() == 0)
		return false;

	return true;
}

bool MainWindow::CleanDir(const std::string& path)
{
	bool check = false;
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		check = true;
		std::filesystem::remove_all(entry.path());
	}
    return check;
}

MainWindow::~MainWindow()
{
	//EMPTY
}
