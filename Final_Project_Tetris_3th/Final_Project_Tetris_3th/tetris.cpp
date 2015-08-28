/*************************************
*                                    *
*	«–π¯: 20123341                   *
*   ¿Ã∏ß: ±ËªÛ»∆                     *
*                                    *
**************************************/

#include "tetris.h"

CGame::CGame(char *user)
{	
	initscr();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();

	type = rand() % 7;

	//∫Ì∂Ù ¿˙¿Â
	block[0] = new OBlock;
	block[1] = new LBlock;
	block[2] = new JBlock;
	block[3] = new SBlock;
	block[4] = new ZBlock;
	block[5] = new TBlock;
	block[6] = new IBlock;

	resize_term(25, 50); 
	start_color(); 
	init_pair(1, COLOR_GREEN, COLOR_BLACK); 
	init_pair(2, COLOR_YELLOW, COLOR_BLACK); 

	init_pair(10, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_BLUE, COLOR_BLACK);
	init_pair(12, COLOR_GREEN, COLOR_BLACK);
	init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(14, COLOR_RED, COLOR_BLACK);
	init_pair(15, COLOR_CYAN, COLOR_BLACK);
	init_pair(16, COLOR_WHITE, COLOR_BLACK);

	border('|', '|', '-', '-', '+', '+', '+', '+'); 
	refresh();

	win1 = newwin(20, 22, 2, 2); 

	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = 0;
		}
	}

	x = 0, y = 4;
	printGameBoard();

	win2 = newwin(4, 10, 4, 30); 
	wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+'); 
	wattron(win2, COLOR_PAIR(2)); 
	mvwprintw(win2, 1, 1, "score:");
	wattroff(win2, COLOR_PAIR(2));

	score = 0;
	printScore();

	win3 = newwin(4, 10, 10, 30); 
	wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+'); 
	wattron(win3, COLOR_PAIR(2));
	mvwprintw(win3, 1, 1, "name:");
	mvwprintw(win3, 2, 1, "%s", user);
	wattroff(win3, COLOR_PAIR(2));
	wrefresh(win3);
}

void CGame::printGameBoard()
{
	for(int i = 0; i < 18; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			if(board[i][j] == 0)
			{
				wattron(win1, COLOR_PAIR(1));
				mvwprintw(win1, i + 1, j * 2 + 1, "°‡");
				wattroff(win1, COLOR_PAIR(1));
			}
			else
			{
				wattron(win1, COLOR_PAIR(board[i][j]));
				mvwprintw(win1, i + 1, j * 2 + 1, "°·");
				wattroff(win1, COLOR_PAIR(board[i][j]));
			}
		}
	}

	for(int i = 0; i < 4; i++)
	{
		for(int j=0; j < 4; j++)
		{
			if(block[type]->getBlock(i,j))
			{
				wattron(win1, COLOR_PAIR(block[type]->getBlock(i,j)));
				mvwprintw(win1, i + x + 1, (j + y) * 2 + 1, "°·");
				wattroff(win1, COLOR_PAIR(block[type]->getBlock(i,j)));
			}
		}
	}

	wrefresh(win1);
}

void CGame::printResult()
{
	mvprintw(22, 10, "score is %d", score);
	mvprintw(23, 10, "Press any key to exit Tetris");
}

void CGame::printScore()
{
	wattron(win2, COLOR_PAIR(2));

	mvwprintw(win2, 2, 1, "%d", score);
	wattroff(win2, COLOR_PAIR(2));

	wrefresh(win2);
}

bool CGame::checkCollision(int x, int y) 
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[type]->getBlock(i,j) != 0 && ((x + i) < 0 || x + i > 17 || y + j < 0 || y + j > 9 || board[x + i][y + j] != 0))	
				return true;
		}
	}
	return false;
}

int CGame::moveBlock(int dir)
{
	switch (dir)
	{
	case KEY_DOWN:
		if(!checkCollision(x+1,y)){
			x++;
			break;
		}
		break;
	case KEY_LEFT:
		if(!checkCollision(x,y-1)){
			y -= 1;
			break;
		}
		break;
	case KEY_RIGHT:
		if(!checkCollision(x,y+1)){
			y += 1;
			break;
		}
		break;
	case KEY_SPACE:
		while (!checkCollision(x+1,y))
			x++;
		break;
	case KEY_UP:
		block[type]->rotate();
		break;
	}

	if(checkCollision(x+1,y))		//πÿø° ¥Í¿∏∏È ¿˙¿Â
	{
		for(int i = 0; i < 4; i++)
		{
			for(int j=0; j < 4; j++)
			{
				if(block[type]->getBlock(i,j) != 0)
					board[x+i][y+j] = block[type]->getBlock(i,j);
			}
		}
		x = 0, y = 4;
		type = rand() % 7;



		for (int j = 0; j < 10; j++)
		{
			if (board[0][j] != 0)
			{
				printGameBoard();
				return 1;
			}
		}
	}
	checkLine();
	printScore();
	printGameBoard();

	return 0;
}

void CGame::checkLine()
{
	int i, j, k;
	int check;

	i = 17;

	while (i >= 0)
	{
		check = 1;

		for (j = 0; j<10; j++)
		{
			if (board[i][j] == 0)
			{
				check = 0;
				break;
			}
		}

		if (check == 1)
		{
			score += 1;
			for (k = i - 1; k >= 0; k--)
			{
				for (j = 0; j<10; j++)
				{
					board[k + 1][j] = board[k][j];
				}
			}
			for (j = 0; j<10; j++)
			{
				board[0][j] = 0;
			}

			continue;
		}

		i--;
	}

}

CGame::~CGame()
{
	delwin(win1);
	delwin(win2);
	delwin(win3);
	endwin();
}