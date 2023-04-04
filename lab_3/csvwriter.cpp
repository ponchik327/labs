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

Book csvwriter::writeBook(int id, const std::string& name, const std::string& autor, int pages, int year)
{
    if(!fout.is_open())
    {
        std::cout << "Error! File is not open" << std::endl;
    } else {
        fout << std::endl << id << "," << name << "," << autor << "," << pages << "," << year;
    }
    fout.close();
    return {id, name, autor, pages, year};
}
