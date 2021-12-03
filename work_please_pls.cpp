#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


int main(){
    //Array of letters with scrabble probabilities
    string letters[100] = {"A","A","A","A","A","A","A","A","A",
    "B","B","C","C","D","D","D","D","E","E","E","E","E","E",
    "E","E","E","E","E","E","F","F","G","G","G","H","H","I","I",
    "I","I","I","I","I","I","J","K","L","L","L","L","M","M",
    "N","N","N","N","N","N","O","O","O","O","O","O","O","O","P",
    "P","Q","R","R","R","R","R","R","S","S","S","S","T","T",
    "T","T","T","T","U","U","U","U","V","V","W","W","X","Y","Y","Z" };


    cout << "Welcome to Anagrams." << letters[100];

    


    ifstream words;
    size_t pos;
    string line;
    cout << "Write the word you're searching for\n";
    string user_input;
    cin >> user_input;
    words.open("words_alpha.txt");
    bool word_check = false;
    if(words.is_open()){
      while(getline(words,line)){
        pos = line.find(user_input);
        //https://www.codeproject.com/Questions/844342/How-Do-I-Search-For-A-Word-In-A-Text-File-In-Cplus
        if(pos!= string::npos){ // string::npos is returned if string is not found
            word_check = true; //sets word check to true if found
    }//if not the word check value will stay at its default boolean, false.
}


    if(word_check == true){
        cout << "valid\n";
    }
    else if(word_check == false){
        cout << "not valid\n";
    }
}
}
