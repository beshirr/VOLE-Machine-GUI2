#include "cu.h"
#include "memory.h"
#include <QString>
#include "cpu.h"
#include <stdexcept>
#include "alu.h"

cu::cu() {}

void cu::load(QString indexReg, QString indexMem, Memory& mem, Register& reg){
    QString valueToLoad = mem.getCell(ALU::hexToDec(indexMem));
    reg.setCell(ALU::hexToDec(indexReg), valueToLoad);
}

void cu::load(QString indexReg, QString val, Register& reg){
    reg.setCell(ALU::hexToDec(indexReg), val);
}

void cu::store(QString indexReg, QString indexMem, Memory& mem, Register& reg){
    QString valueToStore = reg.getCell(ALU::hexToDec(indexReg));

    if (indexMem == "00") {
        cout << valueToStore << endl;
    }
    mem.setCell(ALU::hexToDec(indexMem), valueToStore);
}

void cu::move(QString indexReg1, QString indexReg2, Register& reg){
    QString valueToMove = reg.getCell(ALU::hexToDec(indexReg1));
    reg.setCell(ALU::hexToDec(indexReg1), "00");
    reg.setCell(ALU::hexToDec(indexReg2), valueToMove);
}

void cu::jump(QString indexReg, int NewProgramCounter, Register& reg)
{
    if (reg.getCell(ALU::hexToDec(indexReg)) == reg.getCell(0)) {
        cpu::m_programCounter = NewProgramCounter;
    }

}

void halt(){
    throw runtime_error("execution of halt instruction");
}

