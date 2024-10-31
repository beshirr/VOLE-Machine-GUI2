#ifndef CPU_H
#define CPU_H


#include <QString>
#include <QChar>
#include "memory.h"

using namespace std;

class cpu {
public:
    static int m_programCounter;
    Memory* m_memory;
    Register* m_register;
    QString m_instructionRegister;

public:
    cpu();
    ~cpu();
    void fetch();
    vector<QChar> decode();
    void execute();
    void runOneCycle();
    void runTillHalt();
};


#endif // CPU_H
