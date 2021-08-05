#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
	private:
		sf::RenderWindow mWindow;
		Player mPlayer;
		Player mEnemy;
		void Events();
		void Update();
		void Render();
	public:
		Game();
		void Run();
};

Game::Game() {
	mWindow.create(sf::VideoMode(800, 800), "Game", sf::Style::Close);
	mPlayer.Create(100,"Player",sf::Vector2f(50,50),sf::Vector2f(0,0));
}

void Game::Run()
{
	while (mWindow.isOpen())
	{
		Events();
		Update();
		Render();
	}
}

void Game::Events() {
	sf::Event gameEvent;
	while (mWindow.pollEvent(gameEvent)) {
		if (gameEvent.type == sf::Event::Closed) {
			mWindow.close();
		}
	}
}

void Game::Update() {

}

void Game::Render() {
	mWindow.clear(sf::Color::Black);
	mWindow.draw(mPlayer.GetShape());
	mWindow.display();
}