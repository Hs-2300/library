#include <iostream>
#include <string>
#include <fstream>
#include "csc300222fall/assignment1/lib.h" 
using namespace std;

void execute(istream & is, ostream & os);
void recomment(int c, istream & is, ostream & os);
void in_comment(istream & is, ostream & os);
void echo_quote(int c, istream & is, ostream & os);
void start_comment(istream & is, ostream & os);

int main(){
    ifstream infile;
    ofstream outfile;
    promptUserForFile(infile,"Input file: ");
    promptUserForFile(outfile,"Output file: ");

    execute(infile, outfile);

    infile.close();
    outfile.close();

}

void execute(istream & is, ostream & os){
    int c,d;
    while((c=is.get()) != EOF){
        recomment(c,is,os);
    }
}

//搜索注释开始位置
void recomment(int c, istream & is, ostream & os){

    int d;
    if (c =='/'){

        if ((d = is.get()) == '*'){
            in_comment(is,os);
        }
        else if ( d == '/'){
            start_comment(is,os);
        }
        else{
            os.put(c);
            os.put(d);
        }
    }
    else if (c == '\'' || c == '"'){
        echo_quote(c,is,os);
    }
    else{
        os.put(c);
    }
}

//删除以"//"开始的注释
void start_comment(istream & is, ostream & os){
    int c, d;
    while((c = is.get()) !=  '\n');//什么都不做，直到newline
    os.put(c);
}


//删除"/*    */"注释
void in_comment(istream & is, ostream & os){
    int c, d;
    c = is.get();
    d = is.get();
    while (c != '*' || d != '/'){
        c = d;
        d = is.get();
    }
}

//保证引号里面内容能够完整输出
void echo_quote(int c, istream & is, ostream & os){
    int d;
    os.put(c);
    while((d = is.get()) != c){//引号没有成对则输出
        os.put(d);
        if (d == '\\'){//换行符
            os.put(is.get());//手动换行
        }
    }
    os.put(d);
}