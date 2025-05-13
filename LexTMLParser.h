// LexTMLParser.h
#ifndef LEXTML_PARSER_H
#define LEXTML_PARSER_H

#include <string>
#include <vector>
#include <map>

struct LexTML {
    std::string emotion;
    int intensity;
    char nuance;
    int expression;
    std::string symbolicGesture;
    std::string target;
    std::vector<std::string> modifiers;
};

LexTML parseLexTML(const std::string& tml);

#endif
