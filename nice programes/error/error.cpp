/*
 *File:error.cpp
 *---------------
 *This file implements the error.h interface
 */

#include <iostream> //cerr,endl
#include <cstdlib>  //exit.EXIT_FAILURE
#include <string>  //string
#include "error.h"
using namespace std;

/*this function write about the erro message to the cerr stream and then
 *exists the program.The EXIT_FALURE constant is defined in
 * <cstlib> to represent a standart failure code. */
void error(string msg){
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}