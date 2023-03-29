//
// Created by Gabby Barcinas on 5/14/21.
//

#ifndef BATTLESHIPMASTER_INPUTVALIDATION_H
#define BATTLESHIPMASTER_INPUTVALIDATION_H
#include <iostream>

bool StreamOnlyContainsWhiteSpace(std::istream& stream);
std::string no_white_space(const std::string &user_input);
int getValidInt(const std::string& prompt);
std::string toLower(std::string word);
int getValidChar(const std::string& prompt);


#endif //BATTLESHIPMASTER_INPUTVALIDATION_H
