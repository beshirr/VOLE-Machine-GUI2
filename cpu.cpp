#include "cpu.h"

int cpu::programCounter = 0;

void cpu::fetch(Memory& memory) {
    // NOTE: THIS VARIABLE WILL BE USED ONLY FOR DISPLAYING IN THE UI
    QString instructionRegister;
    for (int i = 0; i < 3; i++) {
        instructionRegister += memory.getCell(programCounter);
        programCounter++;
    }
}
