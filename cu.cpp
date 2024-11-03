#include "cu.h"


cu::cu() = default;

void cu::load(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg){
    QString valueToLoad = mem.getCell(indexMem.toInt(nullptr, 16));
    reg.setCell(indexReg.toInt(nullptr, 16), valueToLoad);
}

void cu::load(const QString& indexReg, const QString& val, Register& reg){
    reg.setCell(indexReg.toInt(nullptr, 16), val);
}

void cu::store(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg){
    QString valueToStore = reg.getCell(indexReg.toInt(nullptr, 16));

    if (indexMem == "00") {
        
    }
    mem.setCell(indexMem.toInt(nullptr, 16), valueToStore);
}

void cu::move(const QString& indexReg1, const QString& indexReg2, Register& reg){
    QString valueToMove = reg.getCell(indexReg1.toInt(nullptr, 16));
    reg.setCell(indexReg1.toInt(nullptr, 16), "00");
    reg.setCell(indexReg2.toInt(nullptr, 16), valueToMove);
}

void cu::jump(const QString& indexReg, const QString& indexMem, Register& reg, Memory& mem, int programCounter)
{
    if (reg.getCell(indexReg.toInt(nullptr, 16)) == reg.getCell(0)) {
        QString value = mem.getCell(indexMem.toInt(nullptr, 16));
        mem.setCell(programCounter, value);
    }
}


void cu::halt(){
    throw runtime_error("execution of halt instruction");
}
