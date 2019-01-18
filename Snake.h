#pragma once
class Snake
{

public:
	enum Directions{UP, RIGHT, DOWN, LEFT};
	int gameFieldSize;
	std::list<Cell> cellList;
	Directions direction;
	Cell apple;


	Snake(int gameFieldSize);
	~Snake();
	
	Cell nextCell();
	void move();
	bool changeDirection(Directions newDirection);
	void resetApple();
};


