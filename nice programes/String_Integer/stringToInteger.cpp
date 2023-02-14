#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void error(std::string msg);

int stringToInteger(string str){
    istringstream stream(str);
    int value;
    stream >> value >> ws;
    if (stream.fail() || !stream.eof()){
        error("stringToInteger: Illegal integer format");
    }
    return value;
}

void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}