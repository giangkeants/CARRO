#ifndef _Caro_
#define _Caro_
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#define BOARD_SIZE 14
#define LEFT 2
#define TOP 1
#define Color_Grey			248
#define Color_Blue			249
#define Color_Green			250
#define Color_Cyan			11
#define Color_Red			4
#define Color_Pink			253
#define Color_Yellow		254
#define Color_White			7
#define default_ColorCode		240
using namespace std;
class _Common {
public:
		static void fixConsoleWindow();
		static void gotoXY(int, int);
		void remove_scrollbar();
		static void SetColor(int backgound_color, int text_color);
		static void ShowConsoleCursor(bool);
		int getCursorX();
		int getCursorY(); 
		void changeFont(int x);
		
};




#endif // !