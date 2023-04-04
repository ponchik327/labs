#ifndef CSVWRITER_H
#define CSVWRITER_H

#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include"book.h"

class csvwriter
{
public:
    csvwriter(const std::string& fname);
    bool is_open() const;
    Book writeBook(int id, const std::string& name, const std::string& autor, int pages, int year);

private:
    std::ofstream fout;
};

#endif // CSVWRITER_H
