#include "book.h"

Book::Book(int id, const std::string& name, const std::string& author, int pages, int year)
    : id(id)
    , name(name)
    , author(author)
    , pages(pages)
    , year(year)
{

}

QString Book::to_string()
{
    return QString("%1, %2").arg(QString::fromStdString(name)).arg(year);
}
