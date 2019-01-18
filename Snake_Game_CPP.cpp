#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake_Game_CPP.h"

const int FPS = 10;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 640;
const int BIT_RATE = 32;
const int GAME_FIELD_SCALE = 30;
const int GAME_FIELD_SIZE = 20;
const int GAME_FIELD_HORIZONTAL_OFFSET = 5;
const int GAME_FIELD_VERTICAL_OFFSET = 5;
const int GAME_FIELD_BORDER_SIZE = 5;


int main()
{
	Snake snake(GAME_FIELD_SIZE);

	sf::RenderWindow mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_RATE), "SnakeGame", sf::Style::None);
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
				if (ev.key.code == sf::Keyboard::Left)
					snake.changeDirection(Snake::LEFT);
				if (ev.key.code == sf::Keyboard::Up)
					snake.changeDirection(Snake::UP);
				if (ev.key.code == sf::Keyboard::Right)
					snake.changeDirection(Snake::RIGHT);
				if (ev.key.code == sf::Keyboard::Down)
					snake.changeDirection(Snake::DOWN);
			}


		}
		
		snake.move();
		mainWindow.clear();

			sf::RectangleShape newRectangle(sf::Vector2f(GAME_FIELD_SCALE * (GAME_FIELD_SIZE + 1)
													   , GAME_FIELD_SCALE * (GAME_FIELD_SIZE + 1)));
			newRectangle.setFillColor(sf::Color::Black);
			newRectangle.setOutlineColor(sf::Color::White);
			newRectangle.setOutlineThickness(GAME_FIELD_BORDER_SIZE);
			newRectangle.setPosition(GAME_FIELD_HORIZONTAL_OFFSET, GAME_FIELD_VERTICAL_OFFSET);
			mainWindow.draw(newRectangle);

			sf::RectangleShape apple(sf::Vector2f(GAME_FIELD_SCALE, GAME_FIELD_SCALE));
			apple.setPosition(GAME_FIELD_HORIZONTAL_OFFSET + snake.apple.x * GAME_FIELD_SCALE,
						      GAME_FIELD_VERTICAL_OFFSET + snake.apple.y * GAME_FIELD_SCALE);
			apple.setFillColor(sf::Color::Red);
			mainWindow.draw(apple);

		for (Cell cell: snake.cellList)
		{
			sf::RectangleShape newRectangle(sf::Vector2f(GAME_FIELD_SCALE, GAME_FIELD_SCALE));
			newRectangle.setPosition(GAME_FIELD_HORIZONTAL_OFFSET + cell.x * GAME_FIELD_SCALE, 
									 GAME_FIELD_VERTICAL_OFFSET + cell.y * GAME_FIELD_SCALE);
			newRectangle.setFillColor(sf::Color::Green);
			mainWindow.draw(newRectangle);
		}

		
		mainWindow.display();
	}

}


