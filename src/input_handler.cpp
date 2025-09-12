//
// Created by Waqar Ahmad on 9/7/2025.
//

#include "../include/input_handler.h"
#include <iostream>
#include <sstream>

std::string InputHandler::readMultiLine() {
    std::ostringstream buffer;
    std::string line;

    std::cout << "CppQL> "; // prompt

    while (std::getline(std::cin, line)) {
        buffer << line << "\n";
        if (!line.empty() && line.back() == ';') {
            break; // end of the query.
        }
        std::cout << "   -> "; // continuation prompt
    }

    return buffer.str();
}