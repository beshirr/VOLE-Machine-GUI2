#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    // Vector to hold the content of the file (Each instruction)
    vector<QString> fileContent;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openInstructionFile_clicked();

    void on_excuteButton_clicked();

    void on_decodeButton_clicked();

    void on_instructionDecode_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
