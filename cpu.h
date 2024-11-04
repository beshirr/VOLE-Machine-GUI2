#ifndef CPU_H
#define CPU_H


#include <QString>
#include <QChar>
#include "memory.h"
#include "alu.h"
#include "cu.h"


using namespace std;

class cpu {
public:
    static int m_programCounter;
    Memory* m_memory;
    Register* m_register;
    QString m_instructionRegister;
    bool m_isScreen = false;

public:
    cpu();
    ~cpu();
    void fetch();
    QString decode();
    void execute();
};


#endif // CPU_H
