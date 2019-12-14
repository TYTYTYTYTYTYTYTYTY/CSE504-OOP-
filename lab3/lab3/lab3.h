#pragma once

#ifndef LAB3 
#define LAB3 

#include <string>

using namespace std;

enum useful_number {
	file_name = 0,
	expect_num_input = 2,
	board_edge_right = 1,
	board_dege_down =3,
	board_edge_up =1,
	board_edge_left = 3,
	board_size =6,
	end_game =9,
	num_dim  = 2 // number of dimension on the board
};

enum action {
	QUIT = 1, // quit is not an error thus put it here
    Tie = 100 // tie is not an error thus put it here 
};

enum error_type {
	no_error  = 0 
};

class TicTac {
private:
	string board[board_size][board_size];
	bool if_AI; //if play against AI 
	unsigned int num_moves; //count number of moves 
	string player;
	string x_moves;//store what moves x has made 
	string y_moves;// store what moves o has made

public:
	TicTac();
    bool done();
	bool draw();
	int prompt(unsigned int& x, unsigned int& y);
	int play();
	int turn();


	friend ostream& operator<<(ostream& os, const TicTac& board);
};





#endif 