#include "MatrixCalculation/lib/matrix.h"
#include "MatrixCalculation/matrix_calculator.h"

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <map>

void calculate() {
    std::map<std::string, uint32_t> command_dictionary = {{"add", 0},
                                                          {"sub", 1},
                                                          {"mul", 2}};
    std::string user_command;
    std::cout << "Enter command for calculation:" << std::endl;
    std::cout << "Matrix Multiplication: mul" << std::endl;
    std::cout << "Matrix Addition: add" << std::endl;
    std::cout << "Matrix Subtraction: sub" << std::endl;
    std::cin >> user_command;
    user_command.erase(0, user_command.find_first_not_of(" \t\n\r\f\v"));
    user_command.erase(user_command.find_last_not_of(" \t\n\r\f\v") + 1);
    std::transform(user_command.begin(), user_command.end(), user_command.begin(), ::tolower);

    // Keep looping until user enter a valid respond
    while (true) {
        if (command_dictionary.count(user_command) > 0) break;
        std::cout << "Invalid Command, Enter correct command for calculation:" << std::endl;
        user_command.clear();
        std::cin >> user_command;
        user_command.erase(0, user_command.find_first_not_of(" \t\n\r\f\v"));
        user_command.erase(user_command.find_last_not_of(" \t\n\r\f\v") + 1);
        std::transform(user_command.begin(), user_command.end(), user_command.begin(), ::tolower);
    }

    uint32_t command_code = command_dictionary[user_command];
}

