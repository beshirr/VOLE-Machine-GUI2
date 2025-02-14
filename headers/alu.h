/**
 * @file alu.h
 *
 * @brief this file contains the definition of the ALU class which is responsible for the Arithmetic logical operations
 * */

#ifndef ALU_H
#define ALU_H

#include <cmath>
#include "memory.h"

using namespace std;

class ALU {
public:
    static int hexToDec(const QString& strNumber);
    static QString decToHex(int number);
    static void addInteger(const QString& index1, const QString& index2, const QString& index3, Register& reg);
    static void addFloat(const QString& index1, const QString& index2, const QString& index3, Register &reg);
    static QString reverse(QString str);
    static QString hexToBin(QString strNumber);
    static int binToDec(QString strNumber);
    static QString decToBin(int number);
    static float binToFloat(QString strNumber);
    static QString floatToBin(float number);
    static QString binToHex(QString strNumber);
    static float hexToFloat(QString strNumber);
    static QString floatToHex(float number);
};
#endif