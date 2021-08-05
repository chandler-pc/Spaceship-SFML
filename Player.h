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
	public:
		Player();
		Player(int, std::string, sf::Vector2f, sf::Vector2f);
		~Player();
		void Create(int, std::string, sf::Vector2f, sf::Vector2f);
		int GetLife();
		std::string GetName();
		sf::Vector2f GetPos();
		sf::Vector2f GetRot();
		sf::RectangleShape GetShape();
		void SetLife(int);
		void SetName(std::string);
		void SetPos(sf::Vector2f);
		void SetRot(sf::Vector2f);
};

Player::Player() {
	this->life = 0;
	this->name = "";
	this->pos = sf::Vector2f(0, 0);
	this->rot = sf::Vector2f(0, 0);
}

Player::Player(int life, std::string name, sf::Vector2f pos, sf::Vector2f rot) {
	this->life = life;
	this->name = name;
	this->pos = pos;
	this->rot = rot;
	this->texture.loadFromFile("./Assets/Player.png");
	this->collider.setSize(sf::Vector2f(128, 80));
	this->collider.setTexture(&texture);
	this->collider.setOutlineColor(sf::Color::Green);
}

Player::~Player() {

}

void Player::Create(int life, std::string name, sf::Vector2f pos, sf::Vector2f rot) {
	this->life = life;
	this->name = name;
	this->pos = pos;
	this->rot = rot;
	this->texture.loadFromFile("./Assets/Player.png");
	this->collider.setSize(sf::Vector2f(128, 80));
	this->collider.setTexture(&texture);
	this->collider.setOutlineColor(sf::Color::Green);
	this->collider.setOutlineThickness(1);
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
}

void Player::SetRot(sf::Vector2f rot) {
	this->rot = rot;
}
