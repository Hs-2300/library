#ifndef _error_h
#define _error_h
//#include <string>//这句可以省略吗？可以省略，因为*.cpp一般有。
//using namespace std;//一般不能在headerfile使用，因为*.cpp 一般包含。
void error(std::string msg);

#endif