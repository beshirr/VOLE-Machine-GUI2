#ifndef CPU_H
#define CPU_H


#include <QString>
#include <QChar>
#include "memory.h"

using namespace std;

class cpu {
public:
    static int programCounter;
    Memory* m_memory;
    Register* m_register;
    QString instructionRegister;

public:
    cpu();
    ~cpu();
    static void fetch(Memory& memory);
    static void decode();
    static void execute();
    static void runOneCycle();
    static void runTillHalt();
};


#endif // CPU_H
