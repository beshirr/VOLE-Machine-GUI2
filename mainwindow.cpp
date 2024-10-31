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

    /**
     * @brief The decoding display section*/
    ui->encodedInsMessage->setReadOnly(true);
    ui->opCodeDisplay->setReadOnly(true);
    ui->rDisplay->setReadOnly(true);
    ui->xDisplay->setReadOnly(true);
    ui->yDisplay->setReadOnly(true);

    /**
     * @brief Program counter*/
    ui->pCounter->setText(QString::number(cpu::m_programCounter));


    // TODO: TRY TO MAKE THIS ONE FUNCTION FOR BOTH MEMORY AND REGISTER


    /**
     * @brief setting memory display section*/
    ui->memoryDisplay->setRowCount(256);
    ui->memoryDisplay->setColumnCount(4);
    QStringList headers = {"Address", "Binary", "Hex", "Int"};
    ui->memoryDisplay->setHorizontalHeaderLabels(headers);
    for (int i = 0; i < 256; ++i) {
        // Address column (display as hex)
        QString address = QString::number(i, 16).toUpper().rightJustified(2, '0');
        ui->memoryDisplay->setItem(i, 0, new QTableWidgetItem(address));

        // Binary column (initialize to zeros)
        QString binaryValue = "00000000";
        ui->memoryDisplay->setItem(i, 1, new QTableWidgetItem(binaryValue));

        // Hex column (initialize to zero)
        QString hexValue = "00";
        ui->memoryDisplay->setItem(i, 2, new QTableWidgetItem(hexValue));

        QString intValue = "0";
        ui->memoryDisplay->setItem(i, 3, new QTableWidgetItem(intValue));
    }
    // Setting memory display properties
    ui->memoryDisplay->setEditTriggers(QAbstractItemView::NoEditTriggers); // Make table read-only
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Stretch columns
    ui->memoryDisplay->verticalHeader()->setVisible(false); // Hide row numbers if unnecessary
    ui->memoryDisplay->setSelectionMode(QAbstractItemView::NoSelection); // Disable selection


    /**
     * @brief Setting Register display section*/
    ui->registerDisplay->setRowCount(16);
    ui->registerDisplay->setColumnCount(4);
    QStringList r_headers = {"Address", "Binary", "Hex", "Int"};
    ui->registerDisplay->setHorizontalHeaderLabels(r_headers);
    for (int i = 0; i < 256; ++i) {
        // Address column (display as hex)
        QString address = QString::number(i, 16).toUpper().rightJustified(2, '0');
        ui->registerDisplay->setItem(i, 0, new QTableWidgetItem(address));

        // Binary column (initialize to zeros)
        QString binaryValue = "00000000";
        ui->registerDisplay->setItem(i, 1, new QTableWidgetItem(binaryValue));

        // Hex column (initialize to zero)
        QString hexValue = "00";
        ui->registerDisplay->setItem(i, 2, new QTableWidgetItem(hexValue));

        QString intValue = "0";
        ui->registerDisplay->setItem(i, 3, new QTableWidgetItem(intValue));
    }
    // Setting memory display properties
    ui->registerDisplay->setEditTriggers(QAbstractItemView::NoEditTriggers); // Make table read-only
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // Stretch columns
    ui->registerDisplay->verticalHeader()->setVisible(false); // Hide row numbers if unnecessary
    ui->registerDisplay->setSelectionMode(QAbstractItemView::NoSelection); // Disable selection

    /**
     * @brief Connecting signals*/
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
        } else {
            QMessageBox::warning(this, "Error", "Could not open the instructionsFile for reading.");
        }
    }
}


void MainWindow::on_fetchButton_clicked()
{
    m_cpu->fetch();
    ui->instructionDecode->setText(m_cpu->m_instructionRegister);
}


void MainWindow::on_decodeButton_clicked()
{
    vector<QString> decoded = m_cpu->decode();
    ui->opCodeDisplay->setText(decoded[0]);
    ui->rDisplay->setText(decoded[1]);
    ui->xDisplay->setText(decoded[2]);
    ui->yDisplay->setText(decoded[3]);
    ui->encodedInsMessage->setText(decoded[4]);
}


void MainWindow::on_executeButton_clicked()
{
    // m_cpu->execute();
}

