#include "cpu.h"

int cpu::m_programCounter = 0;

cpu::cpu(){
    m_instructionRegister = "";
    m_memory = new Memory();
    m_register = new Register();
}


cpu::~cpu(){
    delete m_memory;
    delete m_register;
}


void cpu::fetch() {
    m_instructionRegister = "";
    for (int i = 0; i < 2; i++) {
        m_instructionRegister += m_memory->getCell(m_programCounter);
        m_programCounter++;
    }
}


QString cpu::decode() {
    QChar op = m_instructionRegister[0];
    QChar r = m_instructionRegister[1];
    QChar x = m_instructionRegister[2];
    QChar y = m_instructionRegister[3];

    QString message;
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


void cpu::execute() {
    QChar op = m_instructionRegister[0];
    QString r = m_instructionRegister[1];
    QChar x = m_instructionRegister[2];
    QChar y = m_instructionRegister[3];

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

