#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>

#include"Guess_the_number.h"

using namespace std;

/*!
* \brief Class GuessTheNumber allows you to generate a random number
* 
* Operations:
* -picking the number of use
* -verification the number
* -displaying the message
* -counting trials
* -saveing result
*/

/*!
* \brief Constructor for class GuessTheNumber
* 
* Create a object,generate random number and takes a number from user
*/
GuessTheNumber::GuessTheNumber()
{
	input_number_from_user();
	random_number();
}

GuessTheNumber::~GuessTheNumber() {};

/*!
* \brief Void function 
* 
* Takeing number from user and verifies this number
*/
void GuessTheNumber::input_number_from_user()
{
	cout << "Hi, give me a number (from 0 to 100): ";
	while (!(cin >> GuessTheNumber::number_for_game))
	{
		cout << "Bad value, please give new:";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if (GuessTheNumber::number_for_game < 0 or GuessTheNumber::number_for_game > 100)
	{
		cout << "Bad value, please give new:";

		while (!(cin >> GuessTheNumber::number_for_game))
		{
			cout << "Bad value, please give new:";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

/*!
* \brief Void function to create random number
* 
* This function creating random number for game
*/
void GuessTheNumber::random_number()
{
	srand(time(NULL));
	int first_number, second_number;
	first_number = (rand() % 2) + 1;
	second_number = (rand() % 50) + 1;
	GuessTheNumber::random_number_for_game = first_number * second_number;

}

/*!
* \brief Integer function for checking number
* 
* Check user's number with random number and return how many trials user needed
*/
int GuessTheNumber::check_number()
{
	int how_many_time = 1;

	if (GuessTheNumber::number_for_game == GuessTheNumber::random_number_for_game)
	{
		return how_many_time;
	}
	else
	{
		do
		{
			if (GuessTheNumber::number_for_game > GuessTheNumber::random_number_for_game)
			{
				cout << "Your number is to big";
			}
			else
			{
				cout << "Your number is to small";
			}
			cout << " Unlucky!, try again: ";

			while (!(cin >> GuessTheNumber::number_for_game))
			{
				cout << "Bad value, please give new:";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (GuessTheNumber::number_for_game < 0 or GuessTheNumber::number_for_game > 100)
			{
				cout << "Bad value, please give new:";

				while (!(cin >> GuessTheNumber::number_for_game))
				{
					cout << "Bad value, please give new:";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			how_many_time++;
		} while (GuessTheNumber::number_for_game != GuessTheNumber::random_number_for_game);

	}
	return how_many_time;
}

/*!
* \brief Bool function to check if the user wants to save the result
*/
bool input_chose_for_save()
{
	char chose;
	cin >> chose;
	if (chose == 'T' or chose == 't')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*!
* \brief Void function to saving result
* 
* This function gets result, nick and saveing them 
*/
void GuessTheNumber::save(int score)
{
	bool chose_for_save;
	cout << "You won, you done this in " << score << " times";
	cout << "\nWant to save this? (T is yes , evry thing else is no):";
	chose_for_save = input_chose_for_save();
	if (chose_for_save == true)
	{
		fstream save;
		string name;
		cout << "Your nick is: ";
		cin.clear();
		cin.ignore();
		getline(cin, name);
		save.open("Save_Game.txt", ios::app);
		if (save.is_open() == true)
		{
			string information_about_game = name + " has: " + to_string(score);
			save << information_about_game << endl;
			save.close();
		}
		else
		{
			cout << "We dont have acces to file, sorry";
		}

	}
}

