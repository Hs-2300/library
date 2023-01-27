#include <iostream>
#include <fstream>
#include <string>
#include "promptUserForFile.h"
using namespace std;

/*
 * Function: promptUserForFile
 * Usage: string filename = promptUserForFile(infile,prompt);
 * Ask the user for the name of an input file and opens the reference
 * parameter infile using tat name, which is returned as a result of 
 * the function.    If the requested file does not exist, the user is 
 * given additional chances to enter a valid file name. The optional 
 * prompt argument is used to give the user more information about the 
 * desired input file.
 */

string promptUserForFile(ifstream & infile, string prompt){
    while (true){
        cout << prompt;
        string filename;
        getline(cin,filename);
        infile.open(filename.c_str());
        if (!infile.fail()) return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if (prompt == "") prompt = "Input file: ";
    }
}