#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include<fstream>
#include<string>
#include<vector>
#include"book.h"

class AbstractReader {

public:
    virtual bool is_open() const = 0;
    virtual std::vector<Book> readAll() = 0;
};

#endif // ABSTRACTREADER_H
