#include "jsonreader.h"
#include "single_include/nlohmann/json.hpp"
#include <iostream>

JsonReader::JsonReader(const std::string& fname)
    : fname_(fname)
{
    fin.open(fname);
}

bool JsonReader::is_open() const
{
    return fin.is_open();
}

 std::tuple<std::vector<Book>, csv_exception> JsonReader::readAll()
{
    std::vector<Book> result;

    nlohmann::json json;
    fin >> json;
    fin.close();
    int str_num = 1;
    for(const auto & j: json) {
            Book b;
            try {
                b.id = j["id"];
                b.name = j["name"];
                b.author = j["author"];
                b.pages = j["pages"];
                b.year = j["year"];
            } catch(nlohmann::json_abi_v3_11_2::detail::type_error er) {
                return {result, csv_exception("data filling error", str_num, fname_)};
            }
            ++str_num;
            result.push_back(b);
        }

   return {result, csv_exception("")};
}

