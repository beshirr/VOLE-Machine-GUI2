#ifndef CU_H
#define CU_H

#include "memory.h"
#include <QString>

class cu{
public:
    cu();
    static void load(int indexReg, int indexMem, Memory& mem, Register& reg);
    static void load(int indexReg, QString val, Register& reg);
    static void store(int indexReg, int indexMem, Memory& mem, Register& reg);
    static void move(int indexReg1, int indexReg2, Register& reg);
    static void jump(int indexReg, int indexMem, Register& reg);
    static void halt();
};

#endif
