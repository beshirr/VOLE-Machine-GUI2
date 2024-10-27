#include "volemachine.h"
#include "./ui_volemachine.h"

VoleMachine::VoleMachine(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VoleMachine)
{
    ui->setupUi(this);
}

VoleMachine::~VoleMachine()
{
    delete ui;
}
