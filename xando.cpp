#include <iostream>
using namespace std;

// an array containing each tile on the board.
char square[10] = {'c', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// variable to track turns
// odd --> player 1 (x)
// even --> player 2 (o)
short playerTurn = 1;

// if number of moves equal to 9, game is draw
int numberOfMoves = 0;

void drawGrid(){	
	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl << endl;
}

int checkWin(){
	int i; bool win;
	// check for any diagonal wins
	win = (square[1] == square[5]) && (square[1] == square[9]);
	if (win)
		return 1;

	win = (square[3] == square[5]) && (square[3] == square[7]);
	if (win)
		return 1;	

	// check for horizontal wins
	for (i=1; i<8; i+=3){
		win = (square[i] == square[i+1]) && (square[i] == square[i+2]);
		if (win)
			return 1;
	}

	// check for vertical wins
	for (i=1; i<4; i++){
		win = (square[i] == square[i+3]) && (square[i] == square[i+6]);
		if (win)
			return 1;
	}

	// check for draw
	// if 9 moves have been made, it has to be a draw.
	// (playerTurn starts counting from 1) 
	// 10 - 1 = 9 moves.
	if (playerTurn == 10)
		return 0;

	return -1;

}

int main(){

	do {
		int move;
		char player = (playerTurn%2 == 0) ? 'O' : 'X';
		cout << "The player turn number is: " << playerTurn << endl;
		cout << "Enter a valid number";
		drawGrid();
		cout << "It is " << player << "'s turn" << endl;
		cin >> move;

		// check if the move doesn't exist or has been made
		if (move > 9 || square[move] == 'X' || square[move] == 'O'){
			cout << "Invalid move. Play again." << endl;
			playerTurn--;
		}
		else{
			square[move] = player;
		}

		playerTurn++;
	} while (checkWin() == -1);

	drawGrid(); // draw final game state

	if(checkWin() == 1){
		char player = ((playerTurn-1)%2 == 0) ? 'O' : 'X';
		cout << player << " won the game!!!" << endl;
	}
	else if (checkWin() == 0){
		cout << "The game ended in a draw" << endl;		
	}

	return 0;

}