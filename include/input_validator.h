//
// Created by bsi on 22.01.23.
//

#ifndef COUNTER_INPUT_VALIDATOR_H
#define COUNTER_INPUT_VALIDATOR_H

#include <vector>
#include <memory>

/**
* @class StringCharValidator
* @brief Abstract base class for string and character validation
* This class defines the interface for validating a given string and character. The class is abstract and cannot be instantiated.
*/
class StringCharValidator {
public:
/**
* @brief Validate the string and character
* This pure virtual function must be implemented by derived classes to validate the given string and character.
* @param str The const reference of string to be validated
* @param ch The const reference of character to be validated
*/
virtual void validate(const std::string_view& str,const char& ch) = 0;
/**
* @brief Virtual destructor
* The virtual destructor ensures that the correct destructor is called for objects of derived classes.
*/
virtual ~StringCharValidator() = default;
};


/**
* @class CounterInputValidator
* @brief Class for validating input for character counting
* This class is responsible for validating input for character counting, it takes a string and a character as input and
* runs it through a list of validators_ that are responsible for checking the input for specific conditions.
*/
class CounterInputValidator {

public:
/**
* @brief add a validator
* This function adds a unique pointer of StringCharValidator to the vector of validators_
* @param validator the validator to be added
*/
void add_validator(std::unique_ptr<StringCharValidator> validator);
/**
* @brief validate the input
* This function takes in a string and character and runs it through all the validators_ in the vector
* @param str The const reference of string to be validated
* @param ch The const reference of character to be validated
*/
void validate(const std::string_view& str,const char& ch);

private:
/**
* @brief Vector of unique pointers to StringCharValidator objects
*/
    std::vector<std::unique_ptr<StringCharValidator>> validators_;
};

/**
* @class EmptyStringValidator
* @brief Concrete class for validating empty strings
* This class is a concrete implementation of the StringCharValidator interface, designed for validating empty strings.
* It inherits from the StringCharValidator abstract base class and provides a concrete implementation for the validate function.
*/
class EmptyStringValidator : public StringCharValidator {
public:
/**
* @brief Validate the string
* This function is the concrete implementation of the pure virtual function defined in the base class.
* It checks if the given string is empty, if it is it throws an exception.
* @param str The const reference of string to be validated
* @param ch The const reference of character to be validated
*/
void validate(const std::string_view& str,const char& ch) override;
};

/**
* @class NullCharacterValidator
* @brief Concrete class for validating null characters
* This class is a concrete implementation of the StringCharValidator interface, designed for validating null characters.
* It inherits from the StringCharValidator abstract base class and provides a concrete implementation for the validate function.
*/
class NullCharacterValidator : public StringCharValidator {
public:
/**
* @brief Validate the character
* This function is the concrete implementation of the pure virtual function defined in the base class.
* It checks if the given character is a null character, if it is it throws an exception.
* @param str The const reference of string to be validated
* @param ch The const reference of character to be validated
*/
void validate(const std::string_view& str, const char& ch) override;
};

#endif //COUNTER_INPUT_VALIDATOR_H
