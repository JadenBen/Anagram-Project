#include "input.hpp"
#include "Platform/Platform.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Input::Input(std::string ui)
{
	user_input = ui;
}
//constructor function
bool Input::word_check()
{
	std::ifstream words;			   //file variable
	size_t pos;						   //size_t datatype variable that holds position
	std::string line;				   //temp variable for line position
	words.open("src/words_alpha.txt"); //open file path
	bool word_check = false;
	//"if while true" essentially. This is so the function doesn't get runned when the file isn't open
	while (getline(words, line))
	{
		pos = line.find(user_input); //iterates through each line to find (match) inputted user input
		//https://www.codeproject.com/Questions/844342/How-Do-I-Search-For-A-Word-In-A-Text-File-In-Cplus
		if (pos != std::string::npos)
		{					   // string::npos is returned if string is not found
			word_check = true; //sets word check to true if found
		}					   //if not the word check value will stay at its default boolean, false.
	}
	if (word_check == true)
	{ //ifstatement that checks if boolean has changed to true and prints valid
		return true;
	}
	return false;
}
