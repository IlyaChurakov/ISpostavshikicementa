/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_program;
    QAction *actionAdd_project;
    QAction *actionEdit_project;
    QAction *actionDelete_project;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QFrame *line;
    QMenuBar *menubar;
    QMenu *menuLanguage;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionAbout_program = new QAction(MainWindow);
        actionAbout_program->setObjectName(QString::fromUtf8("actionAbout_program"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_program->setIcon(icon);
        actionAdd_project = new QAction(MainWindow);
        actionAdd_project->setObjectName(QString::fromUtf8("actionAdd_project"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_project->setIcon(icon1);
        actionEdit_project = new QAction(MainWindow);
        actionEdit_project->setObjectName(QString::fromUtf8("actionEdit_project"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ico/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_project->setIcon(icon2);
        actionDelete_project = new QAction(MainWindow);
        actionDelete_project->setObjectName(QString::fromUtf8("actionDelete_project"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/ico/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_project->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuLanguage->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout_program);
        toolBar->addAction(actionAdd_project);
        toolBar->addSeparator();
        toolBar->addAction(actionEdit_project);
        toolBar->addSeparator();
        toolBar->addAction(actionDelete_project);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAbout_program->setText(QCoreApplication::translate("MainWindow", "About program", nullptr));
        actionAdd_project->setText(QCoreApplication::translate("MainWindow", "Add project", nullptr));
        actionEdit_project->setText(QCoreApplication::translate("MainWindow", "Edit project", nullptr));
        actionDelete_project->setText(QCoreApplication::translate("MainWindow", "Delete project", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
