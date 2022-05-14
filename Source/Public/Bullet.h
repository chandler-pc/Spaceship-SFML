#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
	private:
		float rot;
		sf::Vector2f pos;
		sf::RectangleShape collider;
		sf::Texture texture;
		float time;
		float speed;
		sf::Color color;
	public:
		Bullet(float, sf::Vector2f, float, float, sf::Color);
		float GetTime();
		float GetSpeed();
		float GetRot();
		sf::Vector2f GetPos();
		void SetTime(float);
		void SetPos(sf::Vector2f);
		sf::RectangleShape GetShape(); 
		sf::Color GetColor();
};

Bullet::Bullet(float rot, sf::Vector2f pos, float time, float speed, sf::Color color) {
	this->rot = rot;
	this->pos = pos;
	this->time = time;
	this->speed = speed;
	this->texture.loadFromFile("./Assets/Bullet.png");
	this->collider.setTexture(&texture);
	this->collider.setSize(sf::Vector2f(4, 12));
	this->collider.setOrigin(2, 6);
	this->collider.setPosition(pos);
	this->collider.setRotation(rot);
	this->color = color;
	this->collider.setFillColor(color);
}

void Bullet::SetTime(float time) {
	this->time = time;
}
void Bullet::SetPos(sf::Vector2f pos) {
	this->pos = pos;
	collider.setPosition(pos);
}
sf::RectangleShape Bullet::GetShape() {
	return this->collider;
}

float Bullet::GetTime() {
	return time;
}

float Bullet::GetSpeed() {
	return this->speed;
}

float Bullet::GetRot() {
	return this->rot;
}
sf::Vector2f Bullet::GetPos() {
	return this->pos;
}

sf::Color Bullet::GetColor() {
	return color;
}