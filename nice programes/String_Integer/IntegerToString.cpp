#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void error(std::string msg);

string integerToString(int n){
    ostringstream stream;
    stream << n;
    return stream.str();
}

void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}
