#include "cu.h"
#include "memory.h"
#include <QString>
#include "cpu.h"
#include <stdexcept>
#include "alu.h"

cu::cu() {}

void cu::load(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg){
    QString valueToLoad = mem.getCell(ALU::hexToDec(indexMem));
    reg.setCell(ALU::hexToDec(indexReg), valueToLoad);
}

void cu::load(const QString& indexReg, const QString& val, Register& reg){
    reg.setCell(ALU::hexToDec(indexReg), val);
}

void cu::store(int indexReg, const QString& indexMem, Memory& mem, Register& reg){
    QString valueToStore = reg.getCell(indexReg);

    if (indexMem == "00") {
    }
    mem.setCell(ALU::hexToDec(indexMem), valueToStore);
}

void cu::move(const QString& indexReg1, const QString& indexReg2, Register& reg){
    QString valueToMove = reg.getCell(ALU::hexToDec(indexReg1));
    reg.setCell(ALU::hexToDec(indexReg1), "00");
    reg.setCell(ALU::hexToDec(indexReg2), valueToMove);
}

void cu::jump(const QString& indexReg, int newProgramCounter, Register& reg)
{
    if (reg.getCell(ALU::hexToDec(indexReg)) == reg.getCell(0)) {
        cpu::m_programCounter = newProgramCounter;
    }

}


void cu::halt(){
    throw runtime_error("execution of halt instruction");
}
