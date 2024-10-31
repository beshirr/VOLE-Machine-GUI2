#include "cpu.h"

int cpu::m_programCounter = 0;

cpu::cpu(){
    m_instructionRegister = "";
    m_memory = new Memory();
    m_register = new Register();
}


cpu::~cpu(){
    delete m_memory;
    delete m_register;
}


void cpu::fetch() {
    for (int i = 0; i < 2; i++) {
        m_instructionRegister += m_memory->getCell(m_programCounter);
        m_programCounter++;
    }
}


vector<QChar> cpu::decode() {

}