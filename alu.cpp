#include "alu.h"

string reverse(string number){
    string reverseNum = "";
    for(int i = number.size()-1; i >= 0; i--){
        reverseNum += number[i];
    }
    return reverseNum;
}

int ALU::hexToDec(string strnumber){
    int power = 0;
    string hexNumber = reverse(strnumber);
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
            decNumber += (hexNumber[i]+'0') * pow(16, power);
        }

    }
    return decNumber;

}

string ALU::decToHex(int number){
    string hexNumber = "";
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

    hexNumber = reverse(hexNumber);
    return hexNumber;
}

bool isValid(string val){

}

void add(int index1, int index2, int index3, Register& reg){
    int num1 = reg[index1];
    int num2 = reg[index2];
    reg[index3] = num1 + num2;
}
