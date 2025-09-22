//
// Created by Waqar Ahmad on 9/12/2025.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
    // Keywords
    CREATE, TABLE, INSERT, INTO, SELECT, FROM, VALUES,
    INT, DOUBLE, TEXT,

    // Identifiers and literals
    IDENTIFIER, STRING, NUMBER,

    // Symbols
    LPAREN, RPAREN, COMMA, SEMICOLON, STAR,

    // Special
    END, UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;

    explicit Token(const TokenType t, const std::string& v = "") : type(t), value(v) {}
};

#endif //TOKEN_H
