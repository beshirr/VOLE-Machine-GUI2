#ifndef VOLEMACHINE_H
#define VOLEMACHINE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class VoleMachine;
}
QT_END_NAMESPACE

class VoleMachine : public QMainWindow
{
    Q_OBJECT

public:
    VoleMachine(QWidget *parent = nullptr);
    ~VoleMachine();

private:
    Ui::VoleMachine *ui;
};
#endif // VOLEMACHINE_H
