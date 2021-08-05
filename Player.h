#pragma once
#include <SFML/Graphics.hpp>

class Player {
	private:
		sf::Texture texture;
		sf::RectangleShape collider;
		int life;
		std::string name;
		sf::Vector2f pos;
		sf::Vector2f rot;
		float speed;
	public:
		Player();
		Player(int, std::string, sf::Vector2f, sf::Vector2f, float);
		~Player();
		void Create(int, std::string, sf::Vector2f, sf::Vector2f, float);
		int GetLife();
		std::string GetName();
		sf::Vector2f GetPos();
		sf::Vector2f GetRot();
		float GetSpeed();
		sf::RectangleShape GetShape();
		void SetLife(int);
		void SetName(std::string);
		void SetPos(sf::Vector2f);
		void SetRot(sf::Vector2f);
		bool mMoveUp;
		bool mMoveDown;
		bool mMoveRight;
		bool mMoveLeft;
};

Player::Player() {
	this->life = 0;
	this->name = "";
	this->pos = sf::Vector2f(0, 0);
	this->rot = sf::Vector2f(0, 0);
}

Player::Player(int life, std::string name, sf::Vector2f pos, sf::Vector2f rot, float speed) {
	this->life = life;
	this->name = name;
	this->pos = pos;
	this->rot = rot;
	this->texture.loadFromFile("./Assets/Player.png");
	this->collider.setSize(sf::Vector2f(128, 80));
	this->collider.setTexture(&texture);
	this->collider.setOutlineColor(sf::Color::Green);
	this->collider.setOutlineThickness(1);
	this->speed = speed;
	this->mMoveUp = false;
	this->mMoveDown = false;
	this->mMoveLeft = false;
	this->mMoveRight = false;
	this->collider.setPosition(pos);
	this->collider.setOrigin(sf::Vector2f(64, 40));
}

Player::~Player() {

}

void Player::Create(int life, std::string name, sf::Vector2f pos, sf::Vector2f rot, float speed) {
	this->life = life;
	this->name = name;
	this->pos = pos;
	this->rot = rot;
	this->texture.loadFromFile("./Assets/Player.png");
	this->collider.setSize(sf::Vector2f(128, 80));
	this->collider.setTexture(&texture);
	this->collider.setOutlineColor(sf::Color::Green);
	this->collider.setOutlineThickness(1);
	this->speed = speed;
	this->mMoveUp = false;
	this->mMoveDown = false;
	this->mMoveLeft = false;
	this->mMoveRight = false;
	this->collider.setPosition(pos);
	this->collider.setOrigin(sf::Vector2f(64,40));
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

sf::Vector2f Player::GetRot() {
	return rot;
}

float Player::GetSpeed() {
	return speed;
}

sf::RectangleShape Player::GetShape() {
	return collider;
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

void Player::SetRot(sf::Vector2f rot) {
	this->rot = rot;
}
