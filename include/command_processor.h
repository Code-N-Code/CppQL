//
// Created by Waqar Ahmad on 9/7/2025.
//

#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <string>

class CommandProcessor {
public:
    // returns false if user wants to exit
    bool process(const std::string& query);
};



#endif //COMMAND_PROCESSOR_H
