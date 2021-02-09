#include "mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(std::unique_ptr<QWidget> parent) :
	QMainWindow(parent.get()),
	ui(new Ui::MainWindowClass)
{
	ui->setupUi(this);
	
}

MainWindow::~MainWindow()
{
	//EMPTY
}