#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>

using namespace std;



class Letters {
    //Array of letters with scrabble probabilities
    int numb_words;
    int points;//checks length of the words and determines a point value for input
    //bool check_w;
    
    //methods
    public:
    Letters(int nw, int p);
    string get_letters();
    
};