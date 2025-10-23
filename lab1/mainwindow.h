#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStack>
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString operand;
    QString opcode;
    QStack<QString> operands;
    QStack<QString>opcodes;

    QString calculation(bool *ok=NULL);

private slots:

    void btnNumClicked();

    void btnBinaryOperandorClicked();

    void on_pushButton_21_clicked();

    void on_btnClear_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
