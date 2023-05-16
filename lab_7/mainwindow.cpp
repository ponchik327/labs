#include <vector>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
#include "abstractreader.h"
#include "csvreader.h"
#include "csvwriter.h"
#include "jsonreader.h"
#include <QString>
#include <QFileDialog>
#include <iostream>
#include <type_traits>

void MainWindow::Initialization(AbstractReader& abs) {
    if (abs.is_open()) {
        try {
            auto [vec, exp] = abs.readAll();
            books = vec;
            if (exp.number != 0) {
              throw exp;
            }
        } catch(const csv_exception& er) {
            ui->TextBrowser->RedOutput(QString(er.what()) + QString(" | string: ") + QString(QString::number(er.number)) + QString(", name_file: ") + er.fname);
        }

    } else {
        std::cout << "error opening file" << std::endl;
    }
}

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
        Initialization(reader);
    }
    if (saf == "csv" || saf == "txt") {
        CSVreader reader(fileName);
        Initialization(reader);
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
          *ui->TextBrowser << books[i];
          error = false;
        }
    }
    ui->SearchEdit->clear();

if (error) {
    ui->TextBrowser->RedOutput(QString("Ошибка"));
}
error = true;

}

template<typename T>
void InitializationField(auto ptr, T& field) {
    if (!ptr->text().isEmpty()) {
        if constexpr (std::is_same_v<int, T>) {
            field = stoi(ptr->text().toStdString());
        }
        if constexpr (std::is_same_v<std::string, T>) {
            field = ptr->text().toStdString();
        }
        ptr->clear();
    }
}

void MainWindow::Add()
{
    Book b;

    InitializationField(ui->Id, b.id);
    InitializationField(ui->Name, b.name);
    InitializationField(ui->Autor, b.author);
    InitializationField(ui->Pages, b.pages);
    InitializationField(ui->Year, b.year);

    if (!b.empty()) {
        books.push_back(b);
        csvwriter writer(fileName);
        writer.writeBook(b);
    }

}
