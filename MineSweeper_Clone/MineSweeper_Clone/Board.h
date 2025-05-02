#pragma once
#include <vector>
#include "Cell.h"

class Board
{
private:
	int gridSize;
	int totalMines;
	vector<vector<Cell>> grid;
	void calculateAdjacentCells();

public:
	Board(int gridSize, int toatalMines);
	void initializeBoard();
	void displayBoard(bool debugMode = false);
	void displaySettings();
	int getSide();
	int getMines();
	Cell& getCell(int row, int col);
};