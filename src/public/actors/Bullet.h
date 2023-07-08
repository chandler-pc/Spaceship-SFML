#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include "../../Enums.h"

namespace sf{
	class RectangleShape;
	class Texture;
}

class Bullet {
	private:
		float bulletRotation;
		sf::Vector2f bulletPosition;
		sf::RectangleShape* bulletShape;
		sf::Texture* bulletTexture;
		float bulletLifeTime;
		float bulletSpeed;
		sf::Color bulletColor;
		PlayerType playerType;
	public:
		Bullet(float, sf::Vector2f, float, float, sf::Color, PlayerType);
		sf::RectangleShape* getShape(){return bulletShape;}
		PlayerType getPlayerType(){return playerType;}
		void update(float);
};

