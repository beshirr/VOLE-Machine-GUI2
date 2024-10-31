/**
 * @file mainwindow.cpp
 * @brief Running the Machine and Linking between the UI and the application classes
*/

#include "mainwindow.h"

/**
 * @brief Constructor for MainWindow class. Initializes the UI and connects signals.
 *
 * @param parent Pointer to the parent widget.
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_cpu = new cpu;
    // connect signals
    connect(ui->openInstructionButton, &QPushButton::clicked, this, &MainWindow::on_openInstructionFile_clicked);
    connect(ui->excuteButton, &QPushButton::clicked, this, &MainWindow::on_executeButton_clicked);
    connect(ui->decodeButton, &QPushButton::clicked, this, &MainWindow::on_decodeButton_clicked);
}

/**
 * @brief Destructor for MainWindow class.
 *
 * This destructor is responsible for cleaning up the dynamically allocated memory for the UI.
 * It is called when the MainWindow object is destroyed.
 */
MainWindow::~MainWindow()
{
    delete ui;
    delete m_cpu;
}


void MainWindow::on_openInstructionFile_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open instruction File"), "", tr("Text Files (*.txt)"));

    if (!fileName.isEmpty()) {
        QFile instructionsFile(fileName);
        if (instructionsFile.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&instructionsFile);
            QString instruction;
            while (!in.atEnd()) {
                in >> instruction;
//                m_fileContent.push_back(instruction);
            }
            instructionsFile.close();
            ui->instructionDecode->setText(instruction);
        } else {
            QMessageBox::warning(this, "Error", "Could not open the instructionsFile for reading.");
        }
    }
}


void MainWindow::on_fetchButton_clicked()
{
    m_cpu->fetch();
}


void MainWindow::on_decodeButton_clicked()
{
    m_cpu->decode();
}


void MainWindow::on_executeButton_clicked()
{
    // m_cpu->execute();
}

