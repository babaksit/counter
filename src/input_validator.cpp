//
// Created by bsi on 22.01.23.
//

#include "../include/input_validator.h"

void CounterInputValidator::add_validator(std::unique_ptr <StringCharValidator> validator) {
    validators_.push_back(std::move(validator));
}

void CounterInputValidator::validate(const std::string_view &str, const char &ch) {
    for(auto const & validator : validators_) {
        validator->validate(str,ch);
    }
}

void EmptyStringValidator::validate(const std::string_view &str, const char &ch) {
    if(str.empty()) {
        throw std::invalid_argument("string is empty");
    }
}

void NullCharacterValidator::validate(const std::string_view &str, const char &ch) {
    if(ch == '\0') {
        throw std::invalid_argument("character is null");
    }
}
