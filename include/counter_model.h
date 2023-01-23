//
// Created by bsi on 22.01.23.
//

#ifndef COUNTER_MODEL_H
#define COUNTER_MODEL_H

#include <string_view>
#include <algorithm>


/**
* @class CounterModel
* @brief Abstract base class for character counting models
* This class defines the interface for character counting models, which are responsible for
* counting the occurrences of a specific character in a given string. The class is abstract and cannot
* be instantiated.
*/
class CounterModel {
public:
/**
* @brief Virtual destructor
* The virtual destructor ensures that the correct destructor is called for objects of derived classes.
*/
    virtual ~CounterModel() = default;
protected:
/**
* @brief Count character occurrences
* This pure virtual function must be implemented by derived classes to count the occurrences of a specific
* character in a given string.
* @param str The const reference of string view to count characters in
* @param ch The const reference of character to count in the string
* @return The number of times the character occurs in the string
*/
virtual long count_char(const std::string_view& str, const char& ch) = 0;

};

/**

*@class CounterConsoleModel
* @brief Concrete class for character counting models in console applications
* It inherits from the CounterModel abstract base class and provides a concrete implementation for the count_char function.
*/
class CounterConsoleModel : public CounterModel{
public:
/**
* @brief Default constructor
* The default constructor has no parameters
*/
CounterConsoleModel() = default;
/**
* @brief Count character occurrences
* This function is the concrete implementation of the pure virtual function defined in the base class.
* It counts the occurrences of a specific character in a given string.
* @param str The const reference of string view to count characters in
* @param ch The const reference of character to count in the string
* @return The number of times the character occurs in the string
*/
long count_char(const std::string_view& str,const char& ch) override;
/**
* @brief Destructor
* The destructor is overridden to ensure that the correct destructor is called for objects of this class.
*/
~CounterConsoleModel() override = default;
};

#endif //COUNTER_MODEL_H
