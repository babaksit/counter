//
// Created by bsi on 22.01.23.
//

#ifndef COUNTER_INPUT_READER_H
#define COUNTER_INPUT_READER_H

#include <tuple>
#include <iostream>

/**
* @class InputReader
* @brief Abstract base class for input reading
* This class defines the interface for input reading, which is responsible for
* reading input from the user. The class is abstract and cannot be instantiated.
*/
class InputReader {
public:
/**
* @brief Read input
* This pure virtual function must be implemented by derived classes to read input from the user.
* @return The input read from the user as a string
*/
virtual std::string read_input() = 0;
/**
* @brief Virtual destructor
* The virtual destructor ensures that the correct destructor is called for objects of derived classes.
*/
virtual ~InputReader() = default;
};



/**
* @class ConsoleInputReader
* @brief Concrete class for input reading from console
* This class is a concrete implementation of the InputReader interface, designed for reading input from console.
* It inherits from the InputReader abstract base class and provides a concrete implementation for the read_input function.
*/
class ConsoleInputReader : public InputReader {
public:
/**
* @brief Read input from console
* This function is the concrete implementation of the pure virtual function defined in the base class.
* It reads input from the console and returns it as a string.
* @return The input read from the console as a string
*/
std::string read_input() override;
};

#endif //COUNTER_INPUT_READER_H
