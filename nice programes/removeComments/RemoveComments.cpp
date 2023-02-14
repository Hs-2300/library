/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <fstream>//
#include <iomanip>
#include "csc300222fall/assignment1/lib.h" //for local
#include "csc300222fall/assignment1/RemoveComments.h" //for OJ
using namespace std;

// #pragma GCC diagnostic ignored "-Wcomment"

/* function prototype*/
void removeComments(istream & is, ostream & os);

/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

/* variables: line, status
 * ---------------------------------------------
 * line = "":The line has been processed.
 * 
 * status = 1: the progress finished. Ready for new loop.
 * status = 2: the /** / case is still looking for "* /".
 * 
 * 
 * flag =true: the first time to use while loop in status 2
 */
void removeComments(istream & is, ostream & os) {
    string line="";
    /* status 1: normal state
     * status 2: finding /** / match*/
    int status = 1;
    /*true: the first time to cuse while loop in status 2*/
    bool flag = false;
    while (true) {
        if (line == ""){
                // cout << "line finished."<<endl;//
                getline(is, line);
                // cout << "getline()"<<endl;//
                if (is.fail()) break;
            }
        /* status 1 */
        if (status==1){
            // cout << "switch to STATUS 1" << endl;//
            int i = line.find("//");
            int j = line.find("/*");
            //normal
            if (i == -1 && j == -1) {
                // os << "----------No comments.----------" << endl;//
                os << line << endl;
                line = "";
            }
            //
            else if ((j == -1) || ((i!=-1)&&(j!=-1)&&(i < j))) {
                // os << "----------// style----------" <<endl;//
                string out = line.substr(0,i);
                if ( out !="") {
                    os << out << endl; 
                    }
                line = "";
            }
            /**/
            else if ((i == -1) || ((i!=-1)&&(j!=-1)&&(j < i))) {
                // os << "----------/* style----------"<<endl;//
                string out = line.substr(0,j); //output latter
                os << out;
                // if (out != "") os << out;
                line = line.substr(j+2);
                status=2;
                flag = true;
            }

            // else os<<"----------Unexpected----------";
        }
        /* Looking for "* /" */
        if (status==2){
            // cout << "switch to STATUS 2"<< endl;//
            int i = line.find("*/");
            //本行无 "*/"
            if (i == -1){
                // cout << "Comment lasts" << endl;//
                if (flag) os << endl;
                flag = false;
                line = "";
            }
            //本行有 "*/"
            else {
                // cout << "Comment ends.(*/ found)"<<endl;
                line = line.substr(i+2);
                status = 1;
                if (line =="") os << endl;
                // if (line =="") getline(is,line);
            }
        }

    }
    // cout << "----------------------------\n\
    //     All process done." << endl;
}




void TestRemoveComments(){
    ifstream infile;
    ofstream outfile;
    promptUserForFile(infile,"Input file: ");
    promptUserForFile(outfile,"Output file: ");
    removeComments(infile, outfile);
    infile.close();
    outfile.close();

    // removeComments(cin,cout);

    cout << "done.";
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}
