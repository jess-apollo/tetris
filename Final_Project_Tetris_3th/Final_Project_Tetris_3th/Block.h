#include <iostream>
#include <fstream>
#include <ctime>

class Block
{
private:
	static const int WIDTH = 4;
	int temp[WIDTH][WIDTH];
public:
	int rotation;
	void initialize();
	void setBlock(int value, int x, int y);
	int getBlock(int x, int y);
	virtual void rotate() {}
};

class OBlock	: public Block		//Yellow
{
public:
	OBlock()
	{
		initialize();
		rotation = 0;
		setBlock(10, 0, 0);
		setBlock(10, 0, 1);
		setBlock(10, 1, 0);
		setBlock(10, 1, 1);
	}
	virtual void rotate();
};

class LBlock	: public Block		//Blue
{
public:
	LBlock()
	{
		initialize();
		rotation = 0;
		setBlock(11, 0, 1);
		setBlock(11, 1, 1);
		setBlock(11, 2, 1);
		setBlock(11, 2, 2);
	}
	virtual void rotate();
};

class JBlock	: public Block		//Green
{
public:
	JBlock()
	{
		initialize();
		rotation = 0;
		setBlock(12, 0, 1);
		setBlock(12, 1, 1);
		setBlock(12, 2, 1);
		setBlock(12, 2, 0);
	}
	virtual void rotate();
};

class SBlock	: public Block		//Magenta
{
public:
	SBlock()
	{
		initialize();
		rotation = 0;
		setBlock(13, 0, 1);
		setBlock(13, 1, 1);
		setBlock(13, 1, 2);
		setBlock(13, 2, 2);
	}
	virtual void rotate();
};

class ZBlock	: public Block		//Red
{
public:
	ZBlock()
	{
		initialize();
		rotation = 0;
		setBlock(14, 0, 1);
		setBlock(14, 1, 0);
		setBlock(14, 1, 1);
		setBlock(14, 2, 0);
	}
	virtual void rotate();
};

class TBlock	: public Block		//Cyan
{
public:
	TBlock()
	{
		initialize();
		rotation = 0;
		setBlock(15, 0, 1);
		setBlock(15, 1, 0);
		setBlock(15, 1, 1);
		setBlock(15, 1, 2);
	}
	virtual void rotate();
};

class IBlock	: public Block		//White
{
public:
	IBlock()
	{
		initialize();
		rotation = 0;
		setBlock(16, 0, 1);
		setBlock(16, 1, 1);
		setBlock(16, 2, 1);
		setBlock(16, 3, 1);
	}
	virtual void rotate();
};