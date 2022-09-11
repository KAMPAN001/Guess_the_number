#include <iostream>
#include <Windows.h>

#include "Guess_the_number.h"

using namespace std;

//Main function responsible for handling a simple menu and calling the constructor
int main()
{
    HANDLE hout;
    hout = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "________  Guess The Number  ________ \n\n " ;
    SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    char again;
    do
    {
        GuessTheNumber game;
        game.save(game.check_number());
        cout << "If you want to play again youe will have to put +, evry thing is no: ";
        cin >> again;
    } while (again == '+');
    cout << "Thank you for the game";
    
}
