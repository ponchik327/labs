#ifndef BOOK_H
#define BOOK_H

#include<string>
#include <QString>
#include <sstream>

class Book
{
public:
    Book() = default;
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

std::istream& operator >>(std::istream& is, Book b) ;

std::ostream& operator <<(std::ostream& os, Book b) ;

bool operator ==(const Book& b1, const Book& b2);

bool operator <(const Book& b1, const Book& b2);

//operator bool ();

#endif // BOOK_H
