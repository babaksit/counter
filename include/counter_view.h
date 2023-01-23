//
// Created by bsi on 22.01.23.
//

#ifndef COUNTER_VIEW_H
#define COUNTER_VIEW_H
#include <iostream>

/**
* @class CounterView
* @brief Abstract base class for character counting views
* This class defines the interface for character counting views, which are responsible for
* displaying the count of a specific character. The class is abstract and cannot be instantiated.
*/
class CounterView {
protected:
/**
* @brief Display character count
* This pure virtual function must be implemented by derived classes to display the count of a specific
* character.
* @param ch const reference to the character to display the count for
* @param count const reference to the number of times the character occurs
*/
virtual void display_char_count(const char& ch, const long& count) = 0;
/**
* @brief Virtual destructor
* The virtual destructor ensures that the correct destructor is called for objects of derived classes.
*/
virtual ~CounterView() = default;
};

/**
* @class CounterConsoleView
* @brief Concrete class for character counting views in console applications
* This class is a concrete implementation of the CounterView interface, designed for use in console applications.
* It inherits from the CounterView abstract base class and provides a concrete implementation for the display_char_count function.
*/
class CounterConsoleView : public CounterView{
public:
/**
* @brief Default constructor
* The default constructor has no parameters
*/
CounterConsoleView() = default;
/**
* @brief Display character count
* This function is the concrete implementation of the pure virtual function defined in the base class.
* It displays the count of a specific character in the console.
* @param ch const reference to the character to display the count for
* @param count const reference to the number of times the character occurs
*/
void display_char_count(const char& ch, const long& count) override;
/**
* @brief Destructor
* The destructor is overridden to ensure that the correct destructor is called for objects of this class.
*/
~CounterConsoleView() override = default;
};


#endif //COUNTER_VIEW_H
