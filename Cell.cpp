#include "pch.h"

Cell::Cell()
{
}

Cell::Cell(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Cell::setPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}


Cell::~Cell()
{
}
