#ifndef VOLE_MACHINE_GUI_MEMORY_H
#define VOLE_MACHINE_GUI_MEMORY_H

#include <iostream>
#include <string>
#include <QString>

using namespace std;


class Memory {
private:
    string m_memory[256];
    int m_size;

public:
    Memory();

    string getCell(int address);

    void setCell(int address, const string& val);
};


class Register {
private:
    int m_register[16];
    int size;

public:
    Register();

    int getCell(int address);

    void setCell(int address, int val);
};




#endif //VOLE_MACHINE_GUI_MEMORY_H
