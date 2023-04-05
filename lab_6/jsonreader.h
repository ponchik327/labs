#ifndef JSONREADER_H
#define JSONREADER_H

#include<fstream>
#include<string>
#include<vector>
#include"abstractreader.h"
#include"book.h"

class JsonReader : public AbstractReader
{
public:
    JsonReader(const std::string& fname);
    bool is_open() const override;
    std::vector<Book> readAll() override;

private:
    std::ifstream fin;
};

#endif // JSONREADER_H
