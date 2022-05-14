#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
	private:
		sf::RectangleShape bgBtn;
		std::string text;
		sf::Vector2f pos;
		sf::Color backColor;
		sf::Color hoverColor;
		sf::Color pressColor;
	public:
		void config(std::string, sf::Vector2f, sf::Color, sf::Color, sf::Color);
		void display(sf::RenderWindow &window);
		void onHover(sf::Vector2i);
};

#endif