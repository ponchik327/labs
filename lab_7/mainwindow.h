#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "csvreader.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void Initialization(AbstractReader&);
    ~MainWindow();
public slots:
    void File();
    void Search();
    void Add();
private:
    Ui::MainWindow *ui;
    std::vector<Book> books;
    std::string fileName;
};
#endif // MAINWINDOW_H
