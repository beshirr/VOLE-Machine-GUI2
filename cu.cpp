#include "cu.h"
#include "memory.h"
#include <QString>
#include "cpu.h"
#include <stdexcept>

cu::cu() {}

void cu::load(int indexReg, int indexMem, Memory& mem, Register& reg){
    QString valueToLoad = mem.getCell(indexMem);
    reg.setCell(indexReg, valueToLoad);
}

void cu::load(int indexReg, QString val, Register& reg){
    reg.setCell(indexReg, val);
}

void cu::store(int indexReg, int indexMem, Memory& mem, Register& reg){
    QString valueToLoad = reg.getCell(indexReg);

    if (to_string(indexMem) == "00") {
        cout << valueToLoad << endl;
    }
    mem.setCell(indexMem, valueToLoad);
}

void cu::move(int indexReg1, int indexReg2, Register& reg){
    QString valueToMove = reg.getCell(indexReg1);
    reg.setCell(indexReg1, "00");
    reg.setCell(indexReg2, valueToMove);
}

void cu::jump(int indexReg, int newProgramCounter, Register& reg)
{
    if (reg.getCell(indexReg) == reg.getCell(0)) {
        cpu::m_programCounter = newProgramCounter;
    }

}

    
void halt(){
    throw runtime_error("execution of halt instruction");
}
