#ifndef ALU_H
#define ALU_H

#include <cmath>
#include "memory.h"

using namespace std;

class ALU {
public:
    ALU();
    ~ALU();
    static int hexToDec(const QString& strNumber);
    static QString decToHex(int number);
    static bool isValid(const QString& val);
    static void addInteger(const QString& index1, const QString& index2, const QString& index3, Register& reg);
    static void addFloat(int index1, int index2, int index3, Register& reg);
    static QString reverse(QString str);
    static QString hexToBin(QString strNumber);
    static int binToDec(QString strNumber);
    static QString decToBin(int number);
    static float binToFloat(QString strNumber);
    static QString floatToBin(float number);
    static QString binToHex(QString strNumber);
    static float hexToFloat(QString& strNumber);
    static QString floatToHex(float number);
};
#endif