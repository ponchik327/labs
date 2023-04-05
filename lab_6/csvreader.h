#ifndef CSVREADER_H
#define CSVREADER_H

#include<fstream>
#include<string>
#include<vector>
#include"abstractreader.h"
#include"book.h"

class CSVreader : public AbstractReader
{
public:
    CSVreader(const std::string& fname);
    bool is_open() const override;
    std::vector<Book> readAll() override;

private:
    std::ifstream fin;
};

#endif // CSVREADER_H
