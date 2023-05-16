#include "csvwriter.h"
#include <ios>

csvwriter::csvwriter(const std::string& fname)
{
    fout.open(fname, std::ios_base::out | std::ios_base::app);
}

bool csvwriter::is_open() const
{
    return fout.is_open();
}

void csvwriter::writeBook(const Book& b)
{
    if(!fout.is_open())
    {
        std::cout << "Error! File is not open" << std::endl;
    } else {
        fout << std::endl << b;
    }
    fout.close();
}
