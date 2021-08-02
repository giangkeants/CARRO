#pragma once
#include"Caro.h"
#include"Point.h"
extern bool _TURN;
extern int _COMMAND;
extern int _X, _Y;
class Board 
{
private:
	int _size;
	int _left, _top;
	_Point** _pArr;
public:
	Board(int, int, int);
	
	void DrawBoard(int);
	void Draw4corner(int);
	void DrawOUTLine(int);
	void DrawINLine(int);
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard();
	~Board();
};