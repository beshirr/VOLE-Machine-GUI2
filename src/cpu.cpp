/**
 * @file cpu.cpp
 * @brief The declaration of the cpu.h file
 * */

#include "../headers/cpu.h"


int cpu::m_programCounter = 0;


/**
 * @brief Constructor for the cpu class.
 *
 * Initializes the instruction register to an empty string, creates instances of Memory and Register classes,
 * and sets the program counter to 0.
 */
cpu::cpu(){
    m_instructionRegister = "";
    m_memory = new Memory();
    m_register = new Register();
    m_programCounter = 0;
}


/**
 * @brief Destructor for the cpu class.
 *
 * Deallocates the dynamically allocated memory for the Memory and Register objects.
 * This ensures that no memory leaks occur when the cpu object goes out of scope.
 */
cpu::~cpu(){
    delete m_memory;  ///< Deallocate memory for the Memory object.
    delete m_register;  ///< Deallocate memory for the Register object.
}


bool cpu::isValidInstructoin(const QString& instructoin) {
    static QRegularExpression hex("^[0-9a-fA-F]+$");
    for (int i = 0; i < 4; i++) {
        if (!hex.match(m_instructionRegister[i]).hasMatch()) {
            return false;
        }
    }
    return true;
}


/**
 * @brief Fetches the next instruction from memory.
 *
 * This function reads the next two cells from memory starting from the program counter,
 * converts their content to uppercase, and stores it in the instruction register.
 * The program counter is then incremented by 2.
 *
 * @return void
 */
void cpu::fetch() {
    m_instructionRegister = "";
    for (int i = 0; i < 2; i++) {
        m_instructionRegister += m_memory->getCell(m_programCounter).toUpper();
        m_programCounter++;
    }
}


/**
 * @brief Decodes the instruction stored in the instruction register and generates a human-readable message.
 *
 * This function takes the instruction stored in the instruction register and decodes it to generate a human-readable message.
 * The instruction is a 4-character string where the first character represents the operation code (op), and the remaining
 * three characters represent the registers (r, x, y).
 *
 * @return QString - A human-readable message describing the decoded instruction.
 */
QString cpu::decode() {
    QChar op = m_instructionRegister[0];
    QChar r = m_instructionRegister[1];
    QChar x = m_instructionRegister[2];
    QChar y = m_instructionRegister[3];

    QString message;

    if (!cpu::isValidInstructoin(m_instructionRegister)) {
        message = "Invalid instruction";
        return message;
    }

    if (op == '1') {
        message = QString("LOAD the register %1 with the bit pattern found in the memory cell "
                          "whose address is %2%3").arg(r).arg(x).arg(y);
    }
    else if (op == '2') {
        message = QString("LOAD the register %1 with the bit pattern %2%3.").arg(r).arg(x).arg(y);
    }
    else if (op == '3') {
        if (x == '0' && y == '0') {
            message = "STORE to location 00, which is a memory mapping for the screen. Writing to 00 is writing to screen.";
        }
        else {
            message = QString("STORE the bit pattern found in register %1 in the memory cell "
                              "whose address is %2%3.").arg(r).arg(x).arg(y);
        }
    }
    else if (op == '4') {
        message = QString("MOVE the bit pattern found in register %1 to register %2.").arg(x).arg(y);
    }
    else if (op == '5') {
        message = QString("ADD the bit patterns in registers %1 and %2 as though they were two’s complement representations "
                          "and leave the result in register %3.").arg(x).arg(y).arg(r);
    }
    else if (op == '6') {
        message = QString("ADD the bit patterns in registers %1 and %2 as though they represented values in "
                          "floating-point notation and leave the floating-point result in register %3.").arg(x).arg(y).arg(r);
    }

    else if (op.toUpper() == 'B') {
        message = QString("JUMP to the instruction located in the memory cell at address %1%2 if the bit pattern in register %3\n"
                          "is equal to the bit pattern in register number 0. Otherwise, continue with the normal sequence of\n"
                          "execution.").arg(x).arg(y).arg(r);
    }
    else if (op.toUpper() == 'C') {
        message = "Halt";
    }

    else if (op == '0') {
        message = QString("No Instruction to execute");
    }

    else {
        message = QString("Unknown instruction");
    }
    return message;
}


/**
 * @brief Executes the instruction stored in the instruction register.
 * This function decodes the instruction register and performs the corresponding operation.
 * The instruction is a 4-character string where the first character represents the operation code (op),
 * and the remaining three characters represent the registers (r, x, y).
 *
 * @param op - The operation code character.
 * @param r - The register character for the destination register.
 * @param x - The register character for the first source register.
 * @param y - The register character for the second source register.
 *
 * @return void
 */
void cpu::execute() {
    QChar op = m_instructionRegister[0];
    QString r = m_instructionRegister[1];
    QChar x = m_instructionRegister[2];
    QChar y = m_instructionRegister[3];

    if (!cpu::isValidInstructoin(m_instructionRegister))  {
        throw logic_error("Invalid Instruction");
    }

    if (op == '1') {
        QString memoryIndex = x; memoryIndex += y;
        cu::load(r, memoryIndex, *m_memory, *m_register);
    }

    else if (op == '2') {
        QString value = x; value += y;
        cu::load(r, value, *m_register);
    }

    else if (op == '3') {
        QString memoryIndex = x; memoryIndex += y;
        if (memoryIndex == "00") {
            m_isScreen = true;
        }

        cu::store(r, memoryIndex, *m_memory, *m_register);

    }

    else if (op == '4') {
        cu::move(x, y, *m_register);
    }

    else if (op == '5') {
        ALU::addInteger(x, y, r, *m_register);
    }

    else if (op == '6') {
        ALU::addFloat(x, y, r, *m_register);
    }

    else if (op == 'B') {
        QString memoryIndex = x; memoryIndex += y;
        cu::jump(r, memoryIndex, *m_register, *m_memory, m_programCounter);
    }

    else if (op.toUpper() == 'C') {
        cu::halt();
    }
}

