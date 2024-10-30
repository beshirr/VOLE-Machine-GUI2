/**
 * @brief This file is the implementation for the mainwindow.h wich manages the flow of the machine
*/


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openInstructionButton, &QPushButton::clicked, this, &MainWindow::on_openInstructionFile_clicked);
    connect(ui->excuteButton, &QPushButton::clicked, this, &MainWindow::on_excuteButton_clicked);
    connect(ui->decodeButton, &QPushButton::clicked, this, &MainWindow::on_decodeButton_clicked);
}


MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief What action to take when clicking add insturction button
 * @details Creating a vector of QStrings to store each instruction
*/
void MainWindow::on_openInstructionFile_clicked()
{
    // Getting the Instructions file name
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "All Files (*.*);;Text Files (*.txt);;Images (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QMessageBox::information(this, "File Selected", "Instructions Loaded Successfully");
        // Loading the Instructions file
        QFile instructionsFile(fileName);

        if (instructionsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Create a QTextStream to read from the file
            QTextStream in(&instructionsFile);
            // Reading the instructions with a delimiter of whitespaces and newlines
            while (!in.atEnd()) {
                QString instruction;
                in >> instruction;
                fileContent.push_back(instruction);
            }

            instructionsFile.close();
        }

        else {
            QMessageBox::warning(this, "Error", "Could not open the file for reading.");
        }
    }
}


void MainWindow::on_excuteButton_clicked()
{

}


void MainWindow::on_decodeButton_clicked()
{

}


void MainWindow::on_instructionDecode_textChanged(const QString &arg1)
{

}

