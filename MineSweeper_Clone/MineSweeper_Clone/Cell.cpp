#include "Cell.h"
#include <string>

Cell::Cell()
{
	isMine = false;
	isRevealed = false;
	adjacentMines = 0;
}

bool Cell:: hasMines()
{
	return isMine;
}

void Cell:: setMines(bool mine)
{
	isMine = mine;
}

bool Cell::isCellRevealed()
{
	return isRevealed;
}

void Cell:: revealeCell(bool revealed)
{
	isRevealed = revealed;
}

int Cell:: getAdjacentMines()
{
	return adjacentMines;
}

void Cell:: setAdjacentMines(int count)
{
	adjacentMines = count;
}

void Cell::printMines()
{
	cout << (isMine ? "*| " : to_string(adjacentMines) + "| ");
}

void Cell:: display()
{
	cout << (isRevealed ? (isMine ? "*| " : to_string(adjacentMines) + " |") : " -|");
}