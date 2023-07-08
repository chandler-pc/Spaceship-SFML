#pragma once
#include <string>
#include <list>
#include <unordered_map>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../../Enums.h"

namespace sf{
	class Texture;
	class RectangleShape;
	class RenderWindow;
}

class Bullet;

class Player {
	private:
		sf::Texture* pTexture;
		sf::RectangleShape* pShape;
		int pLife;
		std::string pName;
		sf::Vector2f pPosition;
		float pAngleRotation;
		float pSpeed;
		sf::Color pColor;
		float pDelayShoot;
		float pActualDelayShoot;
		std::unordered_map<sf::Keyboard::Key,bool> pKeys;
		PlayerType pType;
		std::list<Bullet*> pBullets;
		void move(float);
		void updateShape();
		void checkScreenSpace();
		void shoot();
	public:
		Player(int, std::string, sf::Vector2f, float, float, sf::Color, float, PlayerType);
		~Player();
		int getLife(){return pLife;}
		std::string getName(){return pName;}
		sf::RectangleShape* getShape(){return pShape;}
		void draw(sf::RenderWindow*);
		void setPosition(sf::Vector2f);
		void addAngleRotation(float);
		void makeDamage(int);
		void eventInput(sf::Keyboard::Key, bool);
		void update(float);
};



