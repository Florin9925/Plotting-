/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionExit;
    QAction *actionHelp;
    QWidget *centralWidget;
    QPushButton *pushButtonStep1;
    QPushButton *pushButtonStep2;
    QLineEdit *lineEditN;
    QLabel *labelN;
    QLabel *labelXn;
    QLineEdit *lineEditXn;
    QLabel *labelYn;
    QLineEdit *lineEditYn;
    QLabel *labelFn;
    QLineEdit *lineEditFx;
    QLineEdit *lineEditFy;
    QLabel *label_5;
    QLineEdit *lineEditYnPrint;
    QLineEdit *lineEditY0;
    QLineEdit *lineEditK;
    QLineEdit *lineEditX0;
    QLineEdit *lineEditXnPrint;
    QLabel *labelDN_2;
    QLabel *labelA_2;
    QLabel *labelMU_2;
    QLabel *labelML_2;
    QLabel *labelB_2;
    QLabel *labelA_3;
    QCustomPlot *potWidget;
    QLineEdit *lineEditA;
    QLineEdit *lineEditMU;
    QLineEdit *lineEditML;
    QLabel *labelB;
    QLabel *labelMU;
    QLineEdit *lineEditB;
    QLabel *labelDN;
    QLabel *labelA;
    QLineEdit *lineEditDN;
    QLabel *labelML;
    QLineEdit *lineEditAddPoints;
    QPushButton *pushButtonAddPoints;
    QMenuBar *menuBar;
    QMenu *menuExit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->setWindowModality(Qt::NonModal);
        MainWindowClass->resize(1600, 900);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
        MainWindowClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        MainWindowClass->setFont(font);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHelp = new QAction(MainWindowClass);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButtonStep1 = new QPushButton(centralWidget);
        pushButtonStep1->setObjectName(QString::fromUtf8("pushButtonStep1"));
        pushButtonStep1->setGeometry(QRect(100, 340, 121, 41));
        QFont font1;
        font1.setPointSize(18);
        pushButtonStep1->setFont(font1);
        pushButtonStep1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonStep2 = new QPushButton(centralWidget);
        pushButtonStep2->setObjectName(QString::fromUtf8("pushButtonStep2"));
        pushButtonStep2->setGeometry(QRect(100, 520, 121, 41));
        pushButtonStep2->setFont(font1);
        pushButtonStep2->setCursor(QCursor(Qt::PointingHandCursor));
        lineEditN = new QLineEdit(centralWidget);
        lineEditN->setObjectName(QString::fromUtf8("lineEditN"));
        lineEditN->setGeometry(QRect(120, 20, 71, 31));
        labelN = new QLabel(centralWidget);
        labelN->setObjectName(QString::fromUtf8("labelN"));
        labelN->setGeometry(QRect(70, 20, 41, 31));
        labelN->setFont(font1);
        labelXn = new QLabel(centralWidget);
        labelXn->setObjectName(QString::fromUtf8("labelXn"));
        labelXn->setGeometry(QRect(60, 70, 51, 31));
        labelXn->setFont(font1);
        lineEditXn = new QLineEdit(centralWidget);
        lineEditXn->setObjectName(QString::fromUtf8("lineEditXn"));
        lineEditXn->setGeometry(QRect(120, 70, 321, 31));
        labelYn = new QLabel(centralWidget);
        labelYn->setObjectName(QString::fromUtf8("labelYn"));
        labelYn->setGeometry(QRect(60, 120, 51, 31));
        labelYn->setFont(font1);
        lineEditYn = new QLineEdit(centralWidget);
        lineEditYn->setObjectName(QString::fromUtf8("lineEditYn"));
        lineEditYn->setGeometry(QRect(120, 120, 321, 31));
        labelFn = new QLabel(centralWidget);
        labelFn->setObjectName(QString::fromUtf8("labelFn"));
        labelFn->setGeometry(QRect(10, 170, 101, 31));
        labelFn->setFont(font1);
        lineEditFx = new QLineEdit(centralWidget);
        lineEditFx->setObjectName(QString::fromUtf8("lineEditFx"));
        lineEditFx->setGeometry(QRect(120, 170, 441, 31));
        lineEditFy = new QLineEdit(centralWidget);
        lineEditFy->setObjectName(QString::fromUtf8("lineEditFy"));
        lineEditFy->setGeometry(QRect(580, 170, 441, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(570, 180, 16, 21));
        lineEditYnPrint = new QLineEdit(centralWidget);
        lineEditYnPrint->setObjectName(QString::fromUtf8("lineEditYnPrint"));
        lineEditYnPrint->setGeometry(QRect(1120, 270, 181, 31));
        lineEditY0 = new QLineEdit(centralWidget);
        lineEditY0->setObjectName(QString::fromUtf8("lineEditY0"));
        lineEditY0->setGeometry(QRect(1120, 120, 181, 31));
        lineEditK = new QLineEdit(centralWidget);
        lineEditK->setObjectName(QString::fromUtf8("lineEditK"));
        lineEditK->setGeometry(QRect(1120, 170, 181, 31));
        lineEditX0 = new QLineEdit(centralWidget);
        lineEditX0->setObjectName(QString::fromUtf8("lineEditX0"));
        lineEditX0->setGeometry(QRect(1120, 70, 181, 31));
        lineEditXnPrint = new QLineEdit(centralWidget);
        lineEditXnPrint->setObjectName(QString::fromUtf8("lineEditXnPrint"));
        lineEditXnPrint->setGeometry(QRect(1120, 220, 181, 31));
        labelDN_2 = new QLabel(centralWidget);
        labelDN_2->setObjectName(QString::fromUtf8("labelDN_2"));
        labelDN_2->setGeometry(QRect(1040, 270, 61, 31));
        labelDN_2->setFont(font1);
        labelA_2 = new QLabel(centralWidget);
        labelA_2->setObjectName(QString::fromUtf8("labelA_2"));
        labelA_2->setGeometry(QRect(1040, 70, 61, 31));
        labelA_2->setFont(font1);
        labelMU_2 = new QLabel(centralWidget);
        labelMU_2->setObjectName(QString::fromUtf8("labelMU_2"));
        labelMU_2->setGeometry(QRect(1040, 220, 61, 31));
        labelMU_2->setFont(font1);
        labelML_2 = new QLabel(centralWidget);
        labelML_2->setObjectName(QString::fromUtf8("labelML_2"));
        labelML_2->setGeometry(QRect(1060, 170, 51, 31));
        labelML_2->setFont(font1);
        labelB_2 = new QLabel(centralWidget);
        labelB_2->setObjectName(QString::fromUtf8("labelB_2"));
        labelB_2->setGeometry(QRect(1040, 120, 61, 31));
        labelB_2->setFont(font1);
        labelA_3 = new QLabel(centralWidget);
        labelA_3->setObjectName(QString::fromUtf8("labelA_3"));
        labelA_3->setGeometry(QRect(1080, 10, 201, 31));
        labelA_3->setFont(font);
        potWidget = new QCustomPlot(centralWidget);
        potWidget->setObjectName(QString::fromUtf8("potWidget"));
        potWidget->setGeometry(QRect(330, 320, 1191, 511));
        lineEditA = new QLineEdit(centralWidget);
        lineEditA->setObjectName(QString::fromUtf8("lineEditA"));
        lineEditA->setGeometry(QRect(1410, 70, 181, 31));
        lineEditMU = new QLineEdit(centralWidget);
        lineEditMU->setObjectName(QString::fromUtf8("lineEditMU"));
        lineEditMU->setGeometry(QRect(1410, 220, 181, 31));
        lineEditML = new QLineEdit(centralWidget);
        lineEditML->setObjectName(QString::fromUtf8("lineEditML"));
        lineEditML->setGeometry(QRect(1410, 170, 181, 31));
        labelB = new QLabel(centralWidget);
        labelB->setObjectName(QString::fromUtf8("labelB"));
        labelB->setGeometry(QRect(1350, 120, 41, 31));
        labelB->setFont(font1);
        labelMU = new QLabel(centralWidget);
        labelMU->setObjectName(QString::fromUtf8("labelMU"));
        labelMU->setGeometry(QRect(1340, 220, 51, 31));
        labelMU->setFont(font1);
        lineEditB = new QLineEdit(centralWidget);
        lineEditB->setObjectName(QString::fromUtf8("lineEditB"));
        lineEditB->setGeometry(QRect(1410, 120, 181, 31));
        labelDN = new QLabel(centralWidget);
        labelDN->setObjectName(QString::fromUtf8("labelDN"));
        labelDN->setGeometry(QRect(1330, 270, 61, 31));
        labelDN->setFont(font1);
        labelA = new QLabel(centralWidget);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setGeometry(QRect(1350, 70, 41, 31));
        labelA->setFont(font1);
        lineEditDN = new QLineEdit(centralWidget);
        lineEditDN->setObjectName(QString::fromUtf8("lineEditDN"));
        lineEditDN->setGeometry(QRect(1410, 270, 181, 31));
        labelML = new QLabel(centralWidget);
        labelML->setObjectName(QString::fromUtf8("labelML"));
        labelML->setGeometry(QRect(1340, 170, 51, 31));
        labelML->setFont(font1);
        lineEditAddPoints = new QLineEdit(centralWidget);
        lineEditAddPoints->setObjectName(QString::fromUtf8("lineEditAddPoints"));
        lineEditAddPoints->setGeometry(QRect(170, 420, 101, 41));
        pushButtonAddPoints = new QPushButton(centralWidget);
        pushButtonAddPoints->setObjectName(QString::fromUtf8("pushButtonAddPoints"));
        pushButtonAddPoints->setGeometry(QRect(40, 420, 121, 41));
        pushButtonAddPoints->setFont(font1);
        pushButtonAddPoints->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 27));
        menuExit = new QMenu(menuBar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuExit->menuAction());
        menuExit->addAction(actionHelp);
        menuExit->addAction(actionExit);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", nullptr));
        actionHelp->setText(QApplication::translate("MainWindowClass", "Help", nullptr));
        pushButtonStep1->setText(QApplication::translate("MainWindowClass", "Step1", nullptr));
        pushButtonStep2->setText(QApplication::translate("MainWindowClass", "Step2", nullptr));
        lineEditN->setText(QApplication::translate("MainWindowClass", "1", nullptr));
        labelN->setText(QApplication::translate("MainWindowClass", "n =", nullptr));
        labelXn->setText(QApplication::translate("MainWindowClass", "Xn =", nullptr));
        lineEditXn->setText(QApplication::translate("MainWindowClass", "SQRT(n)/(1+SQRT(n))", nullptr));
        labelYn->setText(QApplication::translate("MainWindowClass", "Yn =", nullptr));
        lineEditYn->setText(QApplication::translate("MainWindowClass", "SIN(n)/SQRT(1+n)", nullptr));
        labelFn->setText(QApplication::translate("MainWindowClass", "Fn(x,y) =", nullptr));
        lineEditFx->setText(QApplication::translate("MainWindowClass", "(((XN)-(XN-1))*X+b*(XN-1)-a*(XN))/(b-a)", nullptr));
        lineEditFy->setText(QApplication::translate("MainWindowClass", "((YN)-(YN-1)-(DN)*((M)-m))*X/(b-a)+(DN)*Y+(b*(YN-1)-a*(YN)-(DN)*(b*m-a*(M)))/(b-a)", nullptr));
        label_5->setText(QApplication::translate("MainWindowClass", ",", nullptr));
        lineEditYnPrint->setText(QString());
        lineEditY0->setText(QString());
        lineEditK->setText(QString());
        lineEditX0->setText(QString());
        lineEditXnPrint->setText(QString());
        labelDN_2->setText(QApplication::translate("MainWindowClass", "Yn =", nullptr));
        labelA_2->setText(QApplication::translate("MainWindowClass", "x0 =", nullptr));
        labelMU_2->setText(QApplication::translate("MainWindowClass", "Xn =", nullptr));
        labelML_2->setText(QApplication::translate("MainWindowClass", "k =", nullptr));
        labelB_2->setText(QApplication::translate("MainWindowClass", "y0 =", nullptr));
        labelA_3->setText(QApplication::translate("MainWindowClass", "Temp outputs(testing)", nullptr));
        lineEditA->setText(QApplication::translate("MainWindowClass", "0", nullptr));
        lineEditMU->setText(QApplication::translate("MainWindowClass", "0", nullptr));
        lineEditML->setText(QApplication::translate("MainWindowClass", "0", nullptr));
        labelB->setText(QApplication::translate("MainWindowClass", "b =", nullptr));
        labelMU->setText(QApplication::translate("MainWindowClass", "M =", nullptr));
        lineEditB->setText(QApplication::translate("MainWindowClass", "1", nullptr));
        labelDN->setText(QApplication::translate("MainWindowClass", "dn =", nullptr));
        labelA->setText(QApplication::translate("MainWindowClass", "a =", nullptr));
        lineEditDN->setText(QApplication::translate("MainWindowClass", "0.4", nullptr));
        labelML->setText(QApplication::translate("MainWindowClass", "m =", nullptr));
        lineEditAddPoints->setText(QString());
        pushButtonAddPoints->setText(QApplication::translate("MainWindowClass", "Add points", nullptr));
        menuExit->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
