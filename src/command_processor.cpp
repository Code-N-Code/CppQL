//
// Created by Waqar Ahmad on 9/7/2025.
//

#include "../include/command_processor.h"
#include <iostream>

bool CommandProcessor::process(const std::string& query) {
    // For now, just echo query
    if (query == ".exit\n" || query == ".exit;\n") {
        std::cout << "Exiting CppQL. Goodbye!" << std::endl;
        return false;
    }

    std::cout << "[DEBUG] Received Query:\n" << query << std::endl;
    return true;
}