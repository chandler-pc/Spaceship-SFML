#include <SFML/Graphics.hpp>
#include <cmath>
#include "../../public/actors/Bullet.h"

Bullet::Bullet(float rot, sf::Vector2f pos, float time, float speed, sf::Color color, PlayerType type) {
	bulletTexture = new sf::Texture();
	bulletShape = new sf::RectangleShape(sf::Vector2f(4, 12));
	bulletRotation = rot;
	bulletPosition = pos;
	bulletLifeTime = time;
	bulletSpeed = speed;
	bulletTexture->loadFromFile("./assets/Bullet.png");
	bulletShape->setTexture(bulletTexture);
	bulletShape->setOrigin(2, 6);
	bulletShape->setPosition(pos);
	bulletShape->setRotation(rot);
	bulletShape->setFillColor(color);
	bulletColor = color;
    playerType = type;
}

void Bullet::update(float dt){
	bulletPosition.x += sin(bulletRotation * PI / 180) * bulletSpeed * dt;
	bulletPosition.y -= cos(bulletRotation * PI / 180) * bulletSpeed * dt;
	bulletShape->setPosition(bulletPosition);
	bulletLifeTime -= dt;
}