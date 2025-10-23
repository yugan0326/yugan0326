#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFont>

// AboutDialog 实现
AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void AboutDialog::setupUI()
{
    setWindowTitle("关于");
    setFixedSize(300, 200);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("samp2_4", this);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setAlignment(Qt::AlignCenter);

    QLabel *infoLabel = new QLabel("开发人员信息：卢树杰", this);
    infoLabel->setAlignment(Qt::AlignCenter);

    QPushButton *okButton = new QPushButton("OK", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(infoLabel);
    mainLayout->addStretch();
    mainLayout->addWidget(okButton);

    setLayout(mainLayout);
}

// MainWindow 实现
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置窗口标题
    setWindowTitle("QWMainWind");

    // 设置状态栏
    statusBar()->showMessage("当前文件：");

    // 连接UI中已有的关于动作
    // 注意：这个连接应该在UI设置后自动建立，但为了明确，我们可以手动连接
    connect(ui->about, &QAction::triggered, this, &MainWindow::on_actionAbout_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}
