#ifndef CU_H
#define CU_H

#include "memory.h"
#include <QString>

class cu{
public:
    cu();
    static void load(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg);
    static void load(const QString& indexReg, const QString& val, Register& reg);
    static void store(int indexReg, const QString& indexMem, Memory& mem, Register& reg);
    static void move(const QString& indexReg1, const QString& indexReg2, Register& reg);
    static void jump(const QString& indexReg, int NewProgramCounter, Register& reg);
    static void halt();
};

#endif
