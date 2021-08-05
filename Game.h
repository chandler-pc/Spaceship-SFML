#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
	private:
		sf::RenderWindow mWindow;
		Player mPlayer;
		Player mEnemy;
		float deltaTime;
		void Events();
		void Update();
		void Render();
		void PlayerInput(sf::Keyboard::Key, bool);
	public:
		Game();
		void Run();
};

Game::Game() {
	mWindow.create(sf::VideoMode(800, 800), "Game", sf::Style::Close);
	mWindow.setFramerateLimit(60);
	mPlayer.Create(100,"Player",sf::Vector2f(400,400),sf::Vector2f(0,0), 50);
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
		movement.y -= mov;
	}
	if (mPlayer.mMoveDown) {
		movement.y += mov;
	}
	if (mPlayer.mMoveLeft) {
		movement.x -= mov;
	}
	if (mPlayer.mMoveRight) {
		movement.x += mov;
	}
	mPlayer.SetPos(sf::Vector2f((mPlayer.GetPos().x + movement.x), (mPlayer.GetPos().y + movement.y)));
}

void Game::Render() {
	mWindow.clear(sf::Color::Black);
	mWindow.draw(mPlayer.GetShape());
	mWindow.display();
}

void Game::PlayerInput(sf::Keyboard::Key key, bool isPress) {
	if (key == sf::Keyboard::Key::W) {
		mPlayer.mMoveUp = isPress;
	}
	if (key == sf::Keyboard::Key::S) {
		mPlayer.mMoveDown = isPress;
	}
	if (key == sf::Keyboard::Key::A) {
		mPlayer.mMoveLeft = isPress;
	}
	if (key == sf::Keyboard::Key::D) {
		mPlayer.mMoveRight = isPress;
	}
}