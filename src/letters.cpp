#include "letters.hpp"
#include "Platform/Platform.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
//include paths^

//standard namespace

//constructor function
Letters::Letters(int nw, int p)
{
	numb_words = nw;
	points = p;
}

std::string Letters::get_letters()
{

	std::array<std::string, 100> letters { "A", "A", "A", "A", "A", "A", "A", "A", "A", "B", "B", "C", "C", "D", "D", "D", "D", "E", "E", "E", "E", "E", "E", "E", "E", "E", "E", "E", "E", "F", "F", "G", "G", "G", "H", "H", "I", "I", "I", "I", "I", "I", "I", "I", "J", "K", "L", "L", "L", "L", "M", "M", "N", "N", "N", "N", "N", "N", "O", "O", "O", "O", "O", "O", "O", "O", "P", "P", "Q", "R", "R", "R", "R", "R", "R", "S", "S", "S", "S", "T", "T", "T", "T", "T", "T", "U", "U", "U", "U", "V", "V", "W", "W", "X", "Y", "Y", "Z" };
	std::array<std::string, 7> new_letters = { "", "", "", "", "", "", "" };
	srand(time(0));
	int random;
	for (int i = 0; i < numb_words; i++)
	{
		random = rand() % 101;
		new_letters[i] = letters[random];
	}
	std::ostringstream os; //https://www.techiedelight.com/convert-int-array-string-cpp/
	for (std::string i : new_letters)
	{
		os << i;
	}
	std::string str(os.str());
	return str;
}