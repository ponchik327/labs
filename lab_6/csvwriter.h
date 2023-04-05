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
    void writeBook(const Book&);

private:
    std::ofstream fout;
};

#endif // CSVWRITER_H
