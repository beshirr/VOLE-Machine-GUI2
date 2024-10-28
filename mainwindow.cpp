/**
 * @brief This file is the implementation for the mainwindow.h wich manages the flow of the program
*/


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include "cpu.h"


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


vector<QString> fileContent; // String to hold the content of the file


void MainWindow::on_openInstructionFile_clicked()
{
    // Storing the Instructions file name
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "All Files (*.*);;Text Files (*.txt);;Images (*.png *.jpg)");

    if (!fileName.isEmpty()) {
        QMessageBox::information(this, "File Selected", "Instructions Loaded Successfully");
        // Loading the Instructions file
        QFile instructionsFile(fileName);

        if (instructionsFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&instructionsFile); // Create a QTextStream to read from the file

            while (!in.atEnd()) {
                QString instruction;
                in >> instruction;
                fileContent.push_back(instruction);
            }

            instructionsFile.close(); // Close the file after reading
        }

        else {
            // If the file could not be opened, show an error message
            QMessageBox::warning(this, "Error", "Could not open the file for reading.");
        }
    }
}


void MainWindow::on_excuteButton_clicked()
{
    cpu::execute();
}


void MainWindow::on_decodeButton_clicked()
{

}

