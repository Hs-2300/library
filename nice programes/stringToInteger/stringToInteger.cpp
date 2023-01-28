#include <iostream>
#include <cctype>
#include <string>
#include "stringToInteger.h"

/*
 * Function name: stringToInteger
 * -------------------------------------
 * Usage: for formated input, string str with length len,
 * has (len-1) digits.    From str[0] to str[len-1] are 
 * digits.
 * -------------------------------------
 */
int stringToInteger(std::string str){
    if (str == "") return 0;
    int len = str.length();
    for (int i = 0; i < len; i++){
        if (!isdigit(str[i])) return 0;
    }
    return stoi(str);
}
