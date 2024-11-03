#ifndef VOLE_MACHINE_GUI_MEMORY_H
#define VOLE_MACHINE_GUI_MEMORY_H

#include <string>
#include <QString>

using namespace std;


class Memory {
private:
    QString memory[256];
    int m_size;

public:
    Memory();

    QString getCell(int address);

    void setCell(int address, const QString& val);
};


class Register {
private:
    QString m_register[16];
    int size;

public:
    Register();

    QString getCell(int address);

    void setCell(int address, const QString& val);
};




#endif //VOLE_MACHINE_GUI_MEMORY_H
