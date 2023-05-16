#ifndef CSV_EXCEPTION_H
#define CSV_EXCEPTION_H

#endif // CSV_EXCEPTION_H
#include <exception>
#include <string>
#include <QString>
#pragma once

struct csv_exception : public std::invalid_argument {
    csv_exception(const std::string& what_arg)
        : invalid_argument(what_arg)
    {

    }
    csv_exception(const std::string& what_arg, int n, const std::string& f)
        : invalid_argument(what_arg)
        , number{n}
        , fname{QString::fromStdString(f)}
    {
        // empty
    }
    int number = 0;
    QString fname;
};
