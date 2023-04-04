#ifndef BOOK_H
#define BOOK_H

#include<string>
#include <QString>

class Book
{
public:
    Book(int, const std::string&, const std::string&, int, int);

public:
    int id;
    std::string name;
    std::string author;
    int pages;
    int year;

public:
    QString to_string();
};

#endif // BOOK_H
