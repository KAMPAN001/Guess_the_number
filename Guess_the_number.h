#pragma once

//Class with constructor, destroyer,  function and variable.
class GuessTheNumber
{
public:
	GuessTheNumber();
	~GuessTheNumber();
	void input_number_from_user();
	void random_number();
	int check_number();
	void save(int score);
private:
	int number_for_game;
	int random_number_for_game;

};