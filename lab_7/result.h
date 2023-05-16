#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <QTextBrowser>
#include <sstream>

class Result : public QTextBrowser
{
    Q_OBJECT
public:
    Result(QWidget *parent = nullptr);

public slots:
    void RedOutput(const QString & text);
    void GreenOutput(const QString & text);
};

#endif // RESULT_H
