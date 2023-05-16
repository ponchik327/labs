#ifndef CSVREADER_H
#define CSVREADER_H

#include<fstream>
#include<string>
#include<vector>
#include<exception>
#include<tuple>
#include"abstractreader.h"
#include"book.h"
#include"csv_exception.h"

class CSVreader : public AbstractReader
{
public:
    CSVreader(const std::string& fname);
    bool is_open() const override;
     std::tuple<std::vector<Book>, csv_exception> readAll() override;

private:
    std::ifstream fin;
    std::string fname_;
};

#endif // CSVREADER_H
