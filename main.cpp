#include <memory>
#include "include/counter_model.h"
#include "include/counter_view.h"
#include "include/counter_controller.h"
#include "include/input_validator.h"
#include "include/input_reader.h"

int main() {

    auto model = std::make_shared<CounterConsoleModel>();
    auto view = std::make_shared<CounterConsoleView>();
    auto controller = CounterConsoleController(model, view);

    CounterInputValidator input_validator;

    input_validator.add_validator(std::make_unique<EmptyStringValidator>());
    input_validator.add_validator(std::make_unique<NullCharacterValidator>());

    ConsoleInputReader input_reader;
    auto str = input_reader.read_input();
    constexpr auto ch = 'I';
    try {
        input_validator.validate(str, ch);
    }
    catch (const std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    controller.display_char_count(str, ch);
    return 0;
}
