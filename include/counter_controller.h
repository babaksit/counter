//
// Created by bsi on 22.01.23.
//

#ifndef COUNTER_CONTROLLER_H
#define COUNTER_CONTROLLER_H

#include <memory>

#include "counter_view.h"
#include "counter_model.h"



/**
* @class CounterController
* @brief Abstract base class for character counting controllers
* This class defines the interface for character counting controllers, which are responsible for
* displaying the count of a specific character in a given string. The class is abstract and cannot
* be instantiated.
**/
class CounterController {
protected:
/**
@brief Virtual destructor
The virtual destructor ensures that the correct destructor is called for objects of derived classes.
**/
virtual ~CounterController() = default;
/**
* @brief Display character count
* This pure virtual function must be implemented by derived classes to display the count of a specific
* character in a given string.
* @param str The const reference of string view to count characters in
* @param ch The const reference of character to count in the string
**/
virtual void display_char_count(const std::string_view& str,const char& ch) = 0;
};
/**
* @class CounterConsoleController
* @brief Concrete class for character counting controllers in console applications
* This class is a concrete implementation of the CounterController interface, designed for use in console applications.
* It uses a shared pointer to a CounterConsoleModel and a CounterConsoleView.
*/
class CounterConsoleController : public CounterController{
public:
/**
@brief Constructor
* The constructor takes in shared pointers to a CounterConsoleModel and a CounterConsoleView.
* @param model The shared pointer to the CounterConsoleModel
* @param view The shared pointer to the CounterConsoleView
*/
CounterConsoleController(const std::shared_ptr<CounterConsoleModel> &model,
const std::shared_ptr<CounterConsoleView> &view);
/**
* @brief Destructor
* The destructor is overridden to ensure that the correct destructor is called for objects of this class.
*/
~CounterConsoleController() override = default;
/**
* @brief Display character count
* This function is the concrete implementation of the pure virtual function defined in the base class.
* It uses the model and view to display the count of a specific character in a given string.
* @param str The const reference of string view to count characters in
* @param ch The const reference of character to count in the string
*/
void display_char_count(const std::string_view& str, const char& ch) override;
private:
/**
* @brief Shared pointer to a CounterConsoleModel
*/
std::shared_ptr<CounterConsoleModel> model_;
/**
* @brief Shared pointer to a CounterConsoleView
*/
std::shared_ptr<CounterConsoleView> view_;
};


#endif //COUNTER_CONTROLLER_H
