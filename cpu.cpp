#include "cpu.h"

cpu::cpu() {}


void cpu::execute() {
    return;
}


/**
 * @fn This Function is to decode Each instrucion from the instructions file
 * @param instruction the instrucion to decode
 * @brief prints the decoding of the instruciton
 * @return a vector of the decoded parts of the instruction to be exuted
*/
vector<QChar> cpu::decode(const QString& instruction) {
    vector<QChar> decoded;
    // index 0 = o-p code
    // index 1 = Register
    // index 2 = Memory X
    // index 3 = Memory Y
    for (int i = 0; i < 4; ++i) {
        decoded[i] = instruction[i];
    }




    return decoded;
}
