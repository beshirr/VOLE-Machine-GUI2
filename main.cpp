#include "volemachine.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VoleMachine w;
    w.show();
    return a.exec();
}
