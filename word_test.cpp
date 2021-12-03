#include <iostream>
//fstream creates, reads and writes to files
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

int main() {

  //identifier for text file
  

  // create and open a text file - 
  //note: if the file already exists it will be overwritten
  //string to temporarily hold output from file
  
  // Read from the text file
  ifstream words("words_alpha.txt");

//makes it so "applesauce" doesn't work
  //std::regex e{"\\b" + user_input + "\\b"};
  // Use a while loop together with the getline() function to read the file line by line
  
if (words.is_open()){
    cout << "Write the word you're searching for\n";
    string user_input;
    cin >> user_input;
    string line;


  while (!words.eof()){ // for each candidate word read from the file 
			getline(words, line);
			size_t found = line.find(user_input);
			if (found != string::npos)
				cout << "The word" << user_input << "has been found in line:" << line;
		}
		words.close();
	}

  return 1;
}
