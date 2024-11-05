/**
 * @file alu.cpp
 *
 * @brief this file contains the declaration of the alu.h file
 */


#include "alu.h"


/**
 * @brief This function reverses a given QString.
 *
 * @param number The QString to be reversed.
 * @return QString The reversed QString.
 *
 * This function takes a QString as input and returns a new QString that is the reverse of the input.
 * It iterates over the input QString from the end to the beginning and appends each character to a new QString.
 * The reversed QString is then returned.
 */
QString ALU::reverse(QString number){
    QString reverseNum = "";
    for(auto i = number.size()-1; i >= 0; i--){
        reverseNum += number[i];
    }
    return reverseNum;
}


/**
 * @brief Converts a hexadecimal number to binary.
 *
 * @param strNumber The hexadecimal number to be converted.
 * @return QString The binary representation of the input hexadecimal number.
 *
 * This function takes a hexadecimal number as input and returns its binary representation.
 * It iterates over each character of the input hexadecimal number, converts it to its corresponding binary value,
 * and appends it to a new QString. The function ensures that the binary representation is 8-bit long.
 *
 * @note The input hexadecimal number should be a valid hexadecimal number (0-9, A-F).
 */
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
        if (binaryHalf[i].size() < 4){
            int counter = binaryHalf[i].size();
            while (counter < 4){
                binaryHalf[i] += '0';
                counter++;
            }
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


/**
 * @brief Converts a binary number to its decimal equivalent.
 *
 * @param strNumber The binary number to be converted.
 * @return int The decimal representation of the input binary number.
 *
 * This function takes a binary number as input and returns its decimal equivalent.
 * It iterates over each character of the input binary number, converts it to its corresponding decimal value,
 * and accumulates the sum. The function handles both positive and negative binary numbers.
 *
 * @note The input binary number should be a valid binary number (0 or 1).
 */
int ALU::binToDec(QString strNumber) {
    int power = 7;
    int decNumber = 0;
    for (int i = 0; i < 8; ++i) {
        if(i == 0){
            decNumber -= strNumber[i].digitValue() * pow(2, power);
        }
        else{
            decNumber += strNumber[i].digitValue() * pow(2, power);
        }
        power--;
    }
    return decNumber;
}


/**
 * @brief Converts a hexadecimal number to its decimal equivalent.
 *
 * @param strNumber The hexadecimal number to be converted. It should be a valid hexadecimal number (0-9, A-F).
 * @return int The decimal representation of the input hexadecimal number.
 *
 * This function takes a hexadecimal number as input and returns its decimal equivalent.
 * It internally converts the hexadecimal number to binary using the hexToBin function,
 * and then converts the binary number to decimal using the binToDec function.
 *
 * @note The input hexadecimal number should be a valid hexadecimal number (0-9, A-F).
 */
int ALU::hexToDec(const QString& strNumber){
    QString binNumber = ALU::hexToBin(strNumber);
    int decNumber = ALU::binToDec(binNumber);
    return decNumber;
}


/**
 * @brief Converts a decimal number to its 8-bit binary representation.
 *
 * @param number The decimal number to be converted.
 * @return QString The 8-bit binary representation of the input decimal number.
 *
 * This function takes a decimal number as input and returns its 8-bit binary representation.
 * If the input number is negative, it is converted to its 8-bit two's complement representation.
 * The function uses a loop to repeatedly divide the number by 2 and append the remainder to a QString.
 * The binary representation is then reversed and padded with leading zeros if necessary to make it 8 bits long.
 *
 * @note The input number should be within the range of a signed 8-bit integer (-128 to 127).
 */
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
    if (binNumber.size() < 8){
        int counter = binNumber.size();
        while (counter < 8){
            binNumber += '0';
            counter++;
        }
    }
    binNumber = ALU::reverse(binNumber);
    return binNumber;
}


/**
 * @brief Converts a binary number to its hexadecimal equivalent.
 *
 * @param strNumber The binary number to be converted. It should be a valid 8-bit binary number.
 * @return QString The hexadecimal representation of the input binary number.
 *
 * This function takes an 8-bit binary number as input and returns its hexadecimal equivalent.
 * It iterates over the input binary number in groups of 4 bits, converts each group to its corresponding hexadecimal digit,
 * and appends it to a new QString. The function handles both positive and negative binary numbers.
 *
 * @note The input binary number should be a valid 8-bit binary number.
 */
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


/**
 * @brief Converts a decimal number to its hexadecimal equivalent.
 *
 * @param number The decimal number to be converted. It should be within the range of a signed 8-bit integer (-128 to 127).
 * @return QString The hexadecimal representation of the input decimal number.
 *
 * This function takes a decimal number as input and returns its hexadecimal equivalent.
 * It internally converts the decimal number to its 8-bit binary representation using the decToBin function,
 * and then converts the binary number to hexadecimal using the binToHex function.
 *
 * @note The input number should be within the range of a signed 8-bit integer (-128 to 127).
 */
QString ALU::decToHex(int number){
    QString binNumber = decToBin(number);
    QString hexNumber = binToHex(binNumber);
    return hexNumber;
}


/**
 * @brief Performs addition of two integer values stored in the register at given indices.
 *
 * @param index1 The index of the first register cell containing the first integer value.
 * @param index2 The index of the second register cell containing the second integer value.
 * @param index3 The index of the register cell where the result will be stored.
 * @param reg The register object containing the integer values.
 *
 * This function retrieves the integer values stored in the register at the given indices,
 * performs addition, and stores the result in the register cell at the third index.
 * The integer values are first converted from hexadecimal to decimal using the hexToDec function,
 * and the result is then converted back to hexadecimal using the decToHex function.
 *
 * @note The input indices should be valid register cell indices (0-15).
 * @note The register object should be properly initialized and contain valid integer values.
 */
void ALU::addInteger(const QString& index1, const QString& index2, const QString& index3, Register& reg){
    int num1 = ALU::hexToDec(reg.getCell(index1.toInt(nullptr, 16)));
    int num2 = ALU::hexToDec(reg.getCell(index2.toInt(nullptr, 16)));
    reg.setCell(index3.toInt(nullptr, 16), ALU::decToHex(num1 + num2));
}


/**
 * @brief Converts a binary number to its floating-point representation.
 *
 * @param strNumber The binary number to be converted. It should be a valid 8-bit binary number representing a floating-point number.
 * @return float The floating-point representation of the input binary number.
 *
 * This function takes an 8-bit binary number as input and returns its floating-point representation.
 * The binary number is first split into the sign bit, exponent, and mantissa.
 * The sign bit is extracted and used to determine the sign of the floating-point number.
 * The exponent is extracted and converted from binary to decimal, then adjusted to account for the bias.
 * The mantissa is extracted and converted from binary to decimal, then multiplied by 2 raised to the power of the adjusted exponent.
 * The sign, adjusted exponent, and mantissa are then combined to form the floating-point number.
 *
 * @note The input binary number should be a valid 8-bit binary number representing a floating-point number.
 */
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
    floatNum = (mantissa / 16.0) * pow(2, exponent) * pow(-1, strNumber[0].digitValue());
    return floatNum;
}


/**
 * @brief Converts a hexadecimal number to its floating-point representation.
 *
 * @param strNumber The hexadecimal number to be converted. It should be a valid 8-bit hexadecimal number representing a floating-point number.
 * @return float The floating-point representation of the input hexadecimal number.
 *
 * This function takes an 8-bit hexadecimal number as input and returns its floating-point representation.
 * The hexadecimal number is first converted to binary using the hexToBin function,
 * and then the binary number is converted to floating-point using the binToFloat function.
 *
 * @note The input hexadecimal number should be a valid 8-bit hexadecimal number representing a floating-point number.
 */
float ALU::hexToFloat(QString strNumber) {
    QString binNumber = hexToBin(strNumber);
    float floatNumber = binToFloat(binNumber);
    return floatNumber;
}


/**
 * @brief Converts a floating-point number to its 8-bit binary representation.
 *
 * @param number The floating-point number to be converted.
 * @return QString The 8-bit binary representation of the input floating-point number.
 *
 * This function takes a floating-point number as input and returns its 8-bit binary representation.
 * The floating-point number is first split into the sign bit, exponent, and mantissa.
 * The sign bit is extracted and used to determine the sign of the binary number.
 * The exponent is extracted and converted from decimal to binary, then adjusted to account for the bias.
 * The mantissa is extracted and converted from decimal to binary, then multiplied by 2 raised to the power of the adjusted exponent.
 * The sign, adjusted exponent, and mantissa are then combined to form the 8-bit binary representation.
 *
 * @note The input floating-point number should be within the range of a valid 8-bit floating-point number.
 */
QString ALU::floatToBin(float number) {
    QString binNumber = "";
    QString signBit;
    if(number < 0){
        signBit = "1";
        number *= (-1);
    }
    else{
        signBit = "0";
    }
    int exponent = 0;
    int mantissa = 0;
    number *= 16;
    for (int i = 3; i >= -4; i--){
        if (number / pow(2, i) == int(number / pow(2, i))){
            exponent = i;
            break;
        }
    }
    mantissa = number / (pow(2, exponent));
    exponent += 4;
    QString strExponent = "";
    while (exponent > 0){
        if(exponent % 2 == 0){
            strExponent += '0';
        }
        else{
            strExponent += '1';
        }
        exponent /= 2;
    }
    if (binNumber.size() < 3){
        int counter = strExponent.size();
        while (counter < 3){
            strExponent += '0';
            counter++;
        }
    }
    QString strMantissa = "";
    while (mantissa > 0){
        if(mantissa % 2 == 0){
            strMantissa += '0';
        }
        else{
            strMantissa += '1';
        }
        mantissa /= 2;
    }
    if (strMantissa.size() < 4){
        int counter = strMantissa.size();
        while (counter < 4){
            strMantissa += '0';
            counter++;
        }
    }
    binNumber += signBit;
    binNumber += ALU::reverse(strExponent);
    binNumber += ALU::reverse(strMantissa);

    return binNumber;
}


/**
 * @brief Converts a floating-point number to its hexadecimal representation.
 *
 * @param number The floating-point number to be converted.
 * @return QString The hexadecimal representation of the input floating-point number.
 *
 * This function takes a floating-point number as input and returns its hexadecimal representation.
 * The floating-point number is first converted to its 8-bit binary representation using the floatToBin function.
 * Then, the binary number is converted to hexadecimal using the binToHex function.
 *
 * @note The input floating-point number should be within the range of a valid 8-bit floating-point number.
 */
QString ALU::floatToHex(float number) {
    QString binNumber = ALU::floatToBin(number);
    QString hexNumber = ALU::binToHex(binNumber);
    return hexNumber;
}


/**
 * @brief Performs addition of two floating-point values stored in the register at given indices.
 *
 * @param index1 The index of the first register cell containing the first floating-point value.
 * @param index2 The index of the second register cell containing the second floating-point value.
 * @param index3 The index of the register cell where the result will be stored.
 * @param reg The register object containing the floating-point values.
 *
 * This function retrieves the floating-point values stored in the register at the given indices,
 * performs addition, and stores the result in the register cell at the third index.
 * The floating-point values are first converted from hexadecimal to floating-point using the hexToFloat function,
 * and the result is then converted back to hexadecimal using the floatToHex function.
 *
 * @note The input indices should be valid register cell indices (0-15).
 * @note The register object should be properly initialized and contain valid floating-point values.
 */
void ALU::addFloat(const QString& index1, const QString& index2, const QString& index3, Register &reg) {
    float num1 = ALU::hexToFloat(reg.getCell(index1.toInt(nullptr, 16)));
    float num2 = ALU::hexToFloat(reg.getCell(index2.toInt(nullptr, 16)));
    reg.setCell(index3.toInt(nullptr, 16), ALU::floatToHex(num1 + num2));
}
