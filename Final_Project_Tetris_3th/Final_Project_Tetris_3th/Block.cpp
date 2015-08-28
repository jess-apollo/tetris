/*************************************
*                                    *
*	ÇÐ¹ø: 20123341                   *
*   ÀÌ¸§: ±è»óÈÆ                     *
*                                    *
**************************************/

#include "Block.h"

void Block::initialize()
{
	for(int i=0; i < WIDTH; i++)
		for(int j=0; j < WIDTH; j++)
			temp[i][j] = 0;
}

void Block::setBlock(int value, int x, int y)
{
	if(x < 0 || y < 0 || x >= WIDTH || y >= WIDTH) return;
	
	temp[x][y] = value;
}

int Block::getBlock(int x, int y)
{
	if(x < 0 || y < 0 || x >= WIDTH || y >= WIDTH) return 0;
	return temp[x][y];
}

void OBlock::rotate()
{
	switch(rotation)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		initialize();
		setBlock(10, 0, 0);
		setBlock(10, 0, 1);
		setBlock(10, 1, 0);
		setBlock(10, 1, 1);
		rotation = ++rotation % 4;
		break;
	}
}

//11
void LBlock::rotate()
{
	switch(rotation)
	{
	case 0:
		initialize();
		setBlock(11, 0, 1);
		setBlock(11, 1, 1);
		setBlock(11, 2, 1);
		setBlock(11, 2, 2);
		rotation = ++rotation % 4;
		break;
	case 1:
		initialize();
		setBlock(11, 0, 2);
		setBlock(11, 1, 0);
		setBlock(11, 1, 1);
		setBlock(11, 1, 2);
		rotation = ++rotation % 4;
		break;
	case 2:
		initialize();
		setBlock(11, 0, 0);
		setBlock(11, 0, 1);
		setBlock(11, 1, 1);
		setBlock(11, 2, 1);
		rotation = ++rotation % 4;
		break;
	case 3:
		initialize();
		setBlock(11, 1, 0);
		setBlock(11, 1, 1);
		setBlock(11, 1, 2);
		setBlock(11, 2, 0);
		rotation = ++rotation % 4;
		break;
	}
}

//12
void JBlock::rotate()
{
	switch(rotation)
	{
	case 0:
		initialize();
		setBlock(12, 0, 1);
		setBlock(12, 1, 1);
		setBlock(12, 2, 1);
		setBlock(12, 2, 0);
		rotation = ++rotation % 4;
		break;
	case 1:
		initialize();
		setBlock(12, 1, 0);
		setBlock(12, 1, 1);
		setBlock(12, 1, 2);
		setBlock(12, 2, 2);
		rotation = ++rotation % 4;
		break;
	case 2:
		initialize();
		setBlock(12, 0, 1);
		setBlock(12, 0, 2);
		setBlock(12, 1, 1);
		setBlock(12, 2, 1);
		rotation = ++rotation % 4;
		break;
	case 3:
		initialize();
		setBlock(12, 0, 0);
		setBlock(12, 1, 0);
		setBlock(12, 1, 1);
		setBlock(12, 1, 2);
		rotation = ++rotation % 4;
		break;
	}
}

//13
void SBlock::rotate()
{
	switch(rotation)
	{
	case 0:
	case 2:
		initialize();
		setBlock(13, 0, 1);
		setBlock(13, 1, 1);
		setBlock(13, 1, 2);
		setBlock(13, 2, 2);
		rotation = ++rotation % 4;
		break;
	case 1:
	case 3:
		initialize();
		setBlock(13, 0, 1);
		setBlock(13, 0, 2);
		setBlock(13, 1, 0);
		setBlock(13, 1, 1);
		rotation = ++rotation % 4;
		break;
	}
}

//14
void ZBlock::rotate()
{
	switch(rotation)
	{
	case 0:
	case 2:
		initialize();
		setBlock(14, 0, 1);
		setBlock(14, 1, 0);
		setBlock(14, 1, 1);
		setBlock(14, 2, 0);
		rotation = ++rotation % 4;
		break;
	case 1:
	case 3:
		initialize();
		setBlock(14, 0, 0);
		setBlock(14, 0, 1);
		setBlock(14, 1, 1);
		setBlock(14, 1, 2);
		rotation = ++rotation % 4;
		break;
	}
}

//15
void TBlock::rotate()
{
	switch(rotation)
	{
	case 0:
		initialize();
		setBlock(15, 0, 1);
		setBlock(15, 1, 0);
		setBlock(15, 1, 1);
		setBlock(15, 1, 2);
		rotation = ++rotation % 4;
		break;
	case 1:
		initialize();
		setBlock(15, 0, 1);
		setBlock(15, 1, 0);
		setBlock(15, 1, 1);
		setBlock(15, 2, 1);
		rotation = ++rotation % 4;
		break;
	case 2:
		initialize();
		setBlock(15, 1, 0);
		setBlock(15, 1, 1);
		setBlock(15, 1, 2);
		setBlock(15, 2, 1);
		rotation = ++rotation % 4;
		break;
	case 3:
		initialize();
		setBlock(15, 0, 1);
		setBlock(15, 1, 1);
		setBlock(15, 1, 2);
		setBlock(15, 2, 1);
		rotation = ++rotation % 4;
		break;
	}
}

//16
void IBlock::rotate()
{
	switch(rotation)
	{
	case 0:
	case 2:
		initialize();
		setBlock(16, 0, 1);
		setBlock(16, 1, 1);
		setBlock(16, 2, 1);
		setBlock(16, 3, 1);
		rotation = ++rotation % 4;
		break;
	case 1:
	case 3:
		initialize();
		setBlock(16, 1, 0);
		setBlock(16, 1, 1);
		setBlock(16, 1, 2);
		setBlock(16, 1, 3);
		rotation = ++rotation % 4;
		break;
	}
}