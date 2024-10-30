#include <iostream>
#include <string>

using namespace std;

class Memory {
private:
    string m_memory[256];
    int m_size;

public:
    Memory() : m_size(256) {
        for (int i = 0; i < m_size; ++i) {
            m_memory[i] = "00";
        }
    }

    string getCell(int address) {
        if (address >= 0 && address < m_size) {
            return m_memory[address];
        }
    }

    void setCell(int address, const string& val) {
        if (address >= 0 && address < m_size) {
            m_memory[address] = val;
        }
    }
};


class Register {
private:
    int m_register[16];
    int size;

public:
    Register() : size(16) {
        for (int i = 0; i < size; ++i) {
            m_register[i] = 0;
        }
    }

    int getCell(int address) {
        if (address >= 0 && address < size) {
            return m_register[address];
        }
    }

    void setCell(int address, int val) {
        if (address >= 0 && address < size) {
            m_register[address] = val;
        }
    }
};



