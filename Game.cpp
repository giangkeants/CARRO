#include"Game.h"
_Game::_Game(int pSize, int pLeft, int pTop) {
	_b = new Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = true; // Assign turn and default key
	_x = pLeft; _y = pTop;
}
_Game::~_Game() { delete _b; }

int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 4);
	return waitKeyBoard();
}
void _Game::Show_Selection(int selection)
{
	int U = 57, T = 12;
	switch (selection)
	{
	case 1:
		_Common::gotoXY(51, T + 4);
		_Common::SetColor(0, Color_Cyan);
		cout << "       EXIT       ";
		_Common::gotoXY(U - 1 - 5, T);
		_Common::SetColor(0, Color_White);
		cout << ">>   NEW GAME   <<";
		_Common::gotoXY(51, T + 1);
		_Common::SetColor(0, Color_Cyan);
		cout << "       LOAD       ";
		_Common::ShowConsoleCursor(0);
		break;
	case 2:
		_Common::gotoXY(U - 1 - 5, T);
		_Common::SetColor(0, Color_Cyan);
		cout << "     NEW GAME     ";
		_Common::gotoXY(51, T + 1);
		_Common::SetColor(0, Color_White);
		cout << ">>     LOAD     <<";
		_Common::ShowConsoleCursor(0);
		_Common::gotoXY(51, T + 2);
		_Common::SetColor(0, Color_Cyan);
		cout << "     SETTINGS     ";
		break;
	case 3:
		_Common::gotoXY(51, T + 1);
		_Common::SetColor(0, Color_Cyan);
		cout << "       LOAD       ";
		_Common::gotoXY(51, T + 2);
		_Common::SetColor(0, Color_White);
		cout << ">>   SETTINGS   <<";
		_Common::gotoXY(51, T + 3);
		_Common::SetColor(0, Color_Cyan);
		cout << "       GUIDE      ";
		_Common::ShowConsoleCursor(0);
		break;
	case 4:
		_Common::gotoXY(51, T + 2);
		_Common::SetColor(0, Color_Cyan);
		cout << "     SETTINGS     ";
		_Common::gotoXY(51, T + 3);
		_Common::SetColor(0, Color_White);
		cout << ">>     GUIDE    <<";
		_Common::gotoXY(51, T + 4);
		_Common::SetColor(0, Color_Cyan);
		cout << "       EXIT       ";
		_Common::ShowConsoleCursor(0);
		break;
	case 5:
		_Common::gotoXY(51, T + 3);
		_Common::SetColor(0, Color_Cyan);
		cout << "       GUIDE      ";
		_Common::gotoXY(51, T + 4);
		_Common::SetColor(0, Color_White);
		cout << ">>     EXIT     <<";
		_Common::gotoXY(U - 1 - 5, T);
		_Common::SetColor(0, Color_Cyan);
		cout << "     NEW GAME     ";
		_Common::ShowConsoleCursor(0);
		break;
	}
}
void _Game::Selection()
{
	int selection = 1;

	int T = 12, U = 57;
	_Common::gotoXY(U - 1 - 5, T);
	_Common::SetColor(0, Color_White);
	cout << ">>   NEW GAME   <<";
	_Common::ShowConsoleCursor(0);

	while (1)
	{
		char key = toupper(_getch());
		if (key == 'W' || key == 72)
		{
			if (selection > 1)
			{
				selection--;
			}
			else selection = 5;
		}
		if (key == 'S' || key == 80)
		{
			if (selection < 5)
			{
				selection++;
			}
			else selection = 1;
		}

		//51
		Show_Selection(selection);//ở trên
		if (key == 13 || key == 32)
		{
			switch (selection)
			{
			case 1:
				Data_user::Input_user();//MAIN_GAME->GAME->MAIN_GAME.cpp
				break;
			case 5:
				system("cls");
				exit(0);
				break;
			}

		}
	}
}
void _Game::startGame() {

	system("cls");
	//_b->resetData(); // Setting the original data
	//_b->drawBoard(); // Draw boad
	//_x = _b->getXAt(0, 0);
	//_y = _b->getYAt(0, 0);
	int U = 13, T = 3;
	_Common::SetColor(0, Color_Red);
	_Common::gotoXY(U, T);
	cout << "	     ::::::::      :::     :::::::::   ::::::::          ::::::::      :::       :::   :::   :::::::::: " << endl;
	_Common::gotoXY(U, T + 1);
	cout << "	    :+:    :+:   :+: :+:   :+:    :+: :+:    :+:        :+:    :+:   :+: :+:    :+:+: :+:+:  :+:         " << endl;
	_Common::gotoXY(U, T + 2);
	cout << "	   +:+         +:+   +:+  +:+    +:+ +:+    +:+        +:+         +:+   +:+  +:+ +:+:+ +:+ +:+          " << endl;
	_Common::gotoXY(U, T + 3);
	cout << "	  +#+        +#++:++#++: +#++:++#:  +#+    +:+        :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#      " << endl;
	_Common::gotoXY(U, T + 4);
	cout << "	 +#+        +#+     +#+ +#+    +#+ +#+    +#+        +#+   +#+# +#+     +#+ +#+       +#+ +#+            " << endl;
	_Common::gotoXY(U, T + 5);
	cout << "	#+#    #+# #+#     #+# #+#    #+# #+#    #+#        #+#    #+# #+#     #+# #+#       #+# #+#             " << endl;
	_Common::gotoXY(U, T + 6);
	cout << "	########  ###     ### ###    ###  ########          ########  ###     ### ###       ### ##########       " << endl;
	T = 12, U = 57;
	_Common::SetColor(0, Color_Cyan);
	_Common::gotoXY(U - 1, T);
	cout << "NEW GAME";
	_Common::gotoXY(U + 1, T + 1);
	cout << "LOAD";
	_Common::gotoXY(U - 1, T + 2);
	cout << "SETTINGS";
	_Common::gotoXY(U - 1 + 2, T + 3);
	cout << "GUIDE";
	_Common::gotoXY(U + 1, T + 4);
	cout << "EXIT";
}
void _Game::NewGame()
{

}
void _Game::exitGame() {
	system("cls");
	//Maybe save game before stopping
	_loop = false;

}
bool _Game::processCheckBoard() {
	switch (_b->checkBoard(_x, _y, _turn)) {
	case -1:
		printf("X");
		break;
	case 1:
		printf("O");
		break;
	case 0:
		return false; // Tick the cell marked 
	}
	return true;
}
int _Game::processFinish()
{
	// Move to the reasonable place to print string win/lose/draw
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
	int pWhoWin = _b->testBoard();
	switch (pWhoWin)
	{
	case -1:
		printf("The player %d won and the player %d lost\n", true, false);
		break;
	case 1:
		printf("The player %d won and the player %d lost\n", false, true);
		break;
	case 0:
		printf("The player %d draw with the player %d\n", false, true);
		break;
	case 2:
		_turn = !_turn; // change turn if nothing happen
	}
	_Common::gotoXY(_x, _y);// Return the current position of cursor
	return pWhoWin;
}
void _Game::moveRight() {
	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_x += 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveLeft() {
	if (_x > _b->getXAt(0, 0)) {
		_x -= 4;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveDown() {
	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {
		_y += 2;
		_Common::gotoXY(_x, _y);
	}
}
void _Game::moveUp() {
	if (_y > _b->getYAt(0, 0)) {
		_y -= 2;
		_Common::gotoXY(_x, _y);
	}
}
