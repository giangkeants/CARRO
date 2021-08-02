#include "Caro.h"
#include"Board.h"
#include"Game.h"
#include"Point.h"
int main()
{
	BOOL WINAPI SetConsoleTitle(_In_ LPCTSTR lpConsoleTitle);
	SetConsoleTitle(L"Game Caro");
	int pX, pY, pTurn;
	_Common::fixConsoleWindow();
	
		_Game g(BOARD_SIZE, LEFT, TOP); // You yourself define some constants
	
		g.startGame();
		g.Selection();
	
		while (g.isContinue()) {
			
				g.waitKeyBoard();
			
				if (g.getCommand() == 27) g.exitGame();
			
				else 
				{
						switch (g.getCommand()) {
						 case 'A':							
								g.moveLeft();							
								break;							
						case 'W':							
								g.moveUp();							
								break;							
						case 'S':
								g.moveDown();
								break;							
						case 'D':
							 g.moveRight();
							 break;
						 case 13:
							
								//Mark the board, then check and process win/lose/draw/continue
								
								if (g.processCheckBoard()) {
									
										switch (g.processFinish()) {
											
										case -1: case 1: case 0:
												if (g.askContinue() != 'Y') g.exitGame();
												else g.startGame();
										}
								}							
						}					
				}			
		}
	return 0;
}