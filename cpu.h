#ifndef CPU_H
#define CPU_H


#include <QString>
#include <QChar>

using namespace std;

class cpu {
public:
    static int programCounter;
    QString instruction;

    cpu();
    static void fetch();
    static void decode();
    static void execute();
};

int cpu::programCounter = 0;

#endif // CPU_H
