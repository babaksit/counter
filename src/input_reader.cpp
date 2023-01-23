//
// Created by bsi on 22.01.23.
//

#include "../include/input_reader.h"

std::string ConsoleInputReader::read_input() {
    std::string str;
    std::cout << "Enter the string: ";
    std::getline(std::cin, str);
    return str;
}
