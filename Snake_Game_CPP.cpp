

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

const int FPS = 60;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int BIT_RATE = 32;


int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_RATE), "SnakeGame");
	mainWindow.setFramerateLimit(FPS);

	sf::Event ev;
	while (mainWindow.isOpen())
	{
		while (mainWindow.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				mainWindow.close();
		}
		mainWindow.display();
	}
}
