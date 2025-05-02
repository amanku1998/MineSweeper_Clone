#pragma once
#include <iostream>
using namespace std;

class Cell
{
private:
	bool isMine;
	bool isRevealed;
	int adjacentMines;

public:
	Cell();
	bool hasMines();
	void setMines(bool mine);
	bool isCellRevealed();
	void revealeCell(bool revealed);
	int getAdjacentMines();
	void setAdjacentMines(int count);
	void display();
};
