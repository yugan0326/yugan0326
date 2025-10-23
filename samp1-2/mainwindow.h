#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QProgressBar>
#include <QFontComboBox>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);

private:
    void setupUI();
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    // 新添加的槽函数
    void onFontChanged(const QFont &font);
    void onFontSizeChanged(int index);
    void onTextChanged();

private:
    Ui::MainWindow *ui;
    QProgressBar *progressBar;
    QFontComboBox *fontComboBox;
    QComboBox *fontSizeComboBox;

    void setupToolBar();
    void setupStatusBar();
    void updateProgress();
};

#endif // MAINWINDOW_H
