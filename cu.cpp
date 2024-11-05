/**
 * @file cu.cpp
 * @brief this file contains the declaration of the cu.h file
 * */


#include "cu.h"


/**
 * @brief Loads a value from memory into a register.
 *
 * This function takes two index parameters (indexReg and indexMem) and two reference parameters (mem and reg).
 * It retrieves the value from memory at the index specified by indexMem and stores it in the register at the index specified by indexReg.
 *
 * @param indexReg The index of the register to store the loaded value.
 * @param indexMem The index of the memory location from which to load the value.
 * @param mem A reference to the memory object where the value is loaded from.
 * @param reg A reference to the register object where the loaded value is stored.
 *
 * @return void
 */
void cu::load(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg){
    QString valueToLoad = mem.getCell(indexMem.toInt(nullptr, 16));
    reg.setCell(indexReg.toInt(nullptr, 16), valueToLoad);
}


void cu::load(const QString& indexReg, const QString& val, Register& reg){
    reg.setCell(indexReg.toInt(nullptr, 16), val);
}


/**
 * @brief Stores a value from a register to memory.
 *
 * This function takes two index parameters (indexReg and indexMem) and two reference parameters (mem and reg).
 * It retrieves the value from the register at the index specified by indexReg and stores it in the memory at the index specified by indexMem.
 *
 * @param indexReg The index of the register from which to load the value.
 * @param indexMem The index of the memory location where to store the value.
 * @param mem A reference to the memory object where the value is stored.
 * @param reg A reference to the register object from which the value is loaded.
 *
 * @return void
 */
void cu::store(const QString& indexReg, const QString& indexMem, Memory& mem, Register& reg){
    QString valueToStore = reg.getCell(indexReg.toInt(nullptr, 16));
    mem.setCell(indexMem.toInt(nullptr, 16), valueToStore);
}


/**
 * @brief Moves the value from one register to another.
 *
 * This function takes two index parameters (indexReg1 and indexReg2) and a reference parameter (reg).
 * It retrieves the value from the register at the index specified by indexReg1, clears the value in the
 * register at indexReg1, and stores the retrieved value in the register at the index specified by indexReg2.
 *
 * @param indexReg1 The index of the register from which to move the value. This index is expected to be a
 * hexadecimal string.
 * @param indexReg2 The index of the register where to store the moved value. This index is expected to be a
 * hexadecimal string.
 * @param reg A reference to the register object where the value is moved.
 *
 * @return void
 */
void cu::move(const QString& indexReg1, const QString& indexReg2, Register& reg){
    QString valueToMove = reg.getCell(indexReg1.toInt(nullptr, 16));
    reg.setCell(indexReg1.toInt(nullptr, 16), "00");
    reg.setCell(indexReg2.toInt(nullptr, 16), valueToMove);
}


/**
 * @brief Performs a conditional jump operation based on the value of a register and a memory location.
 *
 * This function checks the value of a register specified by indexReg. If the value is equal to the value in register 0,
 * it retrieves the value from the memory location specified by indexMem and updates the program counter with this value.
 *
 * @param indexReg The index of the register to check for the jump condition. This index is expected to be a hexadecimal string.
 * @param indexMem The index of the memory location from which to retrieve the value for the program counter. This index is expected to be a hexadecimal string.
 * @param reg A reference to the register object where the value is checked.
 * @param mem A reference to the memory object where the value is retrieved.
 * @param programCounter The current program counter value. This value is updated if the jump condition is met.
 *
 * @return void
 */
void cu::jump(const QString& indexReg, const QString& indexMem, Register& reg, Memory& mem, int programCounter)
{
    if (reg.getCell(indexReg.toInt(nullptr, 16)) == reg.getCell(0)) {
        QString value = mem.getCell(indexMem.toInt(nullptr, 16));
        mem.setCell(programCounter, value);
    }
}

/**
 * @brief terminates the execution process
 */
void cu::halt(){
    throw runtime_error("execution of halt instruction");
}
