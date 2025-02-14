/**
 * @file cpu.h
 *
 * @brief This file contains the definition of the cpu class which is responsible of managing the whole process of the execution
 */

#ifndef CPU_H
#define CPU_H


#include <QString>
#include <QChar>
#include "memory.h"
#include "alu.h"
#include "cu.h"
#include <QRegularExpression>


using namespace std;

class cpu {
public:
    bool m_isScreen = false;
    static int m_programCounter;
    QString m_instructionRegister;
    // Creating instances of memory and register
    Memory* m_memory;
    Register* m_register;

public:
    cpu();
    ~cpu();
    void fetch();
    QString decode();
    void execute();
    bool isValidInstructoin(const QString& instruction);
};


#endif // CPU_H
