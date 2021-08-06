#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <list>
#include "Player.h"
#include "Bullet.h"
#define PI 3.14159265

class Game {
	private:
		sf::RenderWindow mWindow;
		sf::RectangleShape background;
		Player mPlayer;
		Player mEnemy;
		float deltaTime;
		void Events();
		void Update();
		void Render();
		void PlayerInput(sf::Keyboard::Key, bool);
		std::list<Bullet> BulletList;
	public:
		Game();
		void Run();
};

Game::Game() {
	mWindow.create(sf::VideoMode(800, 800), "Game", sf::Style::Close);
	mWindow.setFramerateLimit(60);
	mPlayer.Create(100,"Player",sf::Vector2f(400,400),0, 200, sf::Color(82,50,209), .5f);
	background.setSize(sf::Vector2f(800,800));
	background.setFillColor(sf::Color::Black);
	deltaTime = 0;
}

void Game::Run()
{
	sf::Clock elapsedTime;
	while (mWindow.isOpen())
	{
		deltaTime = elapsedTime.getElapsedTime().asSeconds();
		elapsedTime.restart();
		Events();
		Update();
		Render();
	}
}

void Game::Events() {
	sf::Event gameEvent;
	while (mWindow.pollEvent(gameEvent)) {
		if (gameEvent.type == sf::Event::KeyPressed) {
			PlayerInput(gameEvent.key.code, true);
		}
		if (gameEvent.type == sf::Event::KeyReleased) {
			PlayerInput(gameEvent.key.code, false);
		}
		if (gameEvent.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

void Game::Update() {
	sf::Vector2f movement = sf::Vector2f(0, 0);
	float mov = mPlayer.GetSpeed() * deltaTime;
	if (mPlayer.mMoveUp) {
		movement.x += mov*sin(mPlayer.GetRot()*PI/180);
		movement.y -= mov*cos(mPlayer.GetRot()*PI/180);
	}
	if (mPlayer.mMoveDown) {
		movement.x -= mov * sin(mPlayer.GetRot() * PI / 180);
		movement.y += mov * cos(mPlayer.GetRot() * PI / 180);
	}
	/*if (mPlayer.mMoveLeft) {
		movement.x -= mov * cos(mPlayer.GetRot() * PI / 180);
		movement.y -= mov * sin(mPlayer.GetRot() * PI / 180);
	}
	if (mPlayer.mMoveRight) {
		movement.x += mov * cos(mPlayer.GetRot() * PI / 180);
		movement.y += mov * sin(mPlayer.GetRot() * PI / 180);
	}*/
	if (mPlayer.mRotateLeft) {
		mPlayer.SetRot(mPlayer.GetRot()-mov);
	}
	if (mPlayer.mRotateRight) {
		mPlayer.SetRot(mPlayer.GetRot() + mov);
	}
	if (background.getGlobalBounds().contains(mPlayer.GetShape().getPosition().x, mPlayer.GetShape().getPosition().y)) {
		mPlayer.SetPos(mPlayer.GetPos() + movement);
	}
	else {
		if (mPlayer.GetShape().getPosition().x > 800) {
			mPlayer.SetPos(sf::Vector2f(799, mPlayer.GetPos().y));
		}
		if (mPlayer.GetShape().getPosition().x < 0) {
			mPlayer.SetPos(sf::Vector2f(0, mPlayer.GetPos().y));
		}
		if (mPlayer.GetShape().getPosition().y > 800) {
			mPlayer.SetPos(sf::Vector2f(mPlayer.GetPos().x,799));
		}
		if (mPlayer.GetShape().getPosition().y < 0) {
			mPlayer.SetPos(sf::Vector2f(mPlayer.GetPos().x, 0));
		}
	}
	if (mPlayer.GetDelayShoot() < .5f) {
		mPlayer.SetDelayShoot(mPlayer.GetDelayShoot() + deltaTime);
	}
	else {
		if (mPlayer.mShoot) {
			Bullet bullet1(mPlayer.GetRot(),mPlayer.GetPos() + sf::Vector2f(27 * cos(mPlayer.GetRot()*PI/180) + 30 * sin(mPlayer.GetRot() * PI / 180), 27 * sin(mPlayer.GetRot() * PI / 180) - 30 * cos(mPlayer.GetRot() * PI / 180)),4,230, sf::Color(82, 50, 209));
			Bullet bullet2(mPlayer.GetRot(),mPlayer.GetPos() + sf::Vector2f(-27 * cos(mPlayer.GetRot()*PI/180) + 30 * sin(mPlayer.GetRot() * PI / 180), -27 * sin(mPlayer.GetRot() * PI / 180) - 30 * cos(mPlayer.GetRot() * PI / 180)),4,230, sf::Color(82, 50, 209));
			BulletList.push_back(bullet1);
			BulletList.push_back(bullet2);
			mPlayer.SetDelayShoot(0);
		}
	}
	if (BulletList.size() != 0) {
		for (std::list<Bullet>::iterator it = BulletList.begin(); it != BulletList.end(); it++)
		{
			sf::Vector2f movementBullet = sf::Vector2f(0, 0);
			if ((*it).GetTime() > 0) {
				float movBullet = (*it).GetSpeed() * deltaTime;
				movementBullet.x += movBullet * sin((*it).GetRot() * PI / 180);
				movementBullet.y -= movBullet * cos((*it).GetRot() * PI / 180);
				(*it).SetPos((*it).GetPos() + movementBullet);
				if (BulletList.size() > 2) {
					(*it).SetTime((*it).GetTime() - deltaTime);
				}
			}
			if ((*it).GetTime() < 0) {
				BulletList.pop_front();
				it = BulletList.begin();
			}
		}
	}
}

void Game::Render() {
	mWindow.clear(sf::Color::White);
	mWindow.draw(background);
	mWindow.draw(mPlayer.GetShape()); 
	for (std::list<Bullet>::iterator it = BulletList.begin(); it != BulletList.end(); it++)
	{
		mWindow.draw((*it).GetShape());
	}
	mWindow.display();
}

void Game::PlayerInput(sf::Keyboard::Key key, bool isPress) {
	if (key == sf::Keyboard::Key::W) {
		mPlayer.mMoveUp = isPress;
	}
	if (key == sf::Keyboard::Key::S) {
		mPlayer.mMoveDown = isPress;
	}
	/*if (key == sf::Keyboard::Key::A) {
		mPlayer.mMoveLeft = isPress;
	}
	if (key == sf::Keyboard::Key::D) {
		mPlayer.mMoveRight = isPress;
	}*/
	if (key == sf::Keyboard::Key::A) {
		mPlayer.mRotateLeft = isPress;
	}
	if (key == sf::Keyboard::Key::D) {
		mPlayer.mRotateRight = isPress;
	}
	if (key == sf::Keyboard::Key::Space) {
		mPlayer.mShoot = isPress;
	}
}