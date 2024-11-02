#include "cu.h"
#include "memory.h"
#include <QString>

cu::cu() {}

void cu::load(int indexReg, int indexMem, Memory& mem, Register& reg){
    Qstring valueToLoad = mem.getCell(indexMem);
    reg.setCell(indexReg, valueToLoad);
}

void cu::load(int indexReg, QString val, Register& reg){
    reg.setCell(indexReg, val);
}

void cu::store(int indexReg, int indexMem, Memory& mem, Register& reg)
{ 
    Qstring valueToLoad = reg.getCell(indexReg); 

    if (indexMem == "00") {
        cout << valueToLoad<<endl;
    }
    mem.setCell(indexMem, valueToLoad);
}



void cu::move(int indexReg1, int indexReg2, Register& reg){
    QString valueToMove = reg.getCell(indexReg1);
    reg.setCell(indexReg2, valueToMove);
}

void cu::jump(int indexReg, int indexMem, Register& reg){
    
}