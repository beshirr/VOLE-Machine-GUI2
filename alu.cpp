#include "alu.h"
#include"memory.h"


QString ALU::reverse(QString number){
    QString reverseNum = "";
    for(auto i = number.size()-1; i >= 0; i--){
        reverseNum += number[i];
    }
    return reverseNum;
}

// TODO: fix the error at line 38
int ALU::hexToDec(const QString& strNumber){
    int power = 0;
    QString hexNumber = ALU::reverse(strNumber);
    int decNumber = 0;
    for (int i = 0; i < hexNumber.size()-1; i++){
        if (hexNumber[i] == 'A'){
            decNumber += 10 * pow(16, power);
        }
        else if (hexNumber[i] == 'B'){
            decNumber += 11 * pow(16, power);
        }
        else if (hexNumber[i] == 'C'){
            decNumber += 12 * pow(16, power);
        }
        else if (hexNumber[i] == 'D'){
            decNumber += 13 * pow(16, power);
        }
        else if (hexNumber[i] == 'E'){
            decNumber += 14 * pow(16, power);
        }
        else if (hexNumber[i] == 'F'){
            decNumber += 15 * pow(16, power);
        }
        else{
//            decNumber += (hexNumber[i] - '0') * pow(16, power);
        }
        power++;
    }
    return decNumber;
}


QString ALU::decToHex(int number){
    QString hexNumber;
    while (number >= 16){
        if (number % 16 == 10){
            hexNumber += 'A';
        }
        else if (number % 16 == 11){
            hexNumber += 'B';
        }
        else if (number % 16 == 12){
            hexNumber += 'C';
        }
        else if (number % 16 == 13){
            hexNumber += 'D';
        }
        else if (number % 16 == 14){
            hexNumber += 'E';
        }
        else if (number % 16 == 15){
            hexNumber += 'F';
        }
        else{
            hexNumber += to_string(number % 16);
        }
        number /= 16;
    }
    if (number % 16 == 10){
            hexNumber += 'A';
    }
    else if (number % 16 == 11){
        hexNumber += 'B';
    }
    else if (number % 16 == 12){
        hexNumber += 'C';
    }
    else if (number % 16 == 13){
        hexNumber += 'D';
    }
    else if (number % 16 == 14){
        hexNumber += 'E';
    }
    else if (number % 16 == 15){
        hexNumber += 'F';
    }
    else{
        hexNumber += to_string(number % 16);
    }
    hexNumber = ALU::reverse(hexNumber);
    return hexNumber;
}


bool ALU::isValid(const QString& val){

}


void ALU::add(int index1, int index2, int index3, Register& reg){
    int num1 = ALU::hexToDec(reg.getCell(index1));
    int num2 = ALU::hexToDec(reg.getCell(index2));
    reg.getCell(index3) = ALU::decToHex(num1 + num2);
}
