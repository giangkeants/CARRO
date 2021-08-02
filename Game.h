#include"Caro.h"
#include"Board.h"
#include"DataUser.h"
class _Game {

	Board* _b;// a board game
	bool _turn;// turn: true for the 1
	int _x, _y; // current position of cursor
	int _command; // input-key from the players
	bool _loop; // decision bool variable to exit game or not
public:

	_Game(int, int, int);
	int getCommand();
	bool isContinue();
	char waitKeyBoard(); // Receiving keyboard from players
	char askContinue();
	void startGame(); // Function to start the game
	void Show_Selection(int);
	void Selection();
	void NewGame();
	void exitGame();
	int processFinish();
	bool processCheckBoard();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	~_Game();

};