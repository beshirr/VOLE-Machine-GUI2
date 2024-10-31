#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include "cpu.h"

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    cpu* m_cpu;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openInstructionFile_clicked();

    void on_executeButton_clicked();

    void on_decodeButton_clicked();

    void on_instructionDecode_textChanged(const QString &arg1);

    void on_fetchButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
