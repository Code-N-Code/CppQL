//
// Created by Waqar Ahmad on 9/7/2025.
//

#include "../include/repl.h"
#include "../include/input_handler.h"
#include "../include/command_processor.h"
#include <iostream>

void REPL::start() {
    InputHandler inputHandler;
    CommandProcessor processor;

    std::cout << "Welcome to CppQL v0.1 (type .help for help)" << std::endl;

    while (true) {
        std::string query = inputHandler.readMultiLine();

        if (query.empty()) continue;

        if (!processor.process(query)) {
            break; // processor returned false → exit
        }
    }
}
