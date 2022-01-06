#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "letters.hpp"
#include "input.hpp"
using namespace std;


//main function
int main(){
    
    //class object initialization for letters class
    Letters diff(7,0);//attributes of class (list of letters, number of) 

    cout << "Welcome to Anagrams. \n";

    string let = diff.get_letters();
    cout << let;
    cout << endl;
    
    //prompt
    cout << "Write a three (or more) letter word using only the letters above (once each): ";
    string temp;// user input string temporary variable
    cin >> temp;//get user input

    //class object initialization for input class
    Input input(temp);
    input.word_check();
}
