/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openInstructionButton;
    QGroupBox *groupBox;
    QPushButton *excuteButton;
    QPushButton *fetchButton;
    QPushButton *decodeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1284, 790);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openInstructionButton = new QPushButton(centralwidget);
        openInstructionButton->setObjectName("openInstructionButton");
        openInstructionButton->setGeometry(QRect(80, 690, 131, 27));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 381, 601));
        excuteButton = new QPushButton(centralwidget);
        excuteButton->setObjectName("excuteButton");
        excuteButton->setGeometry(QRect(250, 690, 94, 27));
        fetchButton = new QPushButton(centralwidget);
        fetchButton->setObjectName("fetchButton");
        fetchButton->setGeometry(QRect(390, 690, 94, 27));
        decodeButton = new QPushButton(centralwidget);
        decodeButton->setObjectName("decodeButton");
        decodeButton->setGeometry(QRect(540, 690, 94, 27));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1284, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openInstructionButton->setText(QCoreApplication::translate("MainWindow", "Add Instructions", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "CPU", nullptr));
        excuteButton->setText(QCoreApplication::translate("MainWindow", "Excute", nullptr));
        fetchButton->setText(QCoreApplication::translate("MainWindow", "Fetch", nullptr));
        decodeButton->setText(QCoreApplication::translate("MainWindow", "Decode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
