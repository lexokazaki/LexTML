// LexTMLParser.cpp
#include "LexTMLParser.h"
#include <regex>
#include <sstream>

LexTML parseLexTML(const std::string& tml) {
    std::regex pattern("^LX([A-Z]{2})([1-6])([a-z])([1-6])-([a-z]{2}\+[a-z]{2})@([a-zA-Z0-9_]+)((\+[a-z]{2})*)$");
    std::smatch match;
    LexTML result;

    if (std::regex_match(tml, match, pattern)) {
        result.emotion = match[1];
        result.intensity = std::stoi(match[2]);
        result.nuance = match[3].str()[0];
        result.expression = std::stoi(match[4]);
        result.symbolicGesture = match[5];
        result.target = match[6];

        std::string modStr = match[7];
        std::stringstream ss(modStr);
        std::string item;
        while (getline(ss, item, '+')) {
            if (!item.empty()) result.modifiers.push_back(item);
        }
    }

    return result;
}
