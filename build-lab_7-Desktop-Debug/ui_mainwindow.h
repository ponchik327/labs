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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *SearchEdit;
    QPushButton *pushButton;
    Result *TextBrowser;
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        SearchEdit = new QLineEdit(centralwidget);
        SearchEdit->setObjectName(QString::fromUtf8("SearchEdit"));

        horizontalLayout->addWidget(SearchEdit);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        TextBrowser = new Result(centralwidget);
        TextBrowser->setObjectName(QString::fromUtf8("TextBrowser"));

        gridLayout->addWidget(TextBrowser, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Id = new QLineEdit(centralwidget);
        Id->setObjectName(QString::fromUtf8("Id"));

        horizontalLayout_2->addWidget(Id);

        Name = new QLineEdit(centralwidget);
        Name->setObjectName(QString::fromUtf8("Name"));

        horizontalLayout_2->addWidget(Name);

        Autor = new QLineEdit(centralwidget);
        Autor->setObjectName(QString::fromUtf8("Autor"));

        horizontalLayout_2->addWidget(Autor);

        Pages = new QLineEdit(centralwidget);
        Pages->setObjectName(QString::fromUtf8("Pages"));

        horizontalLayout_2->addWidget(Pages);

        Year = new QLineEdit(centralwidget);
        Year->setObjectName(QString::fromUtf8("Year"));

        horizontalLayout_2->addWidget(Year);

        add = new QPushButton(centralwidget);
        add->setObjectName(QString::fromUtf8("add"));

        horizontalLayout_2->addWidget(add);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

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
        SearchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "example", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        Id->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        Name->setPlaceholderText(QCoreApplication::translate("MainWindow", "NAME", nullptr));
        Autor->setPlaceholderText(QCoreApplication::translate("MainWindow", "AUTHOR", nullptr));
        Pages->setPlaceholderText(QCoreApplication::translate("MainWindow", "PAGE", nullptr));
        Year->setPlaceholderText(QCoreApplication::translate("MainWindow", "YEAR", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
