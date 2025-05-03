#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>

Board::Board(int size, int mines)
{
	gridSize = size;
	totalMines = mines;

	initializeBoard();
}

void Board::initializeBoard()
{
	grid.resize(gridSize, vector<Cell>(gridSize));

	srand(time(0));
	int placedMines = 0;

	while (placedMines < totalMines)
	{
		int row = rand() % gridSize;
		int col = rand() % gridSize;

		if (!grid[row][col].hasMines())
		{
			grid[row][col].setMines(true);
			placedMines++;
		}
	}
	calculateAdjacentCells();
}

//Used to calculates how many mines are in its surrounding 8 cells and stores that number in the cell
void Board::calculateAdjacentCells()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			//skip the cell if it has a mine(means If this cell is a mine, don’t count its neighbors)
			if (grid[i][j].hasMines())
				continue;

			int mine_count = 0;

			//checks the 8 surrounding cells
			for (int row = i - 1; row <= i + 1; row++)
			{
				for (int col = j - 1; col <= j + 1; col++)
				{
					if (row >= 0 && row < gridSize && col >= 0 && col < gridSize)
					{
						if (grid[row][col].hasMines())
							mine_count++;
					}
				}
			}
			grid[i][j].setAdjacentMines(mine_count);
		}
	}
}

//Used to reveal the board after win or lose
void Board::displayBoard(bool isRevealed)
{
	cout << "   ";
	//Display the column headers
	for (int i = 0; i < gridSize; i++)
	{
		cout << setw(2) << setfill('0') << i << " ";
	}
	cout << "\n\n";

	for (int i = 0; i < gridSize; i++)
	{
		//print each row header
		cout << setw(2) << setfill('0') << i << "|";
		for (int j = 0; j < gridSize; j++)
		{
			if (isRevealed)
				grid[i][j].printMines();
			else
				grid[i][j].display();
		}

		cout << endl;

		if (gridSize == 9)
			cout << "    ----------------------------";
		else if (gridSize == 16)
			cout << "    -------------------------------------------------";
		else if (gridSize == 24)
			cout << "    -------------------------------------------------------------------------";

		cout << endl;
	}
}

//Used to display the grid size & total no of mines 
void Board::displaySettings()
{
	cout << "=====================================" << endl;

	cout << "Grid Size: " << gridSize << "x" << gridSize << endl;
	cout << "Number of Mines: " << totalMines << endl;

	cout << "=====================================" << endl << endl;
}

int Board::getSide()
{
	return gridSize;
}

int Board::getMines()
{
	return totalMines;
}

Cell& Board::getCell(int row, int col)
{
	return grid[row][col];
}