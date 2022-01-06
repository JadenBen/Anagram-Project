#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "input.hpp"

using namespace std;


//constructor function
Input::Input(string ui){
  user_input = ui;
};

void Input::word_check(){
    ifstream words; //file variable
    size_t pos; //size_t datatype variable that holds position
    string line;//temp variable for line position
    words.open("words_alpha.txt");//open file path
    bool word_check = false;
    if(words.is_open()){ //"if while true" essentially. This is so the function doesn't get runned when the file isn't open
      while(getline(words,line)){
        pos = line.find(user_input);//iterates through each line to find (match) inputted user input
        //https://www.codeproject.com/Questions/844342/How-Do-I-Search-For-A-Word-In-A-Text-File-In-Cplus
        if(pos!= string::npos){ // string::npos is returned if string is not found
            word_check = true; //sets word check to true if found
    }//if not the word check value will stay at its default boolean, false.
}
    if(word_check == true){//ifstatement that checks if boolean has changed to true and prints valid
        cout << "valid\n";
    }
    else if(word_check == false){//if boolean has not changed than print not valid
        cout << "not valid\n";
    }
}
}
bool Input::given_check(){
    return true;
}