#include "alu.h"


QString ALU::reverse(QString number){
    QString reverseNum = "";
    for(auto i = number.size()-1; i >= 0; i--){
        reverseNum += number[i];
    }
    return reverseNum;
}

QString ALU::hexToBin(QString strNumber){
     QString binaryHalf[2];
     QString binaryNumber = "";
    for (int i = 0; i < 2; ++i) {
        int integerVal;
        if(strNumber[i].isDigit()){
            integerVal = strNumber[i].digitValue();
        }
        else{
            if (strNumber[i] == 'A'){
                integerVal = 10;
            }
            else if (strNumber[i] == 'B'){
                integerVal = 11;
            }
            else if (strNumber[i] == 'C'){
                integerVal = 12;
            }
            else if (strNumber[i] == 'D'){
                integerVal = 13;
            }
            else if (strNumber[i] == 'E'){
                integerVal = 14;
            }
            else if (strNumber[i] == 'F'){
                integerVal = 15;
            }
        }
        while (integerVal > 0){
            if (integerVal % 2 == 0){
                binaryHalf[i] += '0';
            }
            else{
                binaryHalf[i] += '1';
            }
            integerVal /= 2;
        }
        binaryHalf[i] = reverse(binaryHalf[i]);
        binaryNumber += binaryHalf[i];
    }
    if (binaryNumber.size() < 8){
        int counter = binaryNumber.size();
        while (counter < 8){
            binaryNumber += '0';
            counter++;
        }
    }
    return binaryNumber;
}

int ALU::binToDec(QString strNumber) {
    int power = 7;
    int decNumber = 0;
    int sign = 0;
    for (int i = 0; i < 8; ++i) {
        if(sign == 0){
            decNumber -= strNumber[i].digitValue() * pow(2, power);
        }
        else{
            decNumber += strNumber[i].digitValue() * pow(2, power);
        }
        sign++;
        power--;
    }
    return decNumber;
}

int ALU::hexToDec(const QString& strNumber){
    QString binNumber = ALU::hexToBin(strNumber);
    int decNumber = ALU::binToDec(binNumber);
    return decNumber;
}

QString ALU::decToBin(int number) {
    if(number < 0){
        number += 256;
    }
    QString binNumber = "";
    while (number > 0){
        if (number % 2 == 0){
            binNumber += '0';
        }
        else{
            binNumber += '1';
        }
        number /= 2;
    }
    binNumber = reverse(binNumber);
    if (binNumber.size() < 8){
        int counter = binNumber.size();
        while (counter < 8){
            binNumber += '0';
            counter++;
        }
    }
    return binNumber;
}

QString ALU::binToHex(QString strNumber) {
    QString hexNumber = "";
    for (int i = 0; i < 8; i += 4) {
        int power = 3;
        int integerVal = 0;
        for (int j = i; j < 4+i; ++j) {
            integerVal += strNumber[j].digitValue() * pow(2, power);
            power--;
        }
        if (integerVal == 10){
            hexNumber += 'A';
        }
        else if(integerVal == 11){
            hexNumber += 'B';
        }
        else if(integerVal == 12){
            hexNumber += 'C';
        }
        else if(integerVal == 13){
            hexNumber += 'D';
        }
        else if(integerVal == 14){
            hexNumber += 'E';
        }
        else if(integerVal == 15){
            hexNumber += 'F';
        }
        else{
            hexNumber += QString::number(integerVal);
        }
    }
    return hexNumber;
}

QString ALU::decToHex(int number){
    QString binNumber = decToBin(number);
    QString hexNumber = binToHex(binNumber);
    return hexNumber;
}


//bool ALU::isValid(const QString& val){
//
//}


void ALU::addInteger(const QString& index1, const QString& index2, const QString& index3, Register& reg){
    int num1 = ALU::hexToDec(reg.getCell(index1.toInt(nullptr, 16)));
    int num2 = ALU::hexToDec(reg.getCell(index2.toInt(nullptr, 16)));
    reg.setCell(index3.toInt(nullptr, 16), ALU::decToHex(num1 + num2));
}

float ALU::binToFloat(QString strNumber) {
    int exponent = 0;
    int power = 2;
    int mantissa = 0;
    float floatNum;
    for (int i = 1; i < 4; ++i) {
        exponent += strNumber[i].digitValue() * pow(2, power);
        power--;
    }
    exponent -= 4;
    power = 3;
    for (int i = 4; i < 8; ++i) {
        mantissa += strNumber[i].digitValue() * pow(2, power);
        power--;
    }
    floatNum = (mantissa / 16.0) * pow(2, exponent - 4) * pow(-1, strNumber[0].diginValue());
    return floatNum;
}

float ALU::hexToFloat(int strNumber) {
    QString binNumber = hexToBin(strNumber);
    float floatNumber = binToFloat(binNumber);
    return floatNumber;
}

QString ALU::floatToBin(float number) {
    Qstring binNumber = "";
    QString signBit;
    if(number < 0){
        signBit = "1"
    }
    else{
        signBit = "0";
    }
    int exponent = 0;
    QString strExponent = "";
    while (number > 1 || number < 0.5){
        if(number > 1){
            exponent++;
            number /= 2;
        }
        else if(number < 0.5){
            exponent--;
            number *= 2;
        }
    }
    exponent += 4;
    while (exponent > 0){
        if(exponent % 2 == 0){
            strExponent += '0';
        }
        else{
            strExponent += '1';
        }
        exponent /= 2;
    }
    strExponent = ALU::reverse(strExponent);
    int intMantissa = number * 16;
    QString mantissa = "";
    while (intMantissa > 0){
        if(intMantissa % 2 == 0){
            mantissa += '0';
        }
        else{
            mantissa += '1';
        }
        intMantissa /= 2;
    }
    mantissa = ALU::reverse(mantissa);
    binNumber += signBit + strExponent + mantissa;
    return binNumber;

}

QString ALU::floatToHex(float number) {
    QString binNumber = floatToBin(number);
    QString hexNumber = binToHex(binNumber);
    return hexNumber;
}

QString ALU::addFloat(int index1, int index2, int index3, Register &reg) {
    float num1 = ALU::hexToFloat(reg.getCell(index1);
    float num2 = ALU::hexToFloat(reg.getCell(index2);
    reg.setCell(index3, ALU::floatToHex(num1 + num2);
}