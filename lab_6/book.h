#ifndef BOOK_H
#define BOOK_H

#include<string>
#include <QString>
#include <sstream>
#include <result.h>

// class Result;

class Book
{
public:
    Book() = default;
    Book(int, const std::string&, const std::string&, int, int);
    int id;
    std::string name;
    std::string author;
    int pages;
    int year;

public:
    QString to_string();
};

std::ostream& operator <<(std::ostream& os, Book b) ;

bool operator ==(const Book& b1, const Book& b2);


Result& operator <<(Result& result, Book& book);

#endif // BOOK_H
