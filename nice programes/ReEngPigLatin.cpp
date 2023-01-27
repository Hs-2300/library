#include <iostream>
#include <string>
#include <cctype>

using std::cin; using std::cout;\
using std::endl; using std::string;

string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

int main(){
    cout << "This program translats English into Pig Latin." <<endl;
    string line;
    cout << "Enter English text: ";
    getline(cin,line);
    string translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation <<endl;
    return 0;
}

string lineToPigLatin(string line){
    string result = "";
    string word = "";
    bool start = false;//start = true:ready to tanslate a word 
    for (int i = 0; i < line.length(); i++){
       if (isalpha(line[i])) word += line[i];
       else {
        start = true;
        if (start){
            result += wordToPigLatin(word);
            word="";
            start = false;
            }
        result += line[i];
        }
       
       
    }
    return result;
}

string wordToPigLatin(string word){
    int first = findFirstVowel(word);
    if (first == -1) return word;
    else if (first == 0) return word+"way";
    else{
        string head = word.substr(0,first);
        string tail = word.substr(first);
        return tail + head + "ay";
    }
}

int findFirstVowel(string word){
    for (int i = 0; i < word.length(); i++){
        if (isVowel(word[i])) return i;
    }
    return -1;
}

bool isVowel(char ch){
    switch (ch)
    {
    case 'a': case 'e': case 'i': case 'o': case 'u':\
    case 'A': case 'E': case 'I': case 'O': case 'U':
        return true;
        // break;
    
    default:
        return false;
        // break;
    }
}
// int main(){
//     cout << lineToPigLatin("Alice was beginning to ... to do.")<< endl;
// }