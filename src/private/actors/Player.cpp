#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include "../../public/actors/Bullet.h"
#include "../../public/actors/Player.h"

Player::Player(int life, std::string name, sf::Vector2f pos, float rot, float speed, sf::Color color, float delayShoot,PlayerType type) {
	pTexture = new sf::Texture();
	pShape = new sf::RectangleShape();
	
	pLife = life;
	pName = name;
	pPosition = pos;
	pAngleRotation = rot;
	pTexture->loadFromFile("./assets/Player.png");
	pShape->setSize(sf::Vector2f(64, 40));
	pShape->setTexture(pTexture);
	pShape->setOutlineColor(sf::Color::Green);
	pShape->setOutlineThickness(0);
	pSpeed = speed;
	pColor = color;
	pShape->setPosition(pos);
	pShape->setOrigin(sf::Vector2f(32, 20));
	pShape->setFillColor(color);
	pDelayShoot = delayShoot;
	pActualDelayShoot = 0;
	pKeys[sf::Keyboard::W] = false;
	pKeys[sf::Keyboard::S] = false;
	pKeys[sf::Keyboard::A] = false;
	pKeys[sf::Keyboard::D] = false;
	pKeys[sf::Keyboard::Space] = false;
	pType = type;
}

Player::~Player() {
	delete pTexture;
	delete pShape;
	pTexture = nullptr;
	pShape = nullptr;
}

void Player::eventInput(sf::Keyboard::Key key, bool isPress) {
	auto iter = pKeys.find(key);
    if (iter != pKeys.end()) {
		iter->second = isPress;
    }
}

void Player::update(float dt){
	move(dt);
	if(pActualDelayShoot > 0){
		pActualDelayShoot -= dt;
	}
	for(auto bullet : pBullets){
		bullet->update(dt);
	}
	updateShape();
	checkScreenSpace();
}

void Player::setPosition(sf::Vector2f NewPosition){
	pPosition.x = NewPosition.x;
	pPosition.y = NewPosition.y;
}

void Player::makeDamage(int Damage){
	pLife -= Damage;
}

void Player::addAngleRotation(float rotation){
	pAngleRotation += rotation;
}

void Player::move(float dt){
	float mov = pSpeed * dt;
	if (pKeys[sf::Keyboard::W]) {
		pPosition.x += mov*sin(pAngleRotation*PI/180);
		pPosition.y -= mov*cos(pAngleRotation*PI/180);
	}
	if (pKeys[sf::Keyboard::S]) {
		pPosition.x -= mov*sin(pAngleRotation*PI/180);
		pPosition.y += mov*cos(pAngleRotation*PI/180);
	}
	/*if (mPlayer.mMoveLeft) {
		movement.x -= mov * cos(mPlayer.GetRot() * PI / 180);
		movement.y -= mov * sin(mPlayer.GetRot() * PI / 180);
	}
	if (mPlayer.mMoveRight) {
		movement.x += mov * cos(mPlayer.GetRot() * PI / 180);
		movement.y += mov * sin(mPlayer.GetRot() * PI / 180);
	}*/
	if (pKeys[sf::Keyboard::A]) {
		pAngleRotation -= mov;
	}
	if (pKeys[sf::Keyboard::D]) {
		pAngleRotation += mov;
	}
	if (pKeys[sf::Keyboard::Space]) {
		if (pActualDelayShoot <= 0) {
			shoot();
			pActualDelayShoot = pDelayShoot;
		}
	}
}

void Player::updateShape(){
	pShape->setPosition(pPosition);
	pShape->setRotation(pAngleRotation);
}

void Player::checkScreenSpace(){
	if (pShape->getPosition().x > 800) {
		pPosition.x = 799;
	}
	if (pShape->getPosition().x < 0) {
		pPosition.x = 0;
	}
	if (pShape->getPosition().y > 800) {
		pPosition.y = 799;
	}
	if (pShape->getPosition().y < 0) {
		pPosition.y = 0;
	}
}

void Player::draw(sf::RenderWindow* window){
	window->draw(*pShape);
	for(auto bullet : pBullets){
		window->draw(*bullet->getShape());
	}
}

void Player::shoot(){
	sf::Vector2f leftPosition = sf::Vector2f(27 * cos(pAngleRotation*PI/180) + 30 * sin(pAngleRotation * PI / 180), 27 * sin(pAngleRotation * PI / 180) - 30 * cos(pAngleRotation * PI / 180));
	sf::Vector2f rightPosition = sf::Vector2f(-27 * cos(pAngleRotation*PI/180) + 30 * sin(pAngleRotation * PI / 180), -27 * sin(pAngleRotation * PI / 180) - 30 * cos(pAngleRotation * PI / 180));
	Bullet* leftBullet = new Bullet(pAngleRotation,pPosition + leftPosition,4,230,pColor,pType);
	Bullet* rightBullet = new Bullet(pAngleRotation,pPosition + rightPosition,4,230,pColor,pType);
	pBullets.push_back(leftBullet);
	pBullets.push_back(rightBullet);
}