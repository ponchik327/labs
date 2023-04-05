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

std::istream& operator >>(std::istream& is, Book& b) {
    int id, pages, year;
    std::string name, author;
    is >> id >> name >> author >> pages >> year;
    b = Book(id, name, author, pages, year);
    return is;
}

std::ostream& operator <<(std::ostream& os, Book b) {
    os << b.id << "," << b.name << "," << b.author << "," << b.pages << "," << b.year;
    return os;
}

bool operator ==(const Book& b1, const Book& b2) {
    return b1.name == b2.name;
}

bool operator <(const Book& b1, const Book& b2) {
    return b1.year < b2.year;
}

/*operator bool () {
    if () {

    }
    return true;
}*/
