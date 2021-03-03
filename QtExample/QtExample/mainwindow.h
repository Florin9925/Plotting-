#pragma once

#include <QtWidgets/QMainWindow>
#include <QIntValidator>
#include <QVector2D>
#include<QtXml/QDomDocument>
#include <QFile>
#include "CMathParser.h"
#include "ui_mainwindow.h"
#include "stopwatch.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <array>
#include <fstream>
#include <thread>
#include <regex>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <direct.h>
#include <filesystem>
#include "data.h"

using set = std::unordered_set<std::pair<double, double>>;

template <>
struct std::hash<std::pair<double, double>>
{
    size_t operator()(const std::pair<double, double>& k) const
    {
        size_t res = 17;
        res = res * 31 + std::hash<double>()(k.first);
        res = res * 31 + std::hash<double>()(k.second);
        return res;
    }
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

private:
	double x0;
	double y0;
    double precision;

public:
	MainWindow(std::unique_ptr<QWidget> parent = Q_NULLPTR);
	~MainWindow();

private slots:
    void facing();
	void SelectButtonStep1();
	void SelectButtonStep2();
	void AddPointsButton();
	void DefaultStep1();
	void DefaultStep2();
	void Clean();
	void ReadXML();
	void ActionExit();
    void ActionHelp();

private:
	std::array<double, 101> xK;
	std::array<double, 101> yK;

	std::string replaceConstant(const std::string& input, const std::string& token, const std::string& token_value);
	void replaceConstant(std::string& input, const std::unordered_map<std::string, std::string>& tokens);
	void replaceFunction(std::string& line);
	void replaceSerie(std::string& line, uint8_t k, double x, double y);
	double calculateExpression(CMathParser& mathParser, const std::string& line);
	double generateKthTerm(CMathParser& mathParser, const QString& line, uint8_t k);
	void generateKthTerms(CMathParser& parser);
	double generateFComp(CMathParser& mathParser, std::string& lineToEdit, double xComp_k, double xComp_k1, double yComp_k, double yComp_k1, double x, double y, uint8_t k);
	QCPGraphData generateFk(CMathParser& mathParser, uint8_t k, double x, double y, std::string& fX, std::string& fY);
    QCPGraphData generate2DPoints(CMathParser& mathParser, std::string& fX, std::string& fY, const double& x, const double& y, int k = -1);
	void plotting(int numberFile);
    void plottingStep2(const int& n, const int& p);
	bool CheckConstraintN();
    void ReadQDomNode(const QString& fileName, const QString& elementTagName);
    void GenerateKPoints(set& k, const int& numberPoints);
    bool CleanDir(const std::string& path);
    bool CheckData();

private:
	const double DN = 0.4;
	std::unique_ptr<Ui::MainWindowClass> ui = std::make_unique<Ui::MainWindowClass>();
    std::unique_ptr<QMessageBox> error = std::make_unique<QMessageBox>();
    std::unique_ptr<QWidget> help = std::make_unique<QWidget>();
};
