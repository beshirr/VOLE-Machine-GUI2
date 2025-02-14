/**
 * @file cu.h
 *
 * @brief This file contains the definition of the cu class which is responsible of controlling the execution
 * by loading and storing data to and from both the memory and register.
 * */

#ifndef CU_H
#define CU_H

#include "memory.h"
#include <QString>
#include <stdexcept>
#include "alu.h"

class cu{
public:
    static void load(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg);
    static void load(const QString& indexReg, const QString& val, Register& reg);
    static void store(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg);
    static void move(const QString& indexReg1, const QString& indexReg2, Register& reg);
    static void jump(const QString& indexReg, const QString& indexMem, Register& reg, Memory&mem, int programCounter);
    static void halt();
};

#endif
