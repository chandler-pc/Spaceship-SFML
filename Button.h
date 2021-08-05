#pragma once
#include <SFML/Graphics.hpp>

class Button {
	private:
		std::string text;
		sf::Vector2f pos;
		sf::Color backColor;
		sf::Color hoverColor;
		sf::Color pressColor;
	public:
		Button(std::string, sf::Vector2f, sf::Color, sf::Color, sf::Color);
		void Display(sf::RenderWindow &window);
};

Button::Button(std::string text, sf::Vector2f pos, sf::Color backColor, sf::Color hoverColor, sf::Color pressColor) {
	this->text = text;
	this->pos = pos;
	this->backColor = backColor;
	this->hoverColor = hoverColor;
	this->pressColor;
}

void Button::Display(sf::RenderWindow &window) {

}