#include "result.h"

Result::Result(QWidget *parent)
    : QTextBrowser(parent)
{

}

void Result::RedOutput(const QString & text)
{
    QColor old_color = this->textColor();
    this->setTextColor(QColor(Qt::red));
    this->append(text);
    this->setTextColor(old_color);
}

void Result::GreenOutput(const QString & text)
{
    QColor old_color = this->textColor();
    this->setTextColor(QColor(Qt::green));
    this->append(text);
    this->setTextColor(old_color);
}
