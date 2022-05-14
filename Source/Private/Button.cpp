#include "../Public/Button.h"

void Button::config(std::string text, sf::Vector2f pos, sf::Color backColor, sf::Color hoverColor, sf::Color pressColor){
    this->text = text;
	this->pos = pos;
	this->backColor = backColor;
	this->hoverColor = hoverColor;
	this->pressColor = pressColor;
	bgBtn.setFillColor(backColor);
	bgBtn.setPosition(pos);
	bgBtn.setSize(sf::Vector2f(300,100));
}

void Button::display(sf::RenderWindow &window) {
	window.draw(bgBtn);
}

void Button::onHover(sf::Vector2i cursor){
	if(bgBtn.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursor))){
		bgBtn.setFillColor(this->hoverColor);
	}
}