#pragma once

#include <QtWidgets/QMainWindow>

#include "ui_mainwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::unique_ptr<QWidget> parent = Q_NULLPTR);
    ~MainWindow();

private:
    std::unique_ptr<Ui::MainWindowClass> ui = std::make_unique<Ui::MainWindowClass>();

};
