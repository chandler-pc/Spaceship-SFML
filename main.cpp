#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"

void Menu();

int main() {
	Game game;
	game.Run();
	//Menu();
	return 0;
}

void Menu() {
	sf::RenderWindow menuWin(sf::VideoMode(800, 800), "Menu", sf::Style::Close);
	menuWin.setFramerateLimit(60);
	while (menuWin.isOpen()) {
		sf::Event eventmenu;
		if (menuWin.pollEvent(eventmenu)) {
			if (eventmenu.type == sf::Event::Closed) {
				menuWin.close();
			}
		}
		menuWin.clear(sf::Color::Black);
		menuWin.display();
	}
}