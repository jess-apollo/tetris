#include <iostream>
#include <fstream>
#include "curses.h"
#include "Block.h"

#define KEY_SPACE 32

class CGame
{
private:
	WINDOW *win1; 
	WINDOW *win2;
	WINDOW *win3; 
	
	Block *block[7];
	int x, y; 
	int board[18][10];
	int score,	
		type;			//block의 형태
public:
	CGame(char *user);

	void printGameBoard();				//게임보드 출력
	void printResult();					//게임 종료시 점수 출력
	void printScore();					//실시간 점수 출력(Score window)
	bool checkCollision(int x, int y);	//충돌 검사
	int moveBlock(int dir);				//키 입력받기
	void checkLine();

	~CGame();
};