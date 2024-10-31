#ifndef ALU_H
#define ALU_H

using namespace std;
#include<iostream>
#include<string>
#include <cmath>


class ALU{
public:
    ALU();
    ~ALU();

    int hexToDec(string strNumber);
    string decToHex(int number);
    bool isValid(string val);
    void add(int index1, int index2, int index3, Register& reg);
    string reverse(string str);
};




#endif
