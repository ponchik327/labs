#include<fstream>

#include "csvreader.h"

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end-start)));
            start = end +1;
        } while (end != std::string::npos);
    }

    return tokens;
}

CSVreader::CSVreader(const std::string& fname)
{
    fin.open(fname);
}

bool CSVreader::is_open() const
{
    return fin.is_open();
}

std::vector<Book> CSVreader::readAll()
{
    std::vector <Book> book;
    if (fin.is_open()){
           while(!fin.eof()){
               std::string str;
               getline(fin, str);
               auto tokens = split(str,',');
               Book c;
               c.id = stoi(tokens[0]);
               c.name= tokens[1];
               c.author= tokens[2];
               c.pages = stoi(tokens[3]);
               c.year = stoi(tokens[4]);
               book.push_back(c);

} }
    return book;
}

