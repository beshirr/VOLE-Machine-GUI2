/**
 * @file memory.cpp
 *
 * @brief this file contains the declaration of the memory and register classes
 */

#include "memory.h"


/**
 * @brief Constructor for the Memory class. Initializes the memory with 256 cells, each containing "00".
 *
 * @param m_size The size of the memory. Default value is 256.
 */
Memory::Memory() : m_size(256) {
    for (int i = 0; i < m_size; ++i) {
        memory[i] = "00";
    }
}


/**
 * @brief Retrieves the value stored in the specified memory cell.
 *
 * This function checks if the given address is within the valid range of the memory.
 * If the address is valid, it returns the value stored in the memory cell at the specified address.
 * If the address is out of range, it returns an empty string.
 *
 * @param address The address of the memory cell to retrieve the value from.
 * @return The value stored in the memory cell at the specified address. If the address is out of range, returns an
 * empty string.
 */
QString Memory::getCell(int address) {
    if (address >= 0 && address < m_size) {
        return memory[address];
    }
}


/**
 * @brief Sets the value of the specified memory cell.
 *
 * This function checks if the given address is within the valid range of the memory.
 * If the address is valid, it sets the value of the memory cell at the specified address to the given value.
 * If the address is out of range, it does nothing.
 *
 * @param address The address of the memory cell to set the value for.
 * @param val The value to be stored in the memory cell at the specified address.
 *
 * @return void
 */
void Memory::setCell(int address, const QString& val) {
    if (address >= 0 && address < m_size) {
        memory[address] = val;
    }
}


Register::Register() : size(16) {
    for (int i = 0; i < size; ++i) {
        m_register[i] = "00";
    }
}

QString Register::getCell(int address) {
    if (address >= 0 && address < size) {
        return m_register[address];
    }
}

void Register::setCell(int address, const QString& val) {
    if (address >= 0 && address < size) {
        m_register[address] = val;
    }
}




