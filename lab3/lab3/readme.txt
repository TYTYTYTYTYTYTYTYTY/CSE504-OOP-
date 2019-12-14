CSE 504 lab3

Codec by Muzhou Liu : muzhouliu@wustl.edu 

Files included:

1. lab2.cpp
    This file includes the main function of the whole project that runs the TicTacToe game. 

2. lab3.h
    Class for TicTac is decleared in this header file. 
	Ostream operator << overload is also decleared in this file. 

3. gameBoard.cpp
    Most of the functions in this project are inplemented in this file. 
	functions included:
	    done: check if any player wins the game. 
		draw: check if the board is full or someone has already win the game 
		prompt: get input from command line and convert into usable coordinates
		turn: the action of players in each turn
		play: the process of running the TicTacToe game. 

///////////////////////////////////////////////////////////////////////////////////////////////
Returns :
This program has 3 different ending satatus:
no_error(0): there is no error runing the code. Can see this if someone wins the game. 
QUIT(1): The game ends when some choose to quit. 
Tie(100): The game ends when there is a tie. 

///////////////////////////////////////////////////////////////////////////////////////////////
Test cases:

