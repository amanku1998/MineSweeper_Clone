#include "Board.h"
#include <cstdlib>
#include <ctime>

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

//Used to calculate the total no of mines in grid
void Board::calculateAdjacentCells()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			if (grid[i][j].hasMines())
				continue;

			int mine_count = 0;

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