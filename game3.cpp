#include <bits/stdc++.h>

using namespace std;

class Board // 0 is empty, 1 is X, -1 is O
{
private:
	int B[3][3];
	int gameState; // Draw is 0, X wins is 1 and O wins is -1
	static int whoseTurn;
public:
	Board () {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				B[i][j] = 0;
			}
		}
	}

	int getTurn () {
		return whoseTurn;
	}

	void changeTurn () {
		whoseTurn++;
	}

	void setX (string c) {
		cout << "Input your choice for X: " << endl;
		cin >> c;
		if(c == "1" || c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == "7" || c == "8" || c == "9") {
			int choice = stoi(c);
			int x = (choice - 1) % 3;
			int y = (choice - 1) / 3;
			if (B[x][y] == 0) {
				B[x][y] = 1;
				printB();
			}
			else {
				cout << "Invalid input, please try again!" << endl;
				setX(c);
			}
		}
		else {
			cout << "Invalid input, please try again!" << endl;
			setX(c);
		}
	}

	void setO (string c) {
		cout << "Input your choice for O: " << endl;
		cin >> c;
		if(c == "1" || c == "2" || c == "3" || c == "4" || c == "5" || c == "6" || c == "7" || c == "8" || c == "9") {
			int choice = stoi(c);
			int x = (choice - 1) % 3;
			int y = (choice - 1) / 3;
			if (B[x][y] == 0) {
				B[x][y] = -1;
				printB();
			}
			else {
				cout << "Invalid input, please try again!" << endl;
				setO(c);
			}
		}
		else {
			cout << "Invalid input, please try again!" << endl;
			setO(c);
		}
	}

	bool isOver () {
		int summ[8];
		summ[0] = B[0][0] + B[0][1] + B[0][2];
		summ[1] = B[1][0] + B[1][1] + B[1][2];
		summ[2] = B[2][0] + B[2][1] + B[2][2];
		summ[3] = B[0][0] + B[1][0] + B[2][0];
		summ[4] = B[0][1] + B[1][1] + B[2][1];
		summ[5] = B[1][2] + B[1][2] + B[2][2];
		summ[6] = B[0][0] + B[1][1] + B[2][2];
		summ[7] = B[2][0] + B[1][1] + B[0][2];
		for (int i = 0; i < 8; i++) {
			if(summ[i] == 3) {
				gameState = 1;
				return true;
			}
			else if(summ[i] == -3) {
				gameState = -1;
				return true;
			}
		}			
		gameState = 0;
		if (whoseTurn == 9) {
			return true;
		}
		return false;
	}

	void printB () {

		char Bo[19][19];
		for(int i = 0; i < 19; i++) {
			for(int j = 0; j < 19; j++) {
				Bo[i][j] = ' ';
			}
		}
		Bo[3][3] = '1';
		Bo[3][9] = '2';
		Bo[3][15] = '3';
		Bo[9][3] = '4';
		Bo[9][9] = '5';
		Bo[9][15] = '6';
		Bo[15][3] = '7';
		Bo[15][9] = '8';
		Bo[15][15] = '9';

		for(int i = 0; i < 19; i++) {
			Bo[0][i] = '-';
			Bo[6][i] = '-';
			Bo[12][i] = '-';
			Bo[18][i] = '-';
		}
		for(int j = 1; j < 18; j++) {
			Bo[j][0] = '|';
			Bo[j][6] = '|';
			Bo[j][12] = '|';
			Bo[j][18] = '|';
		}
		for(int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (B[i][j] == 1) {
					Bo[2 + 6 * j][2 + 6 * i] = '*';
					Bo[2 + 6 * j][4 + 6 * i] = '*';
					Bo[4 + 6 * j][2 + 6 * i] = '*';
					Bo[4 + 6 * j][4 + 6 * i] = '*';
					Bo[3 + 6 * j][3 + 6 * i] = '*';
				}
				else if (B[i][j] == -1) {
					Bo[2 + 6 * j][2 + 6 * i] = '*';
					Bo[3 + 6 * j][2 + 6 * i] = '*';
					Bo[4 + 6 * j][2 + 6 * i] = '*';
					Bo[2 + 6 * j][4 + 6 * i] = '*';
					Bo[3 + 6 * j][4 + 6 * i] = '*';
					Bo[4 + 6 * j][4 + 6 * i] = '*';
					Bo[2 + 6 * j][3 + 6 * i] = '*';
					Bo[4 + 6 * j][3 + 6 * i] = '*';
					Bo[3 + 6 * j][3 + 6 * i] = ' ';
				}
			}
		}
		for(int i = 0; i < 19; i++) {
			for(int j = 0; j < 19; j++) {
				cout << Bo[i][j];
			}
			cout << endl;
		}
	}
	
	void whoWon () {
		if(gameState == 1) cout << "X won!" << endl; 
		else if(gameState == -1) cout << "O won!" << endl; 
		else cout << "It's a draw!" << endl;
	}
};

int Board::whoseTurn = 0;

int main () {
	Board M;
	string choice;
	while (!M.isOver()) {
		cout << "\033[2J\033[1;1H";
		M.printB();
		if(M.getTurn() % 2 == 0) {
			M.setX(choice);
		}
		else if(M.getTurn() % 2 == 1) {
			M.setO(choice);
		}
		M.changeTurn();
	}
	cout << "\033[2J\033[1;1H";
	M.printB();
	M.whoWon();
	return 0;
}