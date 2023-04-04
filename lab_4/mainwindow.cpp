#include <vector>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include "csvreader.h"
#include "csvwriter.h"
#include <QString>
#include <QFileDialog>
#include <iostream>

void MainWindow::File()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "C:/oop/labs/build-lab_1-Desktop-Debug", tr("books (*.csv);;books (*.txt)"));
    std::string str = filename.toStdString();
    fileName = str.substr(str.rfind("/") + 1);
    CSVreader reader(fileName);
    if (reader.is_open())
    {
        books = reader.readAll();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    File();
    CSVreader reader(fileName);
    if (reader.is_open())
    {
        books = reader.readAll();
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Search()
{
    for(uint i = 0; i < books.size(); i++){
        if (ui->SearchEdit->text().toStdString() == books[i].name){
          ui->TextBrowser->append(books[i].to_string());
          //ui->TextBrowser->RedOutput(QString("%1, %2").arg(QString::fromStdString(books[i].name)). arg(books[i].year));
          //ui->TextBrowser->GreenOutput(QString("%1, %2").arg(QString::fromStdString(books[i].name)). arg(books[i].year));
        }
    }
    ui->SearchEdit->clear();
}

void MainWindow::Add()
{
    csvwriter writer(fileName);
    int id = stoi(ui->Id->text().toStdString());
    ui->Id->clear();
    std::string name = ui->Name->text().toStdString();
    ui->Name->clear();
    std::string autor = ui->Autor->text().toStdString();
    ui->Autor->clear();
    int pages = stoi(ui->Pages->text().toStdString());
    ui->Pages->clear();
    int year = stoi(ui->Year->text().toStdString());
    ui->Year->clear();
    books.push_back(writer.writeBook(id, name, autor, pages, year));
}
