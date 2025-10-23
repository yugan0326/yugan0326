#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

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


    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
    connect(ui->btnPlus,SIGNAL(clicked()),this,SLOT(btnBinaryOperandorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperandorClicked()));
    connect(ui->btnMu,SIGNAL(clicked()),this,SLOT(btnBinaryOperandorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperandorClicked()));

    connect(ui->btnPercentage,SIGNAL(clicked()),this,SLOT(btnUnaryqperatorClicked()));
    connect(ui->btnLnverse,SIGNAL(clicked()),this,SLOT(btnUnaryqperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryqperatorClicked()));
    connect(ui->btnSqrt,SIGNAL(clicked()),this,SLOT(btnUnaryqperatorClicked()));
    connect(ui->pushButton_24,SIGNAL(clicked()),this,SLOT(btnUnaryqperatorClicked()));
    // 连接等于按钮
    connect(ui->pushButton_22, &QPushButton::clicked, this, &MainWindow::onEqualsClicked);

    // 连接正负号按钮
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::onPlusMinusClicked);

    // 连接CE按钮
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onCEClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result=0;
    if(operands.size()==2 && opcodes.size()>0)
    {
        //取操作数
            double operand1 =operands.front().toDouble();
        operands.pop_front();
        double operand2 =operands.front().toDouble();
        operands.pop_front();
        //取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

    if (op == "+"){
    result = operand1 + operand2;
    }else if (op == "2") {
    result = operand1 - operand2;
    }
    else if (op == "×") {
    result = operand1 * operand2;
    }
    else if (op == "/") {
    result = operand1 /operand2;
    }

    operands.push_back(QString::number(result));


            ui->statusbar->showMessage(QString ("calcuation is in progress：operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));
    }
        else
        ui->statusbar->showMessage(QString ("operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));

    return QString::number(result);
}

void MainWindow::btnNumClicked()
{

    QString digit=qobject_cast<QPushButton*>(sender())->text();

    if(digit=="0"&& operand=="0")
        digit="";

    if(operand=="0"&&digit=="0")
        operand="";

    operand+=digit;

    ui->display->setText(operand);


}
//小数点
void MainWindow::on_pushButton_21_clicked()
{

    if(!operand.contains("."))
         operand +=qobject_cast<QPushButton*>(sender())->text();
    ui->display->setText(operand);
}

//删除
void MainWindow::on_btnClear_clicked()
{

    operand=operand.left(operand.length()-1);
     ui->display->setText(operand);
}

//清空
void MainWindow::on_pushButton_3_clicked()
{
    operand.clear();
    ui->display->setText(operand);
}



void MainWindow::btnBinaryOperandorClicked()
{
    ui->statusbar->showMessage("last operand"+operand);
        QString opcode =qobject_cast<QPushButton *>(sender())->text();
    if(operand!="")
    {
        operands.push_back(operand);
        operand="";

        opcodes.push_back(opcode);

    QString result=calculation();

    ui->display->setText(result);
    }
}

void MainWindow::btnUnaryqperatorClicked()
{
    if (operand!=""){
    double result = operand.toDouble();
    operand="";

    QString op =qobject_cast<QPushButton*>(sender())->text();

    if(op == "%")
        result /=100.0;
    else if(op =="1/x")
        result=1/result;
    else if(op =="x^2")
         result *=result;
    else if(op == "√")
        result =sqrt(result);
    else if(op=="±")
    {

        result=-result;
    }
    ui->display->setText(QString::number(result));
}
}

//等于
void MainWindow::on_pushButton_22_clicked()
{
    if (operand != "") {
        operands.push_back(operand);
            operand="";
    }

    QString result=calculation();

    ui->display->setText(result);
}




//===========================================================
// 等于按钮的功能实现
void MainWindow::onEqualsClicked()
{
    double operand = ui->display->text().toDouble();

    if (!pendingOperation.isEmpty()) {
        // 执行存储的操作
        if (pendingOperation == "+") {
            currentValue += operand;
        } else if (pendingOperation == "-") {
            currentValue -= operand;
        } else if (pendingOperation == "×") {
            currentValue *= operand;
        } else if (pendingOperation == "/") {
            if (operand != 0.0) {
                currentValue /= operand;
            } else {
                // 处理除零错误
                ui->display->setText("Error");
                pendingOperation = "";
                waitingForOperand = true;
                return;
            }
        }

        // 显示结果
        ui->display->setText(QString::number(currentValue));
        pendingOperation = "";
    }
    waitingForOperand = true;
}

// 正负号按钮的功能实现
void MainWindow::onPlusMinusClicked()
{
    QString text = ui->display->text();
    double value = text.toDouble();

    // 切换正负号
    value = -value;

    // 更新显示
    ui->display->setText(QString::number(value));

    // 如果当前有等待的操作数，更新当前值
    if (!waitingForOperand) {
        currentValue = value;
    }
}

// CE按钮的功能实现
void MainWindow::onCEClicked()
{
    // 清除当前显示，但不影响存储的值和操作
    ui->display->setText("0");
    waitingForOperand = true;
}

// 为了方便其他操作符按钮使用，这里也提供数字按钮和操作符按钮的基本处理框架
// （这些可能已经存在，但为了完整性也列出来）

// 数字按钮点击处理（示例）
void MainWindow::onDigitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();

    if (ui->display->text() == "0" || waitingForOperand) {
        ui->display->setText(QString::number(digitValue));
        waitingForOperand = false;
    } else {
        ui->display->setText(ui->display->text() + QString::number(digitValue));
    }
}

// 操作符按钮点击处理（示例）
void MainWindow::onOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();

    double operand = ui->display->text().toDouble();

    if (!pendingOperation.isEmpty()) {
        // 如果已经有等待的操作，先执行它
        onEqualsClicked();
    }

    currentValue = operand;
    pendingOperation = clickedOperator;
    waitingForOperand = true;
}



