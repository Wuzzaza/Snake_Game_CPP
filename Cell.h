#pragma once
class Cell
{
public:
	int x;
	int y;

	Cell();
	Cell(int x, int y);

	void setPosition(int x, int y);

	~Cell();
};

