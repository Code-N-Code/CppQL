//
// Created by Waqar Ahmad on 9/12/2025.
//

#include "tokenizer/tokenizer.h"
#include <cctype>
#include <stdexcept>
#include <unordered_map>

// Initialize keywords
const std::unordered_map<std::string, TokenType> Tokenizer::keywords = {
    {"CREATE", TokenType::CREATE},
    {"TABLE", TokenType::TABLE},
    {"INSERT", TokenType::INSERT},
    {"INTO", TokenType::INTO},
    {"SELECT", TokenType::SELECT},
    {"FROM", TokenType::FROM},
    {"VALUES", TokenType::VALUES},
    {"INT", TokenType::INT},
    {"DOUBLE", TokenType::DOUBLE},
    {"TEXT", TokenType::TEXT}
};

// Constructor
Tokenizer::Tokenizer(const std::string& input) : input(input), position(0) {}

// Main tokenization function
std::vector<Token> Tokenizer::tokenize() {
    std::vector<Token> tokens;

    while (position < input.size()) {
        skipWhitespace();
        if (position >= input.size()) break;

        const char c = currentChar();

        if (std::isalpha(c) || c == '_') {
            tokens.push_back(readIdentifier());
        } else if (std::isdigit(c)) {
            tokens.push_back(readNumber());
        } else {
            switch (c) {
                case '\'':
                    tokens.push_back(readString());
                    break;
                case '(':
                    tokens.emplace_back(TokenType::LPAREN, "(");
                    position++;
                    break;
                case ')':
                    tokens.emplace_back(TokenType::RPAREN, ")");
                    position++;
                    break;
                case ',':
                    tokens.emplace_back(TokenType::COMMA, ",");
                    position++;
                    break;
                case ';':
                    tokens.emplace_back(TokenType::SEMICOLON, ";");
                    position++;
                    break;
                case '*':
                    tokens.emplace_back(TokenType::STAR, "*");
                    position++;
                    break;
                default:
                    // Unknown character
                    tokens.emplace_back(TokenType::UNKNOWN, std::string(1, c));
                    position++;
            }
        }
    }

    tokens.emplace_back(TokenType::END);
    return tokens;
}

// Helper methods
char Tokenizer::currentChar() const {
    return position < input.size() ? input[position] : '\0';
}

char Tokenizer::nextChar() {
    return position < input.size() ? input[position++] : '\0';
}

void Tokenizer::skipWhitespace() {
    while (position < input.size() && std::isspace(currentChar())) {
        position++;
    }
}

Token Tokenizer::readString() {
    std::string value;
    position++; // Skip opening quote
    while (position < input.size() && currentChar() != '\'') {
        value += nextChar();
    }
    position++; // Skip closing quote
    return Token(TokenType::STRING, value);
}

Token Tokenizer::readNumber() {
    std::string value;
    while (position < input.size() && (std::isdigit(currentChar()) || currentChar() == '.')) {
        value += nextChar();
    }
    // Check if the next character is alphabetic (invalid identifier starting with digit)
    if (position < input.size() && std::isalpha(currentChar())) {
        // Read the rest of the invalid identifier
        while (position < input.size() && (std::isalnum(currentChar()) || currentChar() == '_')) {
            value += nextChar();
        }
        // Return an error token instead of a number token
        return Token(TokenType::UNKNOWN, value);
    }
    return Token(TokenType::NUMBER, value);
}

Token Tokenizer::readIdentifier() {
    std::string value;
    while (position < input.size() && (std::isalnum(currentChar()) || currentChar() == '_')) {
        value += nextChar();
    }

    // Check if it's a keyword
    auto it = keywords.find(value);
    if (it != keywords.end()) {
        return Token(it->second, value);
    }
    return Token(TokenType::IDENTIFIER, value);
}
