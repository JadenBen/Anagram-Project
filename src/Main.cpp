#include "PCH.hpp"
#include "Platform/Platform.hpp"
#include "input.hpp"
#include "letters.hpp"
#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
bool iteration(std::string let, std::string temp);
bool iteration(std::string let, std::string temp)
{
	std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return std::tolower(c); });

	std::transform(let.begin(), let.end(), let.begin(), [](unsigned char c) { return std::tolower(c); });

	for (unsigned int i = 0; i < temp.length(); i++)
	{
		bool found = (std::find(let.begin(), let.end(), temp[i]) != let.end());
		if (found == false)
		{
			return false;
		}
	}
	return true;
}

//main function
int main()
{
	//class object initialization for input class
	//class object initialization for letters class

	Letters diff(7, 0); //attributes of class (list of letters, number of)

	std::string let = diff.get_letters();

	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1000.0f * screenScalingFactor, 600.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());
	//prompt

	sf::Font font;
	if (!font.loadFromFile("content/arial_black.ttf"))
	{
		//error
	}

	//create a text object That will display letters generated from the diff.get_letters() function we made. This will be on
	//the screen the whole time to give the player a reference of what letters they are playing anagrams with
	sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString(let);
	// set the character size
	text.setCharacterSize(30); // in pixels, not points!
	// set the text color
	text.setFillColor(sf::Color::Green);
	// set the text style
	text.setStyle(sf::Text::Bold);
	//article on centering text (it's complicated): https://learnsfml.com/how-to-center-text/
	// get the bounds of the text rectangle
	auto text_width = text.getLocalBounds().width; //auto allows variable to deduce type from the assigned value
	auto text_height = text.getLocalBounds().height;
	//set the position of the text (attempted to center it!)
	text.setPosition(window.getSize().x / 2 - text_width / 2.f, (window.getSize().y / 2 - text_height / 2 - 15.f) - 350);

	//this is the string we will be pushing the letters the user types into. If a user types "A", a will be added (pushed) to this string
	//later in the code
	std::string temp = "";

	//create a text object that will display the letters the user is typing on the screen
	sf::Text user_text;
	// select the font
	user_text.setFont(font); // font is a sf::Font
	// set the string to display
	user_text.setString(temp);
	// set the character size
	user_text.setCharacterSize(75); // in pixels, not points!
	// set the text color
	user_text.setFillColor(sf::Color::White);
	// set the text style
	user_text.setStyle(sf::Text::Bold);
	//article on centering text (it's complicated): https://learnsfml.com/how-to-center-text/
	user_text.setPosition(window.getSize().x / 2 - text_width / 2.f - 100.f, window.getSize().y / 2 - text_height / 2 - 15.f);

	//create a text object to track the time the player has remaining
	sf::Text time;
	// select the font
	time.setFont(font); // font is a sf::Font
	// set the string to display
	time.setString("");
	// set the character size
	time.setCharacterSize(30); // in pixels, not points!
	// set the text color
	time.setFillColor(sf::Color::Red);
	// set the text style
	time.setStyle(sf::Text::Bold);
	//set the position of the text (attempted to center it!)
	time.setPosition(window.getSize().x / 2 - text_width / 2.f + 350, window.getSize().y / 2 - text_height / 2 + 300);

	sf::Text score;
	// select the font
	score.setFont(font); // font is a sf::Font
	// set the string to display
	score.setString("SCORE:");
	// set the character size
	score.setCharacterSize(30); // in pixels, not points!
	// set the text color
	score.setFillColor(sf::Color::White);
	// set the text style
	score.setStyle(sf::Text::Bold);
	//set the position of the text (attempted to center it!)
	score.setPosition(window.getSize().x / 2 - text_width / 2.f - 350, window.getSize().y / 2 - text_height / 2 + 260);

	sf::Text score_number;
	// select the font
	score_number.setFont(font); // font is a sf::Font
	// set the string to display
	score_number.setString("0");
	// set the character size
	score_number.setCharacterSize(30); // in pixels, not points!
	// set the text color
	score_number.setFillColor(sf::Color::White);
	// set the text style
	score_number.setStyle(sf::Text::Bold);
	//set the position of the text (attempted to center it!)
	score_number.setPosition(window.getSize().x / 2 - text_width / 2.f - 350, window.getSize().y / 2 - text_height / 2 + 300);

	int gamescore = 0;

	//reference video to this section of the code below: https://www.youtube.com/watch?v=aEDP7uhaiJc
	//--------------------------------------------------------------------------------
	sf::Texture title_img;
	sf::Texture tutorial_img;
	title_img.loadFromFile("content/title_screen.png");
	tutorial_img.loadFromFile("content/tutorial.png");

	sf::Sprite title;
	title.setTexture(title_img);
	sf::Sprite tutorial;
	tutorial.setTexture(tutorial_img);

	//centering the title and tutorial screens
	title.setPosition(sf::Vector2f(-100, -150));
	tutorial.setPosition(sf::Vector2f(-75, 0));
	//---------------------------------------------------------------------------------------------------------
	sf::Event event;
	float gametime = 0;

	bool game_start = true;
	sf::Clock closk;
	//sf::Time elapsed1 = clock.getElapsedTime();
	//^source: https://www.sfml-dev.org/tutorials/2.5/system-time.php
	window.clear();
	window.draw(title);
	window.display();
	while (window.isOpen() and game_start)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				game_start = false;
			}
		}
	}
	window.clear();
	window.draw(tutorial);
	window.display();
	game_start = true;
	while (window.isOpen() and game_start)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				game_start = false;
			}
		}
	}
	game_start = true;
	window.clear();
	while (window.isOpen() and game_start)
	{

		gametime += 0.0009;
		time.setString(std::to_string(gametime));
		//this loop is listening for events
		while (window.pollEvent(event))
		{
			//if user clicks the close window button, close the window
			if (event.type == sf::Event::Closed)
				window.close();

			// good explanation of event handling here
			//if user presses a key on the keyboard
			else if (event.type == sf::Event::KeyPressed)
			{
				//if statements checking which key was pressed. There probably is a more efficient
				//way of doing this then just putting a bunch of if statements,
				//but this was fast and easy to implement
				if (event.key.code == sf::Keyboard::A)
				{
					temp.push_back('a');
				}
				if (event.key.code == sf::Keyboard::B)
				{
					temp.push_back('b');
				}
				if (event.key.code == sf::Keyboard::C)
				{
					temp.push_back('c');
				}
				if (event.key.code == sf::Keyboard::D)
				{
					temp.push_back('d');
				}
				if (event.key.code == sf::Keyboard::E)
				{
					temp.push_back('e');
				}
				if (event.key.code == sf::Keyboard::F)
				{
					temp.push_back('f');
				}
				if (event.key.code == sf::Keyboard::G)
				{
					temp.push_back('g');
				}
				if (event.key.code == sf::Keyboard::H)
				{
					temp.push_back('h');
				}
				if (event.key.code == sf::Keyboard::I)
				{
					temp.push_back('i');
				}
				if (event.key.code == sf::Keyboard::J)
				{
					temp.push_back('j');
				}
				if (event.key.code == sf::Keyboard::K)
				{
					temp.push_back('k');
				}
				if (event.key.code == sf::Keyboard::L)
				{
					temp.push_back('l');
				}
				if (event.key.code == sf::Keyboard::M)
				{
					temp.push_back('m');
				}
				if (event.key.code == sf::Keyboard::N)
				{
					temp.push_back('n');
				}
				if (event.key.code == sf::Keyboard::O)
				{
					temp.push_back('o');
				}
				if (event.key.code == sf::Keyboard::P)
				{
					temp.push_back('p');
				}
				if (event.key.code == sf::Keyboard::Q)
				{
					temp.push_back('q');
				}
				if (event.key.code == sf::Keyboard::R)
				{
					temp.push_back('r');
				}
				if (event.key.code == sf::Keyboard::S)
				{
					temp.push_back('s');
				}
				if (event.key.code == sf::Keyboard::T)
				{
					temp.push_back('t');
				}
				if (event.key.code == sf::Keyboard::U)
				{
					temp.push_back('u');
				}
				if (event.key.code == sf::Keyboard::V)
				{
					temp.push_back('v');
				}
				if (event.key.code == sf::Keyboard::W)
				{
					temp.push_back('w');
				}
				if (event.key.code == sf::Keyboard::X)
				{
					temp.push_back('x');
				}
				if (event.key.code == sf::Keyboard::Y)
				{
					temp.push_back('y');
				}
				if (event.key.code == sf::Keyboard::Z)
				{
					temp.push_back('z');
				}

				//player presses enter after writing the word
				if (event.key.code == sf::Keyboard::Enter)
				{
					//initializing Input class object
					Input input(temp);

					//this code was used for debugging an error we had with the word_check() function
					//std::cout << iteration(let, temp) << "     " << input.word_check();

					//iteration() function checks if the user only used letters that are available to them
					//word_check() checks if their word is an actual english word. If both are true,
					//their score increases
					if (iteration(let, temp) == 1 and input.word_check() == 1)
					{
						//the longer the word, the more points are added
						//words below the length of 3 dont get points
						if (temp.length() == 3)
						{
							gamescore += 4;
						}
						if (temp.length() == 4)
						{
							gamescore += 7;
						}
						if (temp.length() == 5)
						{
							gamescore += 10;
						}
						if (temp.length() == 6)
						{
							gamescore += 25;
						}
						if (temp.length() > 7)
						{
							gamescore += 50;
						}
						score_number.setString(std::to_string(gamescore));
						//after word is scored, user input is set back to blank so they can type in a new word
						temp = "";
					}
				}
				//they can delete the letters they typed if they made a typo or their word wasnt a valid english word
				if (event.key.code == sf::Keyboard::BackSpace)
				{
					//deletes character from back of string
					temp = temp.substr(0, temp.size() - 1);
				}
				//space means the player wants to reset the game
				if (event.key.code == sf::Keyboard::Space)
				{
					//new letters are chosen for anagrams
					Letters diff(7, 0);
					let = diff.get_letters();
					text.setString(let);

					//gametime and player input are reset
					temp = "";
					gametime = 0;
					gamescore = 0;
					score_number.setString(std::to_string(gamescore));
				}
				user_text.setString(temp);
				//change position to accomdate new text size
			}
		}
		//clear the window
		window.clear();
		//draw all the text
		window.draw(text);
		window.draw(user_text);
		window.draw(time);
		window.draw(score);
		window.draw(score_number);
		//refresh the windwo with the drawings
		window.display();

		if (gametime > 60) // game ends after 60 sec
		{

			//repositions where the score is displayed and how big it is
			score_number.setPosition(window.getSize().x / 2 - text_width / 2.f - 100.f, window.getSize().y / 2 - text_height / 2 - 15.f);
			score_number.setCharacterSize(100);
			score.setPosition(window.getSize().x / 2 - text_width / 2.f - 100.f, window.getSize().y / 2 - text_height / 2 - 15.f - 100);
			score.setCharacterSize(100);

			//the end screen displays ths score in the middle of the screen
			window.clear();
			window.draw(score_number);
			window.draw(score);
			window.display();

			//stops the gameloop. To clarify, the space button isnt meant to replay the game, it is meant
			//to give you a better set of letters if you got really bad ones.
			while (true)
			{
				std::cout << "";
			}
		}
	}

	//class object initialization for input class
}
