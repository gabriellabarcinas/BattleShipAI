//
// Created by Gabby Barcinas on 5/14/21.
//

#include "InputValidation.h"
#include <algorithm>
#include <sstream>
/**
 * Get this from the class tic tac toe drive
 * Check that the stream is empty or contains only white space
 * @param stream: The stream to read from which is modified by the read
 * @return
 */

bool StreamOnlyContainsWhiteSpace(std::istream& stream) {
    char c ='!';
    if(!stream){ //if you can't read from the stream
        return false; //something is wrong with the stream
    }else{
        stream >> c; // attempt to read a nonwhitespace character
        //if the stream is bad it means we failed to read
        //and we should since there shouldn't be anything left
        return !stream;
    }
}

// get this from the class tic tac toe drive
// this function will check if the string is a valid int
int getValidInt(const std::string& prompt) {
    std::string lineRead;
    int val;
    bool readSuccessful;
    do{
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        std::stringstream lineParser(lineRead); //put it into a string stream so we can parse it
        lineParser >> val; //read what we want
        readSuccessful = StreamOnlyContainsWhiteSpace(lineParser); //check that there isn't anything left
    }while(!readSuccessful); //keep asking until they give me what I want

    return val;
}

// function that converts word read from file to lowercase
std::string toLower(std::string word){
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

// base this off the tic tac toe class google drive
// get a valid character
int getValidChar(const std::string& prompt) {
    std::string lineRead;
    char val;
    bool readSuccessful;
    do{
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        std::stringstream lineParser(lineRead); //put it into a string stream so we can parse it
        lineParser >> val; //read what we want
        readSuccessful = StreamOnlyContainsWhiteSpace(lineParser); //check that there isn't anything left
    }while(!readSuccessful); //keep asking until they give me what I want
    return val;
}

// check for no white space
// function removes whitespace chars in the string
std::string no_white_space(const std::string &user_input) {
    auto start = user_input.begin();
    while (start != user_input.end() && std::isspace(*start)) {
        start++;
    }
    auto end = user_input.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}





