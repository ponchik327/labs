#ifndef CSVREADER_H
#define CSVREADER_H

#include<fstream>
#include<string>
#include<vector>

#include"book.h"

class CSVreader
{
public:
    CSVreader(const std::string& fname);
    bool is_open() const;
    std::vector<Book> readAll();

private:
    std::ifstream fin;
};

#endif // CSVREADER_H
