#ifndef ALU_H
#define ALU_H

#include<iostream>
#include<string>
#include <cmath>
using namespace std;

class ALU : public Register{
public:
    ALU();
    ~ALU();
    static int hexToDec(string strNumber);
    static string decToHex(int number);
    static bool isValid(string val);
    static void add(int index1, int index2, int index3, Register& reg);
    static string reverse(string str);
};
#endif
