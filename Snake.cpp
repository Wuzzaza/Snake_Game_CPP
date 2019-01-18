#include "pch.h"
#include "Snake.h"
#include "Cell.h"

Snake::Snake(int gameFieldSize)
{
	this->gameFieldSize = gameFieldSize;
	this->resetApple();
	for (int i = 0; i < 4; i++) cellList.push_back(Cell(10, 10 + i));
	direction = UP;
}

Snake::~Snake()
{
}

void Snake::move()
{
	cellList.push_front(nextCell());
	cellList.pop_back();
}

bool Snake::changeDirection(Directions newDirection)
{
	if (newDirection == UP && direction != DOWN) direction = newDirection;
	if (newDirection == LEFT && direction != RIGHT) direction = newDirection;
	if (newDirection == DOWN && direction != UP) direction = newDirection;
	if (newDirection == RIGHT && direction != LEFT) direction = newDirection;

	return false;
}

Cell Snake::nextCell()
{
	Cell nextCell = this->cellList.front();
	switch (direction)
	{
	case Snake::UP:
		if (nextCell.y == 0) nextCell.y = gameFieldSize;
			else nextCell.y--;
		break;

	case Snake::RIGHT:
		if (nextCell.x == gameFieldSize) nextCell.x = 0;
		else nextCell.x++;		
		break;

	case Snake::DOWN:
		if (nextCell.y == gameFieldSize) nextCell.y = 0;
		else nextCell.y++;
		break;

	case Snake::LEFT:
		if (nextCell.x == 0) nextCell.x = gameFieldSize;
		else nextCell.x--;
		break;

	default:
		break;
	}
	return nextCell;
}

void Snake::resetApple()
{
	this->apple.setPosition((int)(rand() % gameFieldSize), (int)(rand() % gameFieldSize));
}
