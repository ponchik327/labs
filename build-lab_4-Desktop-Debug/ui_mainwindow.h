/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "result.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Result *TextBrowser;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *SearchEdit;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *Id;
    QLineEdit *Name;
    QLineEdit *Autor;
    QLineEdit *Pages;
    QLineEdit *Year;
    QPushButton *add;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TextBrowser = new Result(centralwidget);
        TextBrowser->setObjectName(QString::fromUtf8("TextBrowser"));
        TextBrowser->setGeometry(QRect(45, 100, 711, 401));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 50, 701, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        SearchEdit = new QLineEdit(horizontalLayoutWidget);
        SearchEdit->setObjectName(QString::fromUtf8("SearchEdit"));

        horizontalLayout->addWidget(SearchEdit);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(60, 449, 681, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Id = new QLineEdit(horizontalLayoutWidget_2);
        Id->setObjectName(QString::fromUtf8("Id"));

        horizontalLayout_2->addWidget(Id);

        Name = new QLineEdit(horizontalLayoutWidget_2);
        Name->setObjectName(QString::fromUtf8("Name"));

        horizontalLayout_2->addWidget(Name);

        Autor = new QLineEdit(horizontalLayoutWidget_2);
        Autor->setObjectName(QString::fromUtf8("Autor"));

        horizontalLayout_2->addWidget(Autor);

        Pages = new QLineEdit(horizontalLayoutWidget_2);
        Pages->setObjectName(QString::fromUtf8("Pages"));

        horizontalLayout_2->addWidget(Pages);

        Year = new QLineEdit(horizontalLayoutWidget_2);
        Year->setObjectName(QString::fromUtf8("Year"));

        horizontalLayout_2->addWidget(Year);

        add = new QPushButton(horizontalLayoutWidget_2);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        pushButton_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(Search()));
        QObject::connect(add, SIGNAL(clicked()), MainWindow, SLOT(Add()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(File()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
