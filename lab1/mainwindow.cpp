#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化计算器状态
    currentValue = 0.0;
    storedValue = 0.0;
    pendingOperation = "";
    waitingForOperand = true;
    operand = "0"; // 初始化操作数字符串

    digitBTNs = {
                 {Qt::Key_0, ui->btnNum0},
                 {Qt::Key_1, ui->btnNum1},
                 {Qt::Key_2, ui->btnNum2},
                 {Qt::Key_3, ui->btnNum3},
                 {Qt::Key_4, ui->btnNum4},
                 {Qt::Key_5, ui->btnNum5},
                 {Qt::Key_6, ui->btnNum6},
                 {Qt::Key_7, ui->btnNum7},
                 {Qt::Key_8, ui->btnNum8},
                 {Qt::Key_9, ui->btnNum9},
                 };

    foreach(auto btn, digitBTNs)
        connect(btn, SIGNAL(clicked()), this, SLOT(btnNumClicked()));

    // 连接运算符按钮
    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnBinaryOperandorClicked()));
    connect(ui->btnMinus, SIGNAL(clicked()), this, SLOT(btnBinaryOperandorClicked()));
    connect(ui->btnMu, SIGNAL(clicked()), this, SLOT(btnBinaryOperandorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperandorClicked()));

    // 连接一元运算符按钮
    connect(ui->btnPercentage, SIGNAL(clicked()), this, SLOT(btnUnaryqperatorClicked()));
    connect(ui->btnLnverse, SIGNAL(clicked()), this, SLOT(btnUnaryqperatorClicked()));
    connect(ui->btnSquare, SIGNAL(clicked()), this, SLOT(btnUnaryqperatorClicked()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(btnUnaryqperatorClicked()));

    // 修复：移除重复连接，正负号按钮单独处理
    // connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(btnUnaryqperatorClicked())); // 这行移除

    // 连接功能按钮
    connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(onEqualsClicked()));        // 等于按钮
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(onPlusMinusClicked()));     // 正负号按钮
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onCEClicked()));             // CE按钮

    // 初始化显示
    ui->display->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 计算函数 - 保持原有逻辑
QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if(operands.size() == 2 && opcodes.size() > 0)
    {
        // 取操作数
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        // 取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

        // 修复：操作符判断错误，"2"改为"-"
        if (op == "+") {
            result = operand1 + operand2;
        } else if (op == "-") {  // 修复：改为"-"
            result = operand1 - operand2;
        } else if (op == "×") {
            result = operand1 * operand2;
        } else if (op == "/") {
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                // 除零错误处理
                if (ok) *ok = false;
                return "Error";
            }
        }

        operands.push_back(QString::number(result));
        ui->statusbar->showMessage(QString("calculation is in progress：operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));
    }
    else {
        ui->statusbar->showMessage(QString("operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));
    }

    if (ok) *ok = true;
    return QString::number(result);
}

// 数字按钮点击 - 保持原有逻辑
void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && operand == "0")
        digit = "";

    if(operand == "0" && digit != "0")
        operand = "";

    operand += digit;
    ui->display->setText(operand);
}

// 小数点 - 保持原有逻辑
void MainWindow::on_pushButton_21_clicked()
{
    if(!operand.contains("."))
        operand += qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(operand);
}

// 删除 - 保持原有逻辑
void MainWindow::on_btnClear_clicked()
{
    operand = operand.left(operand.length() - 1);
    if(operand.isEmpty()) operand = "0";
    ui->display->setText(operand);
}

// 清空(C按钮) - 修复：清空所有状态
void MainWindow::on_pushButton_3_clicked()
{
    operand = "0";
    operands.clear();
    opcodes.clear();
    currentValue = 0.0;
    storedValue = 0.0;
    pendingOperation = "";
    waitingForOperand = true;
    ui->display->setText("0");
    ui->statusbar->clearMessage();
}

// 二元运算符 - 保持原有逻辑
void MainWindow::btnBinaryOperandorClicked()
{
    ui->statusbar->showMessage("last operand" + operand);
    QString opcode = qobject_cast<QPushButton *>(sender())->text();

    if(operand != "" && operand != "0")
    {
        operands.push_back(operand);
        operand = "";
        opcodes.push_back(opcode);

        bool ok;
        QString result = calculation(&ok);
        if (ok) {
            ui->display->setText(result);
        } else {
            ui->display->setText(result); // 显示错误信息
            // 清空状态
            operands.clear();
            opcodes.clear();
        }
    }
}

// 一元运算符 - 修复：添加错误处理
void MainWindow::btnUnaryqperatorClicked()
{
    if (operand != "" && operand != "0"){
        double result = operand.toDouble();
        QString op = qobject_cast<QPushButton*>(sender())->text();

        if(op == "%")
            result /= 100.0;
        else if(op == "1/x") {
            if (result != 0) {
                result = 1 / result;
            } else {
                ui->display->setText("Error");
                return;
            }
        } else if(op == "x^2")
            result *= result;
        else if(op == "√") {
            if (result >= 0) {
                result = sqrt(result);
            } else {
                ui->display->setText("Error");
                return;
            }
        }

        operand = QString::number(result);
        ui->display->setText(operand);
    }
}

// ===========================================================
// 等于按钮的功能实现 - 修复：整合两种计算逻辑
void MainWindow::onEqualsClicked()
{
    if (operand.isEmpty() || operand == "0") {
        return; // 没有输入操作数
    }

    // 如果有等待的二元运算，使用新的计算逻辑
    if (!pendingOperation.isEmpty()) {
        double rightOperand = operand.toDouble();

        if (pendingOperation == "+") {
            currentValue += rightOperand;
        } else if (pendingOperation == "-") {
            currentValue -= rightOperand;
        } else if (pendingOperation == "×") {
            currentValue *= rightOperand;
        } else if (pendingOperation == "/") {
            if (rightOperand != 0.0) {
                currentValue /= rightOperand;
            } else {
                ui->display->setText("Error");
                pendingOperation = "";
                waitingForOperand = true;
                return;
            }
        }

        operand = QString::number(currentValue);
        ui->display->setText(operand);
        pendingOperation = "";
    }
    // 否则使用原有的栈式计算逻辑
    else if (!opcodes.isEmpty()) {
        operands.push_back(operand);
        bool ok;
        QString result = calculation(&ok);
        if (ok) {
            operand = result;
            ui->display->setText(operand);
        }
    }

    waitingForOperand = true;
}

// 正负号按钮的功能实现 - 修复：与一元运算符逻辑保持一致
void MainWindow::onPlusMinusClicked()
{
    if (!operand.isEmpty() && operand != "0") {
        double value = operand.toDouble();
        value = -value;
        operand = QString::number(value);
        ui->display->setText(operand);
    }
}

// CE按钮的功能实现 - 修复：只清除当前输入
void MainWindow::onCEClicked()
{
    operand = "0";
    ui->display->setText("0");
    waitingForOperand = true;
}

// 键盘事件处理 - 保持原有逻辑
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach (auto btnKey, digitBTNs.keys())
    {
        if(event->key() == btnKey)
            digitBTNs[btnKey]->animateClick();
    }

    // 运算符和功能键处理
    switch(event->key()) {
    case Qt::Key_Slash:      // / 除号
        ui->btnDivide->animateClick();
        break;
    case Qt::Key_Asterisk:   // * 乘号
        ui->btnMu->animateClick();
        break;
    case Qt::Key_Minus:      // - 减号
        ui->btnMinus->animateClick();
        break;
    case Qt::Key_Plus:       // + 加号
        ui->btnPlus->animateClick();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:     // 回车键
        ui->pushButton_22->animateClick();
        break;
    case Qt::Key_Backspace:     // 删除键（退格）
        ui->btnClear->animateClick();
        break;
    case Qt::Key_Period:     // . 小数点
        ui->pushButton_21->animateClick();
        break;
    case Qt::Key_Escape:     // ESC键 - C按钮
        ui->pushButton_3->animateClick();
        break;
    }
}
