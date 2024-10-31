#include "memory.h"

Memory::Memory() : m_size(256) {
    for (int i = 0; i < m_size; ++i) {
        memory[i] = "00";
    }
}

QString Memory::getCell(int address) {
    if (address >= 0 && address < m_size) {
        return memory[address];
    }
}

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




