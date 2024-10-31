#ifndef ALU_H
#define ALU_H

#include <cmath>
#include "memory.h"
#include "mainwindow.h"

using namespace std;

class ALU {
public:
    ALU();
    ~ALU();
    static int hexToDec(const QString& strNumber);
    static QString decToHex(int number);
    static bool isValid(const QString& val);
    static void add(int index1, int index2, int index3, Register& reg);
    static QString reverse(QString str);
};
#endif
