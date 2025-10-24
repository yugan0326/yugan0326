#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QStack>
#include<QLabel>
#include<QKeyEvent>
#include<QMap>
#include<QPushButton>

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
    QMap<int,QPushButton*> digitBTNs;

    //改
    double currentValue;
    double storedValue;
    QString pendingOperation;
    bool waitingForOperand;


    QString calculation(bool *ok=NULL);

private slots:

    void btnNumClicked();

    void btnBinaryOperandorClicked();

    void btnUnaryqperatorClicked();

    void on_pushButton_21_clicked();

    void on_btnClear_clicked();

    void on_pushButton_3_clicked();



    void onEqualsClicked();

    virtual void keyPressEvent(QKeyEvent *event);



    //void onEqualsClicked();           // 等于按钮
    void onPlusMinusClicked();        // 正负号按钮
    void onCEClicked();               // CE按钮

    // 正负号按钮功能
   // void onPlusMinusClicked();

    // CE按钮功能
    //void onCEClicked();

    // 数字按钮功能（如果还没有声明）
   // void onDigitClicked();

    // 操作符按钮功能（如果还没有声明）
   // void onOperatorClicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
