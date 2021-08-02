#include"Board.h"

Board::Board(int pSize, int pX, int pY) {
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point * [pSize];
	for (int i = 0; i < pSize; i++)
	{
		_pArr[i] = new _Point[pSize];
	}
}
void Board::Draw4corner(int pSize)
{
	_Common::gotoXY(0, 0);
	cout << (char)201;
	_Common::gotoXY(0, TOP + pSize * 2 - 1);
	cout << (char)200;
	_Common::gotoXY(LEFT + (pSize - 1) * 4 + 2, 0);
	cout << (char)203;
	_Common::gotoXY(LEFT + (pSize - 1) * 4 + 2, TOP + (pSize - 1) * 2 + 1);
	cout << (char)188;
	_Common::gotoXY(LEFT + (pSize - 1) * 4 + 2, 14);
	cout << (char)215;
	_Common::gotoXY(119, 0);
	cout << (char)187;
	_Common::gotoXY(119, 2 * pSize);
	cout << (char)188;
	_Common::gotoXY(LEFT + (pSize - 1) * 4 + 2, 2 * pSize);
	cout << (char)202;
}
void Board::DrawOUTLine(int pSize)
{
	for (int i = 1; i <= (pSize - 1) * 2 + 1; i++)
	{
		_Common::gotoXY(0, i);
		if (i % 2 != 0) cout << (char)186;
		if (i % 2 == 0) cout << (char)199;
		_Common::gotoXY(LEFT + (pSize - 1) * 4 + 2, i);
		if (i % 2 != 0) cout << (char)186;
		if (i % 2 == 0) cout << (char)182;
		if (i == 2)
		{
			_Common::gotoXY(LEFT + (pSize - 1) * 4 + 2, i);
			cout << (char)215;
		}
	}
	for (int i = 1; i <= LEFT + (pSize - 1) * 4 + 1; i++)
	{
		_Common::gotoXY(i, 0);
		if (i % 4 != 0) cout << (char)205;
		else cout << (char)209;
		_Common::gotoXY(i, TOP + (pSize - 1) * 2 + 1);
		if (i % 4 != 0) cout << (char)205;
		else cout << (char)207;
	}
	for (int i = LEFT + (pSize - 1) * 4 + 3; i < 119; i++)
	{
		_Common::gotoXY(i, 0);
		cout << (char)205;
		_Common::gotoXY(i, 14);
		cout << (char)196;
		_Common::gotoXY(i, 2 * pSize);
		cout << (char)205;
	}
	_Common::gotoXY(31 + 60 - 3, 0);
	cout << (char)203;
	for (int i = 1; i <= (2 * pSize - 1) + 1; i++)
	{
		if (i <= pSize) {
			_Common::gotoXY(31 + 60 - 3, i);
			cout << (char)186;
		}
		if (i == 14) { _Common::gotoXY(31 + 60 - 3, i); cout << (char)208; }
		_Common::gotoXY(119, i);
		cout << (char)186;
		if (i == 14)
		{
			_Common::gotoXY(119, i);
			cout << (char)182;
		}
		if (i == 18)
		{
			_Common::gotoXY(LEFT + 4 * (pSize - 1) + 2, i);
			cout << (char)215;
			_Common::gotoXY(119, i);
			cout << (char)182;
		}
	}
}
void Board::DrawINLine(int pSize)
{
	for (int i = 1; i <= pSize - 1; i++)
	{
		for (int j = 1; j <= TOP + (pSize - 1) * 2; j++)
		{
			_Common::gotoXY(i * 4, j);
			if (j % 2 != 0) cout << (char)179;
			else cout << (char)197;
		}
	}
	for (int i = 1; i <= pSize - 1; i++)
	{
		for (int j = 1; j <= LEFT + (pSize - 1) * 4 + 1; j++)
		{
			_Common::gotoXY(j, i * 2);
			if (j % 4 != 0) cout << (char)196;
		}
	}
	for (int j = LEFT + (pSize - 1) * 4 + 3; j < 60 + 30 * 2 - 1; j++)
	{
		_Common::gotoXY(j, 2);
		if (j != 60 + 28)cout << (char)196;
		if (j == 60 + 28) cout << (char)215;
		_Common::gotoXY(j, 18);
		cout << (char)196;

	}
}
int Board::getSize() { return _size; }
int Board::getLeft() { return _left; }
int Board::getTop() { return _top; }
int Board::getXAt(int i, int j)
{
	return _pArr[i][j].getX();
}
int Board::getYAt(int i, int j)
{
	return _pArr[i][j].getY();
}


void Board::resetData()
{
	if (_size == 0) return; // Firstly calling constructor before calling resetData

	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // x-value of boardgame
			_pArr[i][j].setY(2 * i + _top + 1); // y-value of boardgame
			_pArr[i][j].setCheck(0);
		}
	}
}
void Board::drawBoard() {
	if (_pArr == NULL) return; // firstly call constructor
	for (int i = 0; i <= _size; i++) {
		for (int j = 0; j <= _size; j++) {
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			printf(".");
		}
	}
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());//move to the 1
}
int Board::checkBoard(int pX, int pY, bool pTurn) {
	for (int i = 0; i < _size; i++) {

		for (int j = 0; j < _size; j++) {


			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0)
			{
				if (pTurn)
				{
					_pArr[i][j].setCheck(-1);// If current turn is true: c = -1
				}
				else
				{
					_pArr[i][j].setCheck(1);// If current turn is false: c = 1

				}

				return _pArr[i][j].getCheck();

			}

		}

	}
	return 0;
}
int Board::testBoard()
{
	return 1;

}
Board ::~Board()
{
	for (int i = 0; i < _size; i++) delete[] _pArr[i];
	delete[] _pArr;
}