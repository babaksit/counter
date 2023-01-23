//
// Created by bsi on 22.01.23.
//
#include "../include/counter_controller.h"

CounterConsoleController::CounterConsoleController(const std::shared_ptr<CounterConsoleModel>& model,
                                     const std::shared_ptr<CounterConsoleView>& view) : model_(model),view_(view)
{

}

void CounterConsoleController::display_char_count(const std::string_view &str, const char &ch)
{
    auto count= model_->count_char(str, ch);
    view_->display_char_count(ch, count);
}

