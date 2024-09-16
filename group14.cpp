#include <iostream>
#include <string>
using namespace std;

bool isWin(char game[3][3]) {
	bool win = false;
	if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
	if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
	// column
	if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
	if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	// diagonal
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
	return win;
}
int main() {
	int i, j;
	char game[3][3] = { ' ' }; // Tic-tac-toe
	int empty[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
	char player1 = 'X';
	char player2 = 'O';
	bool turn = true; // false for player 1's turn, true for player 2's turn.Player 1 first.
	bool check = true, temp = true;
	cout << "X = Player 1" << endl << "O = Player 2" << endl;
	for (int n = 0; n < 9; n++) {
		turn = !turn; // use the not-operator to change true to false or false to true.
			if (turn == false)
				cout << "Player 1: ";
			else
				cout << "Player 2: ";
		cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
		cin >> i >> j;
		//cout << empty[i][j] << endl;
		while (temp) {
			if ((empty[i][j] == 0) && ((i == 0 || i == 1 || i == 2) && (j == 0 || j == 1 || j == 2))) {
				empty[i][j] = 1;
				temp = false;
			}
			else {
				cout << "input error" << endl;
				cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
				cin >> i >> j;
			}
		}
		temp = true;
		//cout << empty[i][j] << endl;
		if (turn == false)
			game[i][j] = 'X';
		else
			game[i][j] = 'O';
		cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
		cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
		cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
		if (isWin(game)) {
			if (turn == false) {
				cout << "Player1 ";
			}
			else {
				cout << "Player2 ";
			}
			cout << "Win!" << endl;
			check = false;
			break; // need to terminate the problem
		}
	}
	if (check == true) // all celles with i=0 to 2 have been inputted above but no winner yet
		cout << "Tie!" << endl;
	// show the game to console
	cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
	cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
	cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;
	return 0;
}