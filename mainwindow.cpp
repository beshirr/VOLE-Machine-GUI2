#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

/**
 * @brief This file is the implementation for the mainwindow.h wich manages the flow of the program
*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the add instruction button to slot for openning file dialog
    connect(ui->openInstructionButton, &QPushButton::clicked, this, &MainWindow::on_openInstructionFile_clicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openInstructionFile_clicked()
{
    // Storing the Instructions file name
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "All Files (*.*);;Text Files (*.txt);;Images (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QMessageBox::information(this, "File Selected", "Instructions Loaded Successfully");
        // Loading the Instructions file
        QFile instructions(fileName);
    }
}


void MainWindow::on_excuteButton_clicked()
{

}

