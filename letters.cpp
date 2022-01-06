#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <array>
#include "letters.hpp"
//include paths^


//standard namespace
using namespace std;

//constructor function
Letters::Letters(int nw, int p) { 
  numb_words = nw;
  points = p;
};

string Letters::get_letters(){
    
    array<string, 100> letters{"A","A","A","A","A","A","A","A","A",
    "B","B","C","C","D","D","D","D","E","E","E","E","E","E",
    "E","E","E","E","E","E","F","F","G","G","G","H","H","I","I",
    "I","I","I","I","I","I","J","K","L","L","L","L","M","M",
    "N","N","N","N","N","N","O","O","O","O","O","O","O","O","P",
    "P","Q","R","R","R","R","R","R","S","S","S","S","T","T",
    "T","T","T","T","U","U","U","U","V","V","W","W","X","Y","Y","Z"};
    array<string,7> new_letters = {"","","","","","",""};
    srand(time(0)); 
    int random;
    for (int i = 0; i < numb_words; i++){
      random = rand() % 101;
      new_letters[i] = letters[random];
    }
  ostringstream os; //https://www.techiedelight.com/convert-int-array-string-cpp/
    for (string i: new_letters) {
        os << i;
    }
    string str(os.str());
    return str;
}
