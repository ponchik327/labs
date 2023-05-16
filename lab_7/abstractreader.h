#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H

#include<fstream>
#include<string>
#include<vector>
#include<tuple>
#include"book.h"
#include"csv_exception.h"

class AbstractReader {

public:
    virtual bool is_open() const = 0;
    virtual std::tuple<std::vector<Book>, csv_exception> readAll() = 0;
};

#endif // ABSTRACTREADER_H
