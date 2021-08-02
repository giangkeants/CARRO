#include"DataUser.h"
void Data_user::Input_user()
{
	system("cls");
	Data_user player1, player2, Player1[11], Player2[11];
	_Common::gotoXY(59 - 3, 14);
	cout << "PLAYER 1";
	_Common::gotoXY(59 - 5, 16);
	cout << "NAME: ";
	cin >> player1.name;
	_Common::gotoXY(59 - 3, 18);
	cout << "PLAYER 2";
	_Common::gotoXY(59 - 5, 20);
	cout << "NAME: ";
	cin >> player2.name;
	//NewGame();
}