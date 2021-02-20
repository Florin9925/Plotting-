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
#include <QtWidgets/QGroupBox>
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
    QPushButton *pushButtonDefaultStep1;
    QPushButton *pushButtonDefaultStep2;
    QLineEdit *lineEditReadXML;
    QPushButton *pushButtonReadXML;
    QPushButton *pushButtonClean;
    QGroupBox *groupBoxStep1;
    QLabel *labelInitialPoints;
    QPushButton *pushButtonStep1;
    QLineEdit *lineEditAddPoints;
    QLineEdit *lineEditInitialPoints;
    QPushButton *pushButtonAddPoints;
    QGroupBox *groupBoxStep2;
    QPushButton *pushButtonStep2;
    QLabel *labelK;
    QLineEdit *lineEditK;
    QLineEdit *lineEditN;
    QLabel *labelN;
    QLineEdit *lineEditP;
    QLabel *labelP;
    QPushButton *pushButtonMakeGraphStep2;
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
        labelXn = new QLabel(centralWidget);
        labelXn->setObjectName(QString::fromUtf8("labelXn"));
        labelXn->setGeometry(QRect(60, 20, 51, 31));
        QFont font1;
        font1.setPointSize(18);
        labelXn->setFont(font1);
        lineEditXn = new QLineEdit(centralWidget);
        lineEditXn->setObjectName(QString::fromUtf8("lineEditXn"));
        lineEditXn->setGeometry(QRect(120, 20, 321, 31));
        lineEditXn->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelYn = new QLabel(centralWidget);
        labelYn->setObjectName(QString::fromUtf8("labelYn"));
        labelYn->setGeometry(QRect(60, 70, 51, 31));
        labelYn->setFont(font1);
        lineEditYn = new QLineEdit(centralWidget);
        lineEditYn->setObjectName(QString::fromUtf8("lineEditYn"));
        lineEditYn->setGeometry(QRect(120, 70, 321, 31));
        lineEditYn->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelFn = new QLabel(centralWidget);
        labelFn->setObjectName(QString::fromUtf8("labelFn"));
        labelFn->setGeometry(QRect(10, 120, 101, 31));
        labelFn->setFont(font1);
        lineEditFx = new QLineEdit(centralWidget);
        lineEditFx->setObjectName(QString::fromUtf8("lineEditFx"));
        lineEditFx->setGeometry(QRect(120, 120, 441, 31));
        lineEditFx->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditFy = new QLineEdit(centralWidget);
        lineEditFy->setObjectName(QString::fromUtf8("lineEditFy"));
        lineEditFy->setGeometry(QRect(590, 120, 441, 31));
        lineEditFy->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(570, 130, 16, 21));
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
        labelB->setFont(font1);
        labelMU = new QLabel(centralWidget);
        labelMU->setObjectName(QString::fromUtf8("labelMU"));
        labelMU->setGeometry(QRect(1170, 170, 51, 31));
        labelMU->setFont(font1);
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
        labelDN->setFont(font1);
        labelA = new QLabel(centralWidget);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setGeometry(QRect(1180, 20, 41, 31));
        labelA->setFont(font1);
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
        labelML->setFont(font1);
        pushButtonDefaultStep1 = new QPushButton(centralWidget);
        pushButtonDefaultStep1->setObjectName(QString::fromUtf8("pushButtonDefaultStep1"));
        pushButtonDefaultStep1->setGeometry(QRect(530, 30, 161, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Century Gothic"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        pushButtonDefaultStep1->setFont(font2);
        pushButtonDefaultStep1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDefaultStep1->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        pushButtonDefaultStep2 = new QPushButton(centralWidget);
        pushButtonDefaultStep2->setObjectName(QString::fromUtf8("pushButtonDefaultStep2"));
        pushButtonDefaultStep2->setGeometry(QRect(780, 30, 161, 31));
        pushButtonDefaultStep2->setFont(font2);
        pushButtonDefaultStep2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonDefaultStep2->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        lineEditReadXML = new QLineEdit(centralWidget);
        lineEditReadXML->setObjectName(QString::fromUtf8("lineEditReadXML"));
        lineEditReadXML->setGeometry(QRect(210, 200, 661, 31));
        lineEditReadXML->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditReadXML->setReadOnly(true);
        pushButtonReadXML = new QPushButton(centralWidget);
        pushButtonReadXML->setObjectName(QString::fromUtf8("pushButtonReadXML"));
        pushButtonReadXML->setGeometry(QRect(20, 200, 161, 31));
        pushButtonReadXML->setFont(font2);
        pushButtonReadXML->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonReadXML->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        pushButtonClean = new QPushButton(centralWidget);
        pushButtonClean->setObjectName(QString::fromUtf8("pushButtonClean"));
        pushButtonClean->setGeometry(QRect(1470, 110, 101, 31));
        pushButtonClean->setFont(font2);
        pushButtonClean->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonClean->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        groupBoxStep1 = new QGroupBox(centralWidget);
        groupBoxStep1->setObjectName(QString::fromUtf8("groupBoxStep1"));
        groupBoxStep1->setGeometry(QRect(30, 290, 281, 271));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Century Gothic"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        groupBoxStep1->setFont(font3);
        groupBoxStep1->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	\n"
"	font: 9pt  \"Century Gothic\";\n"
"	border: 1px solid rgb(181, 204, 214);;\n"
"    border-radius: 12px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"top:-10px;\n"
"}"));
        groupBoxStep1->setAlignment(Qt::AlignCenter);
        labelInitialPoints = new QLabel(groupBoxStep1);
        labelInitialPoints->setObjectName(QString::fromUtf8("labelInitialPoints"));
        labelInitialPoints->setGeometry(QRect(30, 90, 111, 31));
        QFont font4;
        font4.setPointSize(14);
        labelInitialPoints->setFont(font4);
        pushButtonStep1 = new QPushButton(groupBoxStep1);
        pushButtonStep1->setObjectName(QString::fromUtf8("pushButtonStep1"));
        pushButtonStep1->setGeometry(QRect(80, 30, 121, 41));
        pushButtonStep1->setFont(font2);
        pushButtonStep1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonStep1->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        lineEditAddPoints = new QLineEdit(groupBoxStep1);
        lineEditAddPoints->setObjectName(QString::fromUtf8("lineEditAddPoints"));
        lineEditAddPoints->setGeometry(QRect(160, 170, 101, 41));
        lineEditAddPoints->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditInitialPoints = new QLineEdit(groupBoxStep1);
        lineEditInitialPoints->setObjectName(QString::fromUtf8("lineEditInitialPoints"));
        lineEditInitialPoints->setGeometry(QRect(160, 90, 101, 41));
        lineEditInitialPoints->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        pushButtonAddPoints = new QPushButton(groupBoxStep1);
        pushButtonAddPoints->setObjectName(QString::fromUtf8("pushButtonAddPoints"));
        pushButtonAddPoints->setGeometry(QRect(20, 170, 121, 41));
        pushButtonAddPoints->setFont(font2);
        pushButtonAddPoints->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonAddPoints->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        groupBoxStep2 = new QGroupBox(centralWidget);
        groupBoxStep2->setObjectName(QString::fromUtf8("groupBoxStep2"));
        groupBoxStep2->setGeometry(QRect(30, 580, 281, 271));
        groupBoxStep2->setFont(font3);
        groupBoxStep2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	\n"
"	font: 9pt  \"Century Gothic\";\n"
"	border: 1px solid rgb(181, 204, 214);;\n"
"    border-radius: 12px;\n"
"}\n"
"\n"
"QGroupBox{\n"
"top:-10px;\n"
"}"));
        groupBoxStep2->setAlignment(Qt::AlignCenter);
        pushButtonStep2 = new QPushButton(groupBoxStep2);
        pushButtonStep2->setObjectName(QString::fromUtf8("pushButtonStep2"));
        pushButtonStep2->setGeometry(QRect(80, 30, 121, 41));
        pushButtonStep2->setFont(font2);
        pushButtonStep2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonStep2->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
"font: 10pt  \"Century Gothic\";\n"
"color:#19232D;\n"
"background:#148dfa;"));
        labelK = new QLabel(groupBoxStep2);
        labelK->setObjectName(QString::fromUtf8("labelK"));
        labelK->setGeometry(QRect(60, 80, 41, 31));
        labelK->setFont(font1);
        lineEditK = new QLineEdit(groupBoxStep2);
        lineEditK->setObjectName(QString::fromUtf8("lineEditK"));
        lineEditK->setGeometry(QRect(120, 80, 91, 31));
        lineEditK->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        lineEditN = new QLineEdit(groupBoxStep2);
        lineEditN->setObjectName(QString::fromUtf8("lineEditN"));
        lineEditN->setGeometry(QRect(120, 120, 91, 31));
        lineEditN->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelN = new QLabel(groupBoxStep2);
        labelN->setObjectName(QString::fromUtf8("labelN"));
        labelN->setGeometry(QRect(60, 120, 41, 31));
        labelN->setFont(font1);
        lineEditP = new QLineEdit(groupBoxStep2);
        lineEditP->setObjectName(QString::fromUtf8("lineEditP"));
        lineEditP->setGeometry(QRect(120, 160, 91, 31));
        lineEditP->setStyleSheet(QString::fromUtf8("border-style: outset;\n"
"border-width: 1px;\n"
"border-radius: 10px;\n"
"border-color: rgb(181, 204, 214);"));
        labelP = new QLabel(groupBoxStep2);
        labelP->setObjectName(QString::fromUtf8("labelP"));
        labelP->setGeometry(QRect(60, 160, 41, 31));
        labelP->setFont(font1);
        pushButtonMakeGraphStep2 = new QPushButton(groupBoxStep2);
        pushButtonMakeGraphStep2->setObjectName(QString::fromUtf8("pushButtonMakeGraphStep2"));
        pushButtonMakeGraphStep2->setGeometry(QRect(80, 210, 121, 41));
        pushButtonMakeGraphStep2->setFont(font2);
        pushButtonMakeGraphStep2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButtonMakeGraphStep2->setStyleSheet(QString::fromUtf8("border-radius: 10px;;\n"
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
        labelXn->setText(QApplication::translate("MainWindowClass", "Xn =", nullptr));
        lineEditXn->setText(QString());
        labelYn->setText(QApplication::translate("MainWindowClass", "Yn =", nullptr));
        lineEditYn->setText(QString());
        labelFn->setText(QApplication::translate("MainWindowClass", "Fn(x,y) =", nullptr));
        lineEditFx->setText(QString());
        lineEditFy->setText(QString());
        label_5->setText(QApplication::translate("MainWindowClass", ",", nullptr));
        lineEditA->setText(QString());
        lineEditMU->setText(QString());
        lineEditML->setText(QString());
        labelB->setText(QApplication::translate("MainWindowClass", "b =", nullptr));
        labelMU->setText(QApplication::translate("MainWindowClass", "M =", nullptr));
        lineEditB->setText(QString());
        labelDN->setText(QApplication::translate("MainWindowClass", "dn =", nullptr));
        labelA->setText(QApplication::translate("MainWindowClass", "a =", nullptr));
        lineEditDN->setText(QString());
        labelML->setText(QApplication::translate("MainWindowClass", "m =", nullptr));
        pushButtonDefaultStep1->setText(QApplication::translate("MainWindowClass", "Default step1", nullptr));
        pushButtonDefaultStep2->setText(QApplication::translate("MainWindowClass", "Default step2", nullptr));
        pushButtonReadXML->setText(QApplication::translate("MainWindowClass", "Read XML", nullptr));
        pushButtonClean->setText(QApplication::translate("MainWindowClass", "Clean", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBoxStep1->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" font-size:12pt;\">Resolution for the resulting </span><span style=\" font-size:12pt; font-style:italic;\">Mosaic++</span><span style=\" font-size:12pt;\">.</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        groupBoxStep1->setTitle(QApplication::translate("MainWindowClass", "Step1", nullptr));
        labelInitialPoints->setText(QApplication::translate("MainWindowClass", "Initial points:", nullptr));
        pushButtonStep1->setText(QApplication::translate("MainWindowClass", "Make graph", nullptr));
        lineEditAddPoints->setText(QString());
        lineEditInitialPoints->setText(QApplication::translate("MainWindowClass", "100", nullptr));
        pushButtonAddPoints->setText(QApplication::translate("MainWindowClass", "Add points", nullptr));
#ifndef QT_NO_TOOLTIP
        groupBoxStep2->setToolTip(QApplication::translate("MainWindowClass", "<html><head/><body><p><span style=\" font-size:12pt;\">Resolution for the resulting </span><span style=\" font-size:12pt; font-style:italic;\">Mosaic++</span><span style=\" font-size:12pt;\">.</span></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        groupBoxStep2->setTitle(QApplication::translate("MainWindowClass", "Step2", nullptr));
        pushButtonStep2->setText(QApplication::translate("MainWindowClass", "Make points", nullptr));
        labelK->setText(QApplication::translate("MainWindowClass", "k =", nullptr));
        lineEditK->setText(QApplication::translate("MainWindowClass", "10", nullptr));
        lineEditN->setText(QApplication::translate("MainWindowClass", "5", nullptr));
        labelN->setText(QApplication::translate("MainWindowClass", "n =", nullptr));
        lineEditP->setText(QApplication::translate("MainWindowClass", "5", nullptr));
        labelP->setText(QApplication::translate("MainWindowClass", "p =", nullptr));
        pushButtonMakeGraphStep2->setText(QApplication::translate("MainWindowClass", "Make graph", nullptr));
        menuExit->setTitle(QApplication::translate("MainWindowClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
