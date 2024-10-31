#include "cpu.h"

cpu::cpu(){
    programCounter = 0;
    instructionRegister = "";
    m_memory = new Memory();
    m_register = new Register();
}


cpu::~cpu(){
    delete m_memory;
    delete m_register;
}


void cpu::fetch(Memory& memory) {
    for (int i = 0; i < 3; i++) {
        instructionRegister += memory.getCell(programCounter);
        programCounter++;
    }
}
