//
// Created by bsi on 22.01.23.
//
#include "../include/counter_model.h"

long CounterConsoleModel::count_char(const std::string_view &str, const char &ch) {
    return std::count(str.begin(), str.end(), ch);
}

