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


void ALU::addInteger(int index1, int index2, int index3, Register& reg){
    int num1 = ALU::hexToDec(reg.getCell(index1));
    int num2 = ALU::hexToDec(reg.getCell(index2));
    reg.setCell(index3, ALU::decToHex(num1 + num2));
}
