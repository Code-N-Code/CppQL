//
// Created by Waqar Ahmad on 9/12/2025.
//

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Token.h"
#include <vector>
#include <string>
#include <unordered_map>

class Tokenizer {
public:
    explicit Tokenizer(const std::string& input);
    std::vector<Token> tokenize();

private:
    std::string input;
    size_t position;

    // Helper methods
    char currentChar() const;
    char nextChar();
    void skipWhitespace();
    Token readString();
    Token readNumber();
    Token readIdentifier();

    // Keyword lookup
    static const std::unordered_map<std::string, TokenType> keywords;
};


#endif //TOKENIZER_H
