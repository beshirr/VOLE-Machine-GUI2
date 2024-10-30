#include "mainwindow.h"
#include "memory.cpp"
#include "cpu.h"
#include "cu.h"
#include "alu.h"
#include <QApplication>


void runMain() {
    Memory memo;
    Register reg;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    runMain();  // Run the main function to initialize the memory object and other resources
    w.show();
    return a.exec();
}
