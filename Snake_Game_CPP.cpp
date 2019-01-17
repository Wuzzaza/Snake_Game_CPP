#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

const int FPS = 20;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int BIT_RATE = 32;
const int GAME_FIELD_SCALE = 30;
const int GAME_FIELD_SIZE = 20;


int main()
{
	Snake snake(GAME_FIELD_SIZE);

	sf::RenderWindow mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_RATE), "SnakeGame");
	mainWindow.setFramerateLimit(FPS);

	sf::Event ev;
	while (mainWindow.isOpen())
	{
		while (mainWindow.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				mainWindow.close();

			if (ev.type == sf::Event::KeyPressed) {
				if (ev.key.code == sf::Keyboard::Escape) 
					mainWindow.close();
			}


		}
		
		snake.move();

		mainWindow.clear();
		
		for (Cell cell: snake.cellList)
		{
			sf::RectangleShape newRectangle(sf::Vector2f(GAME_FIELD_SCALE, GAME_FIELD_SCALE));
			newRectangle.setPosition(cell.x * GAME_FIELD_SCALE, cell.y * GAME_FIELD_SCALE);
			newRectangle.setFillColor(sf::Color::Green);
			mainWindow.draw(newRectangle);
		}

		
		mainWindow.display();
	}
}
