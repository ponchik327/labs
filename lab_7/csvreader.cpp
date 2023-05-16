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
    : fname_(fname)
{
    fin.open(fname);
}

bool CSVreader::is_open() const
{
    return fin.is_open();
}

 std::tuple<std::vector<Book>, csv_exception> CSVreader::readAll()
{
    std::vector <Book> books;
    int str_num = 1;
    if (fin.is_open()){
           while(!fin.eof()){
               std::string str;
               getline(fin, str);
               auto tokens = split(str,',');
               try {
                   Book c(stoi(tokens[0]), tokens[1], tokens[2], stoi(tokens[3]), stoi(tokens[4]));
                   books.push_back(c);
               } catch(std::invalid_argument& er) {
                   return {books, csv_exception("data filling error", str_num, fname_)};
               }

            ++str_num;
} }
    return {books, csv_exception("")};
}



