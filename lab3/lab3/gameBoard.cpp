#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "lab3.h"

using namespace std;




ostream& operator<<(ostream& os, const TicTac& game) {
	for (int i = 0; i < board_size; i++) {
		for (int j = 0; i < board_size; j++) {
			os << game.board[i][j] << " ";
		}
		os << endl;
	}

	return os;

}

// initialize the game board 
TicTac::TicTac() {
	if_AI = false;
	num_moves = 0;
	player = "X";


	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			board[i][j] = " ";
		}
	}
	board[0][0] = "4";
	board[1][0] = "3";
	board[2][0] = "2";
	board[3][0] = "1";
	board[4][0] = "0";
	board[5][1] = "0";
	board[5][2] = "1";
	board[5][3] = "2";
	board[5][4] = "3";
	board[5][5] = "4";
}


bool TicTac::done() {
	// usable board between (1,2) to (3,4)

	//three in col
	for (int row = board_edge_up; row <= board_dege_down; row++) {
		if (board[row][2] != " " && board[row][2] == board[row][3] && board[row][3] == board[row][4])
			return true;
	}
	
	// three in row
	for (int col = board_edge_left; col <= board_edge_right; col++) {
		if (board[1][col] != " " && board[1][col] == board[2][col] && board[2][col] == board[3][col]) {
			return true;
		}
	}

	// three diag
	if (board[1][1] != " " && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
		return true;
	}

	if (board[1][2] != " " && board[1][1] == board[2][2] && board[2][2] == board[3][3]) {
		return true;
	}

	return false;
}

bool TicTac::draw() {
	// quit if someone win or no space to continue 
	if (num_moves == end_game || this->done()) {
		return true;
	}

	return false;

}


int TicTac::prompt(unsigned int& x, unsigned int& y) {
	unsigned int tempx;
	unsigned int tempy;


	cout << "Please enter the corrdnates of the next move to continue or quit to quit." << endl <<endl;

		string line;
		cin >> line;
        if(line == "quit"){
        	return QUIT;
        }
		
    try{
		size_t = comma = line.find(",");
		line.replace(comma,1," ")
		istringstream ss(line);
		if (ss >> tempx >> tempy) {
			if (board_dege_down <= tempx < board_edge_up && board_edge_left <= tempy <= board_edge_right) {
					// valid input 
					//continue
				x = tempx;
				y = tempy;
				return no_error;
			}
			else {
					thorw exeception("One or both of inputted corrdinate is out of boundary.Please enter the corrdnates of the next move to continue or quit to quit."); 
				}
			}
	
		else {thwor exception( "Your input is invalid. Please enter the corrdnates of the next move to continue or quit to quit." );
		}
	}
	catch ( exception e){
		return TicTac::prompt(x,y)
	}

}

int TicTac::turn() {
	++num_moves;

	if (num_moves % 2 == 0) { // step 1 by x and step2 by o
		player = "O";
	}
	else {
		player = "X";
	}
	cout << endl<< "This is Player " << player << "'s turn" << endl;

	unsigned int x ;
	unsigned int y ;
 
		// quit if input have quit 
		if (prompt(x, y) == QUIT) {
			return QUIT;
		}

		// if sapace is empty, put in
		if (board[4-y][x+1] == " ") { //convert the visually corrding and coordinate in the 2d array.
			board[4-y][x+1] = player;
		}
		else {
			cout << "That space was occupied." << endl;
		}

	

	// output the board
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			std::cout << board[i][j] << " ";
		}
		cout << " " << endl;
	}


	// prints out the moves the player has made store in private string
	stringstream ss;
	ss << x << "," << y << "; ";
	if (player == "X") {
		x_moves.append( ss.str());
		cout << "Player X: " << x_moves << endl << endl;
	}
	else if (player == "O") {
		y_moves.append( ss.str());
		cout << "Player O: " << y_moves << endl<< endl;
	}
	return no_error;


}

int TicTac::play() {

	//output the board for the board 
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << board[i][j] << " ";
		}
		cout << " " << endl;
	}
	//cout << *this << endl;

	// loop until finish (quit win or tie)
	while (1) {
		// quit
		if (this->turn() == QUIT) {
			cout << "Player " << player << " choose to quit" << endl;
			return QUIT;
		}
		// win 
		if (this->done()) {
			if (player == "O") {
				cout << "Player O wins!" << endl;
				return no_error;
			}
			else {
				cout << "Player X wins!" << endl;
				return no_error;
			}
		}
		// tie
		if (this->draw()) {
			cout << num_moves << " There is a tie" << endl;
			return Tie;
		}
	}
}

