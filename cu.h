#ifndef CU_H
#define CU_H

#include "memory.h"
#include <QString>

class cu{
public:
    cu();
    static void load(QString indexReg, QString indexMem, Memory& mem, Register& reg);
    static void load(QString indexReg, QString val, Register& reg);
    static void store(QString indexReg, QString indexMem, Memory& mem, Register& reg);
    static void move(QString indexReg1, QString indexReg2, Register& reg);
    static void jump(QString indexReg, int NewProgramCounter, Register& reg);
    static void halt();
};

#endif
