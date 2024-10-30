#include <iostream>
#include <string>

using namespace std;

class Memory {
private:
    string memory[256];  
    int size;

public:
    Memory() : size(256) {
        for (int i = 0; i < size; ++i) {
            memory[i] = "00";
        }
    }

    string getCell(int address) {
        if (address >= 0 && address < size) {
            return memory[address];
        }
    }

    void setCell(int address, const string& val) {
        if (address >= 0 && address < size) {
            memory[address] = val;
        }
    }
};


class Register {
private:
    int memory[16]; 
    int size;

public:
    Register() : size(16) {
        for (int i = 0; i < size; ++i) {
            memory[i] = 0;
        }
    }

    int getCell(int address) {
        if (address >= 0 && address < size) {
            return memory[address];
        }
    }

    void setCell(int address, int val) {
        if (address >= 0 && address < size) {
            memory[address] = val;
        }
    }
};



