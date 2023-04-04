#include "jsonreader.h"
#include "single_include/nlohmann/json.hpp"
#include <iostream>

JsonReader::JsonReader(const std::string& fname)
{
    fin.open(fname);
}

bool JsonReader::is_open() const
{
    return fin.is_open();
}

std::vector<Book> JsonReader::readAll()
{
    std::vector<Book> result;

    nlohmann::json json;
    fin >> json;
    fin.close();

    for(const auto & j: json) {
            Book b;

            b.id = j["id"];
            b.name = j["name"];
            b.author = j["author"];
            b.pages = j["pages"];
            b.year = j["year"];

            result.push_back(b);
        }

   return result;
}

