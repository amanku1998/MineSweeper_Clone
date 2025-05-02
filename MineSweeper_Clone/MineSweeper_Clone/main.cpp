#include <iostream>
using namespace std;

enum levelDifficulty
{
	EASY = 1,
	MEDIUM,
	HARD
};

void chooseDifficulty(int& side, int& mines)
{
	int level;
	cout << "Choose Difficulty Leve :" << endl;
	cout << "Press 1. EASY (9x9 cells and 10 mines)" << endl;
	cout << "Press 2. EASY (16x16 cells and 40 mines)" << endl;
	cout << "Press 3. EASY (24x24 cells and 99 mines)" << endl;
	cin >> level;

	switch (level)
	{
		case EASY: 
			side = 9;
			mines = 10;
			break;

		case MEDIUM:
			side = 16;
			mines = 40;
			break;

		case HARD:
			side = 24;
			mines = 99;
			break;

		default:
			cout << "Invalid choice. Defaulting to EASY." << endl;
			side = 9;
			mines = 10;
			break;
	}
}

void displayMessage()
{
	cout << "==============================================================================" << endl;
	cout << "                            Welcome to Text-Based Minesweeper!                        " << endl;
	cout << "==============================================================================" << endl;
	cout << "   Rules of the Game:" << endl;
	cout << "1. The board is a grid of hidden cells. Some cells contain mines!" << endl;
	cout << "2. Your goal is to reveal all the cells that do not contain mines." << endl;
	cout << "3. If you reveal a cell with a mine, the game is over." << endl;
	cout << "4. Numbers on revealed cells indicate how many mines are adjacent to that cell." << endl;
	cout << "5. Use logic to determine where the mines are and avoid them!" << endl;
	cout << endl;
	cout << "Good luck, and may your moves be safe!" << endl;
	cout << "==============================================================================" << endl << endl;
}

int main()
{
	int side, mines;
	displayMessage();
	chooseDifficulty(side, mines);

}
