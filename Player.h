#pragma once
#include <SFML/Graphics.hpp>

class Player {
	private:
		sf::Texture texture;
		sf::RectangleShape collider;
		int life;
		std::string name;
		sf::Vector2f pos;
		float rot;
		float speed;
		sf::Color color;
		float delayShoot;
	public:
		Player();
		Player(int, std::string, sf::Vector2f, float, float, sf::Color, float);
		~Player();
		void Create(int, std::string, sf::Vector2f, float, float,sf::Color, float);
		int GetLife();
		std::string GetName();
		sf::Vector2f GetPos();
		float GetRot();
		float GetSpeed();
		sf::RectangleShape GetShape();
		void SetLife(int);
		void SetName(std::string);
		void SetPos(sf::Vector2f);
		void SetRot(float);
		void SetDelayShoot(float);
		bool mMoveUp;
		bool mMoveDown;
		bool mMoveRight;
		bool mMoveLeft;
		bool mRotateLeft;
		bool mRotateRight;
		bool mShoot;
		float GetDelayShoot();
};

Player::Player() {
	this->life = 0;
	this->name = "";
	this->pos = sf::Vector2f(0, 0);
	this->rot = 0;
	this->speed = 0;
	this->delayShoot = 0;
}

Player::Player(int life, std::string name, sf::Vector2f pos, float rot, float speed, sf::Color color, float delayShoot) {
	this->life = life;
	this->name = name;
	this->pos = pos;
	this->rot = rot;
	this->texture.loadFromFile("./Assets/Player.png");
	this->collider.setSize(sf::Vector2f(64, 40));
	this->collider.setTexture(&texture);
	this->collider.setOutlineColor(sf::Color::Green);
	this->collider.setOutlineThickness(1);
	this->speed = speed;
	this->color = color;
	mMoveUp = false;
	mMoveDown = false;
	mMoveLeft = false;
	mMoveRight = false; 
	mRotateLeft = false;
	mRotateRight = false; 
	mShoot = false;
	this->collider.setPosition(pos);
	this->collider.setOrigin(sf::Vector2f(32, 20));
	this->collider.setFillColor(color);
	this->delayShoot = delayShoot;
}

Player::~Player() {

}

void Player::Create(int life, std::string name, sf::Vector2f pos, float rot, float speed, sf::Color color, float delayShoot) {
	this->life = life;
	this->name = name;
	this->pos = pos;
	this->rot = rot;
	this->texture.loadFromFile("./Assets/Player.png");
	this->collider.setSize(sf::Vector2f(64, 40));
	this->collider.setTexture(&texture);
	this->collider.setOutlineColor(sf::Color::Green);
	this->collider.setOutlineThickness(1);
	this->speed = speed;
	this->color = color;
	mMoveUp = false;
	mMoveDown = false;
	mMoveLeft = false;
	mMoveRight = false;
	mRotateLeft = false;
	mRotateRight = false;
	mShoot = false;
	this->collider.setPosition(pos);
	this->collider.setOrigin(sf::Vector2f(32,20));
	this->collider.setFillColor(color);
	this->delayShoot = delayShoot;
}

int Player::GetLife() {
	return life;
}

std::string Player::GetName() {
	return name;
}

sf::Vector2f Player::GetPos() {
	return pos;
}

float Player::GetRot() {
	return rot;
}

float Player::GetSpeed() {
	return speed;
}

sf::RectangleShape Player::GetShape() {
	return collider;
}

float Player::GetDelayShoot() {
	return delayShoot;
}

void Player::SetLife(int life) {
	this->life = life;
}

void Player::SetName(std::string name) {
	this->name = name;
}

void Player::SetPos(sf::Vector2f pos) {
	this->pos = pos;
	collider.setPosition(pos);
}

void Player::SetRot(float rot) {
	this->rot = rot;
	collider.setRotation(rot);
}

void Player::SetDelayShoot(float delayShoot) {
	this->delayShoot = delayShoot;
}
