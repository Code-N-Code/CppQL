cmake_minimum_required(VERSION 3.31)
project(CppQL)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(CppQL
        src/input_handler.cpp
        include/input_handler.h
        src/main.cpp
        src/repl.cpp
        include/repl.h
        src/command_processor.cpp
        include/command_processor.h
        include/tokenizer/Token.h
        include/tokenizer/Tokenizer.h
        src/tokenizer/Tokenizer.cpp)

# Adding include directory for public headers
target_include_directories(CppQL
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)