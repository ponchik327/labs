#include <vector>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include "csvreader.h"
#include "csvwriter.h"
#include "jsonreader.h"
#include <QString>
#include <QFileDialog>
#include <iostream>

void MainWindow::File()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "C:/oop/labs/build-lab_1-Desktop-Debug", tr("books (*.csv);;books (*.txt);;books (*.json);; all (*.*)"));
    std::string str = filename.toStdString();
    fileName = str.substr(str.rfind("/") + 1);
    QFileInfo suff(filename);
    QString suf = suff.suffix();
    std::string saf = suf.toStdString();
    if (saf == "json") {
        JsonReader reader(fileName);
        if (reader.is_open())
        {
            books = reader.readAll();
        }
    }
    if (saf == "csv" || saf == "txt") {
        CSVreader reader(fileName);
        if (reader.is_open())
        {
            books = reader.readAll();
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    File();
}


MainWindow::~MainWindow()
{
    delete ui;
}

bool error = true;

void MainWindow::Search()
{
    for(uint i = 0; i < books.size(); i++){
        Book b;
        b.name = ui->SearchEdit->text().toStdString();
        if (b == books[i]){
          ui->TextBrowser->append(books[i].to_string());
          error = false;
        }
    }
    ui->SearchEdit->clear();

if (error) {
    ui->TextBrowser->RedOutput(QString("Ошибка"));
}
error = true;

}

void MainWindow::Add()
{
    Book b;
    b.id = stoi(ui->Id->text().toStdString());
    ui->Id->clear();
    b.name = ui->Name->text().toStdString();
    ui->Name->clear();
    b.author = ui->Autor->text().toStdString();
    ui->Autor->clear();
    b.pages = stoi(ui->Pages->text().toStdString());
    ui->Pages->clear();
    b.year = stoi(ui->Year->text().toStdString());
    ui->Year->clear();
    books.push_back(b);
    csvwriter writer(fileName);
    writer.writeBook(b);
}
