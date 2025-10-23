/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actNew;
    QAction *about;
    QAction *actopen;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(594, 331);
        MainWindow->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
        actNew = new QAction(MainWindow);
        actNew->setObjectName("actNew");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/new2.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actNew->setIcon(icon);
        actNew->setMenuRole(QAction::MenuRole::NoRole);
        about = new QAction(MainWindow);
        about->setObjectName("about");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/BLD.BMP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        about->setIcon(icon1);
        about->setMenuRole(QAction::MenuRole::NoRole);
        actopen = new QAction(MainWindow);
        actopen->setObjectName("actopen");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/open3.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actopen->setIcon(icon2);
        actopen->setMenuRole(QAction::MenuRole::NoRole);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/103.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_2->setIcon(icon3);
        action_2->setMenuRole(QAction::MenuRole::NoRole);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/cut.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_3->setIcon(icon4);
        action_3->setMenuRole(QAction::MenuRole::NoRole);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/120.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_4->setIcon(icon5);
        action_4->setMenuRole(QAction::MenuRole::NoRole);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/paste.bmp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_5->setIcon(icon6);
        action_5->setMenuRole(QAction::MenuRole::NoRole);
        action_6 = new QAction(MainWindow);
        action_6->setObjectName("action_6");
        action_6->setIcon(icon1);
        action_6->setMenuRole(QAction::MenuRole::NoRole);
        action_7 = new QAction(MainWindow);
        action_7->setObjectName("action_7");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/ITL.BMP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_7->setIcon(icon7);
        action_7->setMenuRole(QAction::MenuRole::NoRole);
        action_8 = new QAction(MainWindow);
        action_8->setObjectName("action_8");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/D:/samp2_4App/images/WORDUNDR.BMP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        action_8->setIcon(icon8);
        action_8->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 30, 541, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 594, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actNew);
        menu->addSeparator();
        toolBar->addAction(actNew);
        toolBar->addAction(about);
        toolBar->addAction(actopen);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);
        toolBar->addAction(action_4);
        toolBar->addAction(action_5);
        toolBar->addAction(action_6);
        toolBar->addAction(action_7);
        toolBar->addAction(action_8);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(tooltip)
        actNew->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        actopen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        action_5->setText(QCoreApplication::translate("MainWindow", "\347\262\230\347\262\230", nullptr));
        action_6->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
        action_7->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
        action_8->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
