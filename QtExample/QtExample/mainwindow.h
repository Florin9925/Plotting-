#pragma once

#include <QtWidgets/QMainWindow>
#include <QIntValidator>
#include <QVector2D>



#include "CMathParser.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <cstdlib>
#include <random>
#include <array>
#include <fstream>
#include <thread>
#include <regex>
#include <sstream>
#include <unordered_map>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::unique_ptr<QWidget> parent = Q_NULLPTR);
    ~MainWindow();

private slots:
    void SelectButtonStep1();
    void SelectButtonStep2();
    void AddPointsButton();
    void DefaultStep1();
    void DefaultStep2();
    void ActionExit();

private:
    std::array<double, 101> xK;
    std::array<double, 101> yK;

    std::string replaceConstant(const std::string& input,const std::string& token,const std::string& token_value);
    void replaceConstant(std::string& input,const std::unordered_map<std::string,std::string>& tokens);
    void replaceFunction(std::string& line);
    void replaceSerie(std::string& line, uint8_t k, double x, double y);
    double calculateExpression(CMathParser& mathParser,const std::string& line);
    double generateKthTerm(CMathParser& mathParser,const QString& line, uint8_t k);
    void generateKthTerms(CMathParser& parser);
    double generateFComp(CMathParser& mathParser,std::string& lineToEdit,double xComp_k, double xComp_k1,double yComp_k, double yComp_k1, double x, double y);
    QCPGraphData generateFk(CMathParser& mathParser, uint8_t k, double x, double y,std::string& fX,std::string& fY);
    QCPGraphData generate2DPoints(CMathParser& mathParser,std::string& fX,std::string& fY);
    void plotting();
    bool CheckConstraintN();

private:
    const double DN = 0.4;
    std::unique_ptr<Ui::MainWindowClass> ui = std::make_unique<Ui::MainWindowClass>();

};
