//
// Created by bsi on 22.01.23.

#include "../include/counter_view.h"

void CounterConsoleView::display_char_count(const char &ch, const long &count) {
    std::cout << "The character " << ch << " appears " << count << " times in the string." << std::endl;
}
