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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    void connecting();
    void decodingDisplay();
    void memoryDisplay();
    void registerDisplay();
    void updateMemoryDisplay();
    void updateRegisterDisplay();

private slots:
    void onOpenInstructionFileClicked();
    void on_execute_button_clicked();
    void onDecodeButtonClicked();
    void onFetchButtonClicked();
    void on_resetCounter_clicked();
    void on_pCounter_textChanged(const QString &arg1);
    void on_instructionDecode_textChanged(const QString &arg1);
    void on_runOneCycleButton_clicked();
    void on_clearMemoryButton_clicked();
    void on_clearRegButton_clicked();
};
#endif // MAINWINDOW_H
