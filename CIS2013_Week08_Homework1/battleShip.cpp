//battle ship game
#include <iostream>
#include<fstream>
#include <string>
using namespace std;




void grid(int num, int turnLimit) {
	char key[10][10], board[10][10];
	int turnCount = 0, hitCount = 0;
	string fileName = ("grid" + to_string(num)), message = "--";
	ifstream in_keyGrid;
	bool ingo = true;

	// gets grid from saved file and saves as array
	in_keyGrid.open(fileName);
	if (in_keyGrid.fail()){
		cout << "file did not open";	
	}
	else {
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				in_keyGrid >> key[x][y];
			}	
		}	
	}
	in_keyGrid.close();


	//sets up clear board
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			 board[y][x] = '~';
		}
	}



	//game logic
	while(turnCount < turnLimit) {
		while (ingo) {
			int x = 0, y = 0;
			cout << "Missle: " << turnCount + 1 << " of " << turnLimit << endl;
			cout << "Where would you like to hit? (x y) \n";
			cin >> x >> y;
			if (x < 1 || x > 10 || y < 0 || y > 10) {
				cout << "Those coordinates are invalid\n";
			}
			else {
				cout << x << "," << y << endl;
				x--; y--;

				//on a hit
				if (key[x][y] == 'x') {
					message = "HIT!\n";
					board[x][y] = 'X';
					key[x][y] = 'o';
					hitCount++;
				}
				//hits the same spot
				else if (key[x][y] == 'o') {
					message = "You already hit there!\n";
					key[x][y] = 'o';
				}
				//on a miss
				else {
					message = "MISS!\n";
					board[x][y] = 'O';
					key[x][y] = 'o';
				}
				ingo = false;
			}
		}ingo = true;


		//writes border and board
		
		cout << "   1 2 3 4 5 6 7 8 9 10\n";
		for (int x = 0; x < 10; x++) {
			if (x < 9) {
				cout << " ";
			}
			cout << x + 1;

			for (int y = 0; y < 10; y++) {
				//writes board array
				cout << " " << board[x][y];
			}
			cout << endl;
		}
		cout << message;
		if (hitCount == 17) {
			turnCount = 100;
		}
		else{ turnCount++; }
		
	}
	if (hitCount == 17) {
		cout << "You sank my battleship!\n";
	}
	else {
		cout << "You ran out of missles, you lose.\n";
	}

}






int main() {
	char keepGoing = 'y';
	int gridNum = 0, turnLimit = 100;
	bool ingo = true;

	while(keepGoing == 'y'){
		while ( ingo) {
			//select map
			cout << "Which grid would you like to use? (1-10)";
			cin >> gridNum;
			if (gridNum > 0 && gridNum <= 10) {
				ingo = false;
			}
			else {
				cout << "Choose 1-10";
			}
		
		}
		//set turn number
		ingo = true;
		while (ingo)
		{
			cout << "How many missles do you have?(1-100)";
			cin >> turnLimit;
			if (turnLimit > 0 && turnLimit <= 100) {
				ingo = false;
			}
			else {
				cout << "Choose 1-10";
			}
		}
		ingo = true;
		grid(gridNum, turnLimit);
		cout << "Press y to play again. \n";

		cin >> keepGoing;

	}
	return 0;
}