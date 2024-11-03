#ifndef CPU_H
#define CPU_H


#include <QString>
#include <QChar>
#include "memory.h"
#include "alu.h"
#include "cu.h"

using namespace std;

class processor {
public:
    static int m_programCounter;
    Memory* m_memory;
    Register* m_register;
    QString m_instructionRegister;

public:
    processor();
    ~processor();
    void fetch();
    QString decode();
    void execute();
    void runOneCycle();
    void runTillHalt();
};


#endif // CPU_H
