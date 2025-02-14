/**
 * @brief VOLE-Machine simulator
 *
 * @authors: Moaaz Mohamed Soliman  20230410
 *           Youssef Ahmed Beshir   20230476
 *           Zeyad Mohamed Arafat   20230161
 *
 * @details This is the CS213:Object Oriented Programming (fall 2024) Assignment-1 Tasks-4&5
 * Instructor: DR/Mohamed El-Ramly
 *
 * @github: https://github.com/beshirr/VOLE-Machine-Simulator
 */


#include "headers/mainwindow.h"
#include <QApplication>


/**
 * @brief The main entry point of the VOLE-Machine simulator application.
 *
 * This function initializes the QApplication and creates an instance of the MainWindow class.
 * It then shows the MainWindow and enters the Qt event loop, where the application runs.
 */
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}