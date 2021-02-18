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
    QPushButton *pushButtonDefaultStep1;
    QPushButton *pushButtonDefaultStep2;
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
        MainWindowClass->setStyleSheet(QString::fromUtf8(" background-color: #19232D;border: 0px solid #32414B;padding: 0px;color: #F0F0F0;selection - background - color: #1464A0;selection - color: #F0F0F0;"));
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
        font1.setFamily(QString::fromUtf8("Century Gothic"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButtonStep1->setFont(font1);
        pushButtonStep1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonStep1->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        pushButtonStep2 = new QPushButton(centralWidget);
        pushButtonStep2->setObjectName(QString::fromUtf8("pushButtonStep2"));
        pushButtonStep2->setGeometry(QRect(100, 520, 121, 41));
        pushButtonStep2->setFont(font1);
        pushButtonStep2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonStep2->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        lineEditN = new QLineEdit(centralWidget);
        lineEditN->setObjectName(QString::fromUtf8("lineEditN"));
        lineEditN->setGeometry(QRect(120, 20, 71, 31));
        lineEditN->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelN = new QLabel(centralWidget);
        labelN->setObjectName(QString::fromUtf8("labelN"));
        labelN->setGeometry(QRect(70, 20, 41, 31));
        QFont font2;
        font2.setPointSize(18);
        labelN->setFont(font2);
        labelXn = new QLabel(centralWidget);
        labelXn->setObjectName(QString::fromUtf8("labelXn"));
        labelXn->setGeometry(QRect(60, 70, 51, 31));
        labelXn->setFont(font2);
        lineEditXn = new QLineEdit(centralWidget);
        lineEditXn->setObjectName(QString::fromUtf8("lineEditXn"));
        lineEditXn->setGeometry(QRect(120, 70, 321, 31));
        lineEditXn->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelYn = new QLabel(centralWidget);
        labelYn->setObjectName(QString::fromUtf8("labelYn"));
        labelYn->setGeometry(QRect(60, 120, 51, 31));
        labelYn->setFont(font2);
        lineEditYn = new QLineEdit(centralWidget);
        lineEditYn->setObjectName(QString::fromUtf8("lineEditYn"));
        lineEditYn->setGeometry(QRect(120, 120, 321, 31));
        lineEditYn->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelFn = new QLabel(centralWidget);
        labelFn->setObjectName(QString::fromUtf8("labelFn"));
        labelFn->setGeometry(QRect(10, 170, 101, 31));
        labelFn->setFont(font2);
        lineEditFx = new QLineEdit(centralWidget);
        lineEditFx->setObjectName(QString::fromUtf8("lineEditFx"));
        lineEditFx->setGeometry(QRect(120, 170, 441, 31));
        lineEditFx->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditFy = new QLineEdit(centralWidget);
        lineEditFy->setObjectName(QString::fromUtf8("lineEditFy"));
        lineEditFy->setGeometry(QRect(590, 170, 441, 31));
        lineEditFy->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(570, 180, 16, 21));
        potWidget = new QCustomPlot(centralWidget);
        potWidget->setObjectName(QString::fromUtf8("potWidget"));
        potWidget->setGeometry(QRect(330, 320, 1191, 511));
        potWidget->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditA = new QLineEdit(centralWidget);
        lineEditA->setObjectName(QString::fromUtf8("lineEditA"));
        lineEditA->setGeometry(QRect(1240, 20, 181, 31));
        lineEditA->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditMU = new QLineEdit(centralWidget);
        lineEditMU->setObjectName(QString::fromUtf8("lineEditMU"));
        lineEditMU->setGeometry(QRect(1240, 170, 181, 31));
        lineEditMU->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditML = new QLineEdit(centralWidget);
        lineEditML->setObjectName(QString::fromUtf8("lineEditML"));
        lineEditML->setGeometry(QRect(1240, 120, 181, 31));
        lineEditML->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelB = new QLabel(centralWidget);
        labelB->setObjectName(QString::fromUtf8("labelB"));
        labelB->setGeometry(QRect(1180, 70, 41, 31));
        labelB->setFont(font2);
        labelMU = new QLabel(centralWidget);
        labelMU->setObjectName(QString::fromUtf8("labelMU"));
        labelMU->setGeometry(QRect(1170, 170, 51, 31));
        labelMU->setFont(font2);
        lineEditB = new QLineEdit(centralWidget);
        lineEditB->setObjectName(QString::fromUtf8("lineEditB"));
        lineEditB->setGeometry(QRect(1240, 70, 181, 31));
        lineEditB->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelDN = new QLabel(centralWidget);
        labelDN->setObjectName(QString::fromUtf8("labelDN"));
        labelDN->setGeometry(QRect(1160, 220, 61, 31));
        labelDN->setFont(font2);
        labelA = new QLabel(centralWidget);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setGeometry(QRect(1180, 20, 41, 31));
        labelA->setFont(font2);
        lineEditDN = new QLineEdit(centralWidget);
        lineEditDN->setObjectName(QString::fromUtf8("lineEditDN"));
        lineEditDN->setGeometry(QRect(1240, 220, 181, 31));
        lineEditDN->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelML = new QLabel(centralWidget);
        labelML->setObjectName(QString::fromUtf8("labelML"));
        labelML->setGeometry(QRect(1170, 120, 51, 31));
        labelML->setFont(font2);
        lineEditAddPoints = new QLineEdit(centralWidget);
        lineEditAddPoints->setObjectName(QString::fromUtf8("lineEditAddPoints"));
        lineEditAddPoints->setGeometry(QRect(170, 420, 101, 41));
        lineEditAddPoints->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        pushButtonAddPoints = new QPushButton(centralWidget);
        pushButtonAddPoints->setObjectName(QString::fromUtf8("pushButtonAddPoints"));
        pushButtonAddPoints->setGeometry(QRect(40, 420, 121, 41));
        pushButtonAddPoints->setFont(font1);
        pushButtonAddPoints->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAddPoints->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        pushButtonDefaultStep1 = new QPushButton(centralWidget);
        pushButtonDefaultStep1->setObjectName(QString::fromUtf8("pushButtonDefaultStep1"));
        pushButtonDefaultStep1->setGeometry(QRect(480, 0, 161, 31));
        pushButtonDefaultStep1->setFont(font1);
        pushButtonDefaultStep1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDefaultStep1->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        pushButtonDefaultStep2 = new QPushButton(centralWidget);
        pushButtonDefaultStep2->setObjectName(QString::fromUtf8("pushButtonDefaultStep2"));
        pushButtonDefaultStep2->setGeometry(QRect(690, 0, 161, 31));
        pushButtonDefaultStep2->setFont(font1);
        pushButtonDefaultStep2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDefaultStep2->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 20));
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
        pushButtonDefaultStep1->setText(QApplication::translate("MainWindowClass", "Default step1", nullptr));
        pushButtonDefaultStep2->setText(QApplication::translate("MainWindowClass", "Default step2", nullptr));
        menuExit->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
