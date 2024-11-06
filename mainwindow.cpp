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

    connecting();
    decodingDisplay();
    memoryDisplay();
    registerDisplay();

    ui->pCounter->setText(QString::number(cpu::m_programCounter));
    ui->decodeButton->setEnabled(false);
    ui->excuteButton->setEnabled(false);
    ui->screen->setReadOnly(true);
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


/**
 * @brief Connects the UI buttons to their respective slots.
 *
 * This function connects the following UI buttons to their respective slots:
 * - openInstructionButton: onOpenInstructionFileClicked
 * - executeButton: on_execute_button_clicked
 * - decodeButton: onDecodeButtonClicked
 * - fetchButton: onFetchButtonClicked
 * - clearMemoryButton: on_clearMemoryButton_clicked
 * - clearRegButton: on_clearRegButton_clicked
 *
 * The connections are made using the Qt's connect function, which allows the UI to react to user actions.
 */
void MainWindow::connecting(){
    connect(ui->openInstructionButton, &QPushButton::clicked, this,
            &MainWindow::onOpenInstructionFileClicked);
    connect(ui->excuteButton, &QPushButton::clicked, this,
            &MainWindow::on_execute_button_clicked);
    connect(ui->decodeButton, &QPushButton::clicked, this,
            &MainWindow::onDecodeButtonClicked);
    connect(ui->fetchButton, &QPushButton::clicked, this,
            &MainWindow::onFetchButtonClicked);
    connect(ui->clearMemoryButton, &QPushButton::clicked, this,
            &MainWindow::on_clearMemoryButton_clicked);
    connect(ui->clearRegButton, &QPushButton::clicked, this,
            &MainWindow::on_clearRegButton_clicked);
}


/**
 * @brief Function to set the display properties for the decoded instruction components.
 *
 * This function configures the read-only mode for the UI elements that display the decoded
 * instruction components. It ensures that the user cannot modify these fields directly.
 *
 * @return void
 */
void MainWindow::decodingDisplay(){
    ui->encodedInsMessage->setReadOnly(true);
    ui->opCodeDisplay->setReadOnly(true);
    ui->rDisplay->setReadOnly(true);
    ui->xDisplay->setReadOnly(true);
    ui->yDisplay->setReadOnly(true);
}


/**
 * @brief Function to set the display properties for the memory section.
 *
 * This function configures the memory display table in the UI. It sets the number of rows and columns,
 * the header labels, and various display properties such as edit triggers, column resizing, and
 * visibility of the vertical header.
 *
 * @return void
 */
void MainWindow::memoryDisplay() {
    ui->memoryDisplay->setRowCount(256);
    ui->memoryDisplay->setColumnCount(5);
    QStringList headers = {"Address", "Binary", "Hex", "Int", "Float"};
    ui->memoryDisplay->setHorizontalHeaderLabels(headers);

    // Setting memory display properties
    ui->memoryDisplay->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->memoryDisplay->verticalHeader()->setVisible(false);
    ui->memoryDisplay->setSelectionMode(QAbstractItemView::NoSelection);

    // Resize columns based on content
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->memoryDisplay->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);

    for (int i = 0; i < 256; ++i) {
        // Address column (display as hex)
        QString address = QString::number(i, 16).toUpper().rightJustified(2, '0');
        ui->memoryDisplay->setItem(i, 0, new QTableWidgetItem(address));

        // Binary column (initialize with 8-bit binary representation)
        QString binaryValue = QString("%1").arg(m_cpu->m_memory->getCell(i).toInt(nullptr, 16),
                                                8, 2, QChar('0'));
        ui->memoryDisplay->setItem(i, 1, new QTableWidgetItem(binaryValue));

        // Hex column (display the instruction in hex)
        QString hexValue = m_cpu->m_memory->getCell(i).toUpper();
        ui->memoryDisplay->setItem(i, 2, new QTableWidgetItem(hexValue));

        // Integer representation of the instruction
        QString intValue = QString::number(m_cpu->m_memory->getCell(i).toInt(nullptr, 16));
        ui->memoryDisplay->setItem(i, 3, new QTableWidgetItem(intValue));

        ui->memoryDisplay->setItem(i, 4, new QTableWidgetItem(intValue));
    }
}


/**
 * @brief Updates the memory display table in the UI.
 *
 * This function iterates through each memory cell and updates the corresponding
 * table items in the UI. It checks if the cell value has changed before updating
 * the display to optimize performance.
 *
 * @return void
 */
void MainWindow::updateMemoryDisplay() {
    for (int i = 0; i < 256; ++i) {
        QString hexValue = m_cpu->m_memory->getCell(i).toUpper();
        if (hexValue != ui->memoryDisplay->item(i, 2)->text()) { // Update only if different
            QString binaryValue = QString("%1").arg(hexValue.toInt(nullptr, 16), 8, 2, QChar('0'));
            QString intValue = QString::number(ALU::hexToDec(hexValue));
            float floatValue = ALU::hexToFloat(hexValue);

            ui->memoryDisplay->item(i, 1)->setText(binaryValue);
            ui->memoryDisplay->item(i, 2)->setText(hexValue);
            ui->memoryDisplay->item(i, 3)->setText(intValue);
            ui->memoryDisplay->item(i, 4)->setText(QString::number(floatValue));
        }
    }
}


/**
 * @brief Function to set the display properties for the register section.
 *
 * This function configures the register display table in the UI. It sets the number of rows and columns,
 * the header labels, and various display properties such as edit triggers, column resizing, and
 * visibility of the vertical header.
 *
 * @return void
 */
void MainWindow::registerDisplay() {
    ui->registerDisplay->setRowCount(16);
    ui->registerDisplay->setColumnCount(5);
    QStringList r_headers = {"Address", "Binary", "Hex", "Int", "Float"};
    ui->registerDisplay->setHorizontalHeaderLabels(r_headers);

    // Setting memory display properties
    ui->registerDisplay->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->registerDisplay->verticalHeader()->setVisible(false);
    ui->registerDisplay->setSelectionMode(QAbstractItemView::NoSelection);

    // Resize columns based on content
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    ui->registerDisplay->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);

    for (int i = 0; i < 16; ++i) {
        // Address column (display as hex)
        QString address = QString::number(i, 16).toUpper().rightJustified(2, '0');
        ui->registerDisplay->setItem(i, 0, new QTableWidgetItem(address));

        // Binary column (initialize with 8-bit binary representation)
        QString binaryValue = QString("%1").arg(m_cpu->m_register->getCell(i).toInt(nullptr, 16),
                                                8, 2, QChar('0'));
        ui->registerDisplay->setItem(i, 1, new QTableWidgetItem(binaryValue));

        // Hex column (display the instruction in hex)
        QString hexValue = m_cpu->m_register->getCell(i).toUpper();
        ui->registerDisplay->setItem(i, 2, new QTableWidgetItem(hexValue));

        // Integer representation of the instruction
        QString intValue = QString::number(m_cpu->m_memory->getCell(i).toInt(nullptr, 16));
        ui->registerDisplay->setItem(i, 3, new QTableWidgetItem(intValue));

        ui->registerDisplay->setItem(i, 4, new QTableWidgetItem(intValue));
    }
}


/**
 * @brief Updates the register display table in the UI.
 *
 * This function iterates through each register cell and updates the corresponding
 * table items in the UI. It checks if the cell value has changed before updating
 * the display to optimize performance.
 *
 * @return void
 */
void MainWindow::updateRegisterDisplay() {

    for (int i = 0; i < 16; ++i) {
        QString hexValue = m_cpu->m_register->getCell(i).toUpper();

        // Only update if the hex value has changed
        if (hexValue != ui->registerDisplay->item(i, 2)->text()) {

            QString binaryValue = QString("%1").arg(hexValue.toInt(nullptr, 16),
                                                        8, 2, QChar('0'));
            QString intValue = QString::number(ALU::hexToDec(hexValue));
            float floatValue = ALU::hexToFloat(hexValue);

            // Update the corresponding table items
            ui->registerDisplay->item(i, 1)->setText(binaryValue);
            ui->registerDisplay->item(i, 2)->setText(hexValue);
            ui->registerDisplay->item(i, 3)->setText(intValue);
            ui->registerDisplay->item(i, 4)->setText(QString::number(floatValue));
        }
    }
}


/**
 * @brief Opens and processes an instruction file.
 *
 * This function opens a file dialog to select an instruction file.
 * It then reads the instructions from the file, converts them into hexadecimal format,
 * and stores them in the CPU's memory starting from the program counter.
 *
 * @return void
 *
 * @note The function assumes that each instruction is a 4-digit hexadecimal number.
 *       It reads the instructions from the file in pairs, with each pair representing
 *       an instruction. The instructions are stored in the memory starting from the
 *       program counter.
 */
void MainWindow::onOpenInstructionFileClicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open instruction File"),
                                                    "", tr("Text Files (*.txt)"));

    if (!fileName.isEmpty()) {
        QFile instructionsFile(fileName);
        if (instructionsFile.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&instructionsFile);
            QString instruction;
            while (!in.atEnd()) {
                in >> instruction;
                QString cell;
                for (int i = 0; i < 2; i++) {
                    cell += instruction[i];
                }
                m_cpu->m_memory->setCell(cpu::m_programCounter++, cell);
                cell = "";
                for (int i = 2; i < 4; i++) {
                    cell += instruction[i];
                }
                m_cpu->m_memory->setCell(cpu::m_programCounter++, cell);
            }
            cpu::m_programCounter = 0;
            instructionsFile.close();
            updateMemoryDisplay();
            QMessageBox::information(this, "File Opened", "Instructions file opened successfully");
        } else {
            QMessageBox::warning(this, "Error", "Could not open the instructionsFile for reading.");
        }
    }
    else {
        QMessageBox::warning(this, "Error", "Could not open the instructionFile");
    }
}


/**
 * @brief Fetches the instruction from memory and updates the instruction register.
 *
 * This function is responsible for fetching the instruction from memory at the current program counter.
 * It then updates the instruction register with the fetched instruction. The function also updates the
 * memory display and the program counter display in the UI. Additionally, it enables or disables the decode
 * button based on the length of the fetched instruction.
 *
 * @return void
 */
void MainWindow::onFetchButtonClicked()
{
    m_cpu->fetch();
    updateMemoryDisplay();
    ui->instructionDecode->setText(m_cpu->m_instructionRegister);
    ui->pCounter->setText(QString::number(cpu::m_programCounter));
    if (m_cpu->m_instructionRegister.length() != 4) {
        ui->decodeButton->setEnabled(false);
    }
    else {
        ui->decodeButton->setEnabled(true);
    }
}


/**
 * @brief Decodes the instruction fetched from memory and updates the UI.
 *
 * This function decodes the instruction fetched from memory using the CPU's decode method.
 * It then updates the UI components related to the decoded instruction, such as the opcode,
 * registers, and encoded instruction message. If the decoded instruction length is not equal
 * to 4, it updates the UI components with the decoded instruction components. Otherwise, it
 * clears the UI components and displays a failure message. Finally, it updates the program
 * counter and enables the execute button.
 *
 * @return void
 */
void MainWindow::onDecodeButtonClicked()
{
    auto decoded = m_cpu->decode();

    if (decoded.length() != 4) {
        ui->opCodeDisplay->setText(m_cpu->m_instructionRegister[0]);
        ui->rDisplay->setText(m_cpu->m_instructionRegister[1]);
        ui->xDisplay->setText(m_cpu->m_instructionRegister[2]);
        ui->yDisplay->setText(m_cpu->m_instructionRegister[3]);
        ui->encodedInsMessage->setText(decoded);
    }
    else {
        ui->opCodeDisplay->clear();
        ui->rDisplay->clear();
        ui->xDisplay->clear();
        ui->yDisplay->clear();
        ui->encodedInsMessage->setText("Failed to Decode");
    }
    ui->pCounter->setText(QString::number(cpu::m_programCounter));
    ui->excuteButton->setEnabled(true);
}


// A Flag to indicate if program counter has reached the end of the memory
bool memLimitReached = true;


/**
 * @brief Executes the instruction fetched from memory.
 *
 * This function executes the instruction fetched from memory using the CPU's execute method.
 * It updates the UI components related to memory, registers, and the program counter.
 * If the executed instruction writes to the screen, it updates the screen display in the UI.
 * If an exception occurs during execution, it displays a message indicating the termination of execution.
 * Finally, it disables the execute button.
 *
 * @return void
 *
 * @throws std::exception If an exception occurs during execution (Halt instruction).
 *
 */
void MainWindow::on_execute_button_clicked()
{
    try {
        m_cpu->execute();
        if (m_cpu->m_isScreen) {
            ui->screen->setText(m_cpu->m_memory->getCell(0));
        }
        m_cpu->m_isScreen = false;
        updateMemoryDisplay();
        updateRegisterDisplay();
        ui->pCounter->setText(QString::number(cpu::m_programCounter));
    } catch (...) {
        QMessageBox::information(this, "Halt", "Execution Terminated due to a halt");
        memLimitReached = false;
    }
    ui->excuteButton->setEnabled(false);
}


/**
 * @brief Resets the program counter to 0 and updates the UI.
 *
 * This function resets the program counter to 0 and updates the program counter display in the UI.
 *
 * @return void
 */
void MainWindow::on_resetCounter_clicked()
{
    cpu::m_programCounter = 0;
    ui->pCounter->setText(QString::number(cpu::m_programCounter));
}


/**
 * @brief Updates the program counter display in the UI.
 *
 * This function is called when the program counter's text changes. It converts the new text to an integer,
 * updates the program counter value, and then updates the program counter display in the UI.
 *
 * @param arg1 The new text for the program counter.
 *
 * @return void
 */
void MainWindow::on_pCounter_textChanged(const QString &arg1)
{
    bool ok;
    cpu::m_programCounter = arg1.toInt(&ok);
    ui->pCounter->setText(QString::number(cpu::m_programCounter));
}


/**
 * @brief Updates the instruction register and enables/disables the decode button.
 *
 * This function is called when the text in the instruction decode line edit changes.
 * It updates the instruction register with the new text and checks if the length of the
 * instruction register is equal to 4. If it is not, the decode button is disabled. Otherwise,
 * the decode button is enabled.
 *
 * @param arg1 The new text for the instruction decode line edit.
 *
 * @return void
 */
void MainWindow::on_instructionDecode_textChanged(const QString &arg1) const
{
    m_cpu->m_instructionRegister = arg1;
    if (m_cpu->m_instructionRegister.length() != 4) {
        ui->decodeButton->setEnabled(false);
    }
    else {
        ui->decodeButton->setEnabled(true);
    }
}


/**
 * @brief Executes a single cycle of the CPU.
 *
 * This function performs a single cycle of the CPU by fetching, decoding, and executing
 * an instruction. It checks if the program counter has reached the memory limit (256).
 * If it has, it displays a message indicating the termination of execution. Otherwise,
 * it fetches, decodes, and executes the instruction.
 *
 * @return void
 */
void MainWindow::on_runOneCycleButton_clicked()
{
    if (cpu::m_programCounter == 256) {
        QMessageBox::information(this, "Halt", "Execution terminated due to program counter exceeding the memory limit");
        memLimitReached = false;
        return;
    }

    MainWindow::onFetchButtonClicked();
    MainWindow::onDecodeButtonClicked();
    MainWindow::on_execute_button_clicked();
}


/**
 * @brief Clears the memory by setting all cells to "00".
 *
 * This function iterates through each cell in the memory and sets its value to "00".
 * After clearing the memory, it updates the memory display in the UI.
 *
 * @return void
 */
void MainWindow::on_clearMemoryButton_clicked()
{
    for (int i = 0; i < 256; i++) {
        m_cpu->m_memory->setCell(i, "00");
    }
    updateMemoryDisplay();
}


/**
 * @brief Clears the CPU's register by setting all cells to "00".
 *
 * This function iterates through each cell in the CPU's register and sets its value to "00".
 * After clearing the register, it updates the register display in the UI.
 *
 * @return void
 */
void MainWindow::on_clearRegButton_clicked()
{
    for (int i = 0; i < 16; i++) {
        m_cpu->m_register->setCell(i, "00");
    }
    updateRegisterDisplay();
}



/**
 * @brief Executes the CPU until a halt instruction is encountered.
 *
 * This function continuously fetches, decodes, and executes instructions until
 * the program counter reaches the memory limit (254). If a halt instruction is
 * encountered (indicated by the `memLimitReached` flag being set to false), the
 * function returns. Otherwise, a message indicating that the memory end has been
 * reached is displayed.
 *
 * @return void
 */
void MainWindow::on_runUntilHaltButton_clicked()
{
    while (cpu::m_programCounter <= 254) {

        MainWindow::onFetchButtonClicked();
        MainWindow::onDecodeButtonClicked();
        MainWindow::on_execute_button_clicked();
        if (!memLimitReached) {
            memLimitReached = true;
            return;
        }
    }

    QMessageBox::information(this, "Memory End", "Memory end is reached");
}
