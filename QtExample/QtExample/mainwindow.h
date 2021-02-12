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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::unique_ptr<QWidget> parent = Q_NULLPTR);
    ~MainWindow();

private slots:
    void SelectButtonStep1();

private:
    //Convertor CONVERTOR = Convertor(-5, 5, -5, 5, ui->potWidget->width(), ui->potWidget->width());

    std::string replaceConstant(const std::string& input,const std::string& token,const std::string& token_value);
    double calculateExpression(CMathParser& mathParser,const std::string& line);
    double generateKthTerm(CMathParser& mathParser,const QString& line, uint8_t k);
    double generateFComp(CMathParser& mathParser,const QString& lineToEdit,const QString& seriesLine, uint8_t k, double x, double y);
    QCPGraphData generateFk(CMathParser& mathParser,uint8_t k, double x, double y);
    QCPGraphData generate2DPoints(CMathParser& mathParser);
    void plotting(CMathParser& mathParser, uint8_t n);
    bool CheckConstraintN();

private:
    const double DN = 0.4;
    std::unique_ptr<Ui::MainWindowClass> ui = std::make_unique<Ui::MainWindowClass>();

};
