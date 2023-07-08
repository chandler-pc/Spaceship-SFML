#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "../public/actors/Player.h"
#include "../public/actors/Bullet.h"
#include "../public/Game.h"
#include "../Enums.h"

Game::Game() {
	gWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "Game", sf::Style::Close);
	gBackground = new sf::RectangleShape(sf::Vector2f(800,800));
	gPlayer = new Player(100,"Player",sf::Vector2f(400,400),0, 200, sf::Color(82,50,209), .7f,PlayerType::PLAYER);

	gWindow->setFramerateLimit(60);
	gBackground->setFillColor(sf::Color::Black);

	deltaTime = 0;
}

Game::~Game(){
	delete gWindow;
	delete gBackground;
	delete gPlayer;

	gWindow = nullptr;
	gBackground = nullptr;
	gPlayer = nullptr;
}

void Game::Run()
{
	sf::Clock elapsedTime;
	while (gWindow->isOpen())
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
	while (gWindow->pollEvent(gameEvent)) {
		if (gameEvent.type == sf::Event::KeyPressed) {
			gPlayer->eventInput(gameEvent.key.code, true);
		}
		if (gameEvent.type == sf::Event::KeyReleased) {
			gPlayer->eventInput(gameEvent.key.code, false);
		}
		if (gameEvent.type == sf::Event::Closed) {
			gWindow->close();
		}
	}
}

void Game::Update() {
	gPlayer->update(deltaTime);
}

void Game::Render() {
	gWindow->clear(sf::Color::White);
	gWindow->draw(*gBackground);
	gPlayer->draw(gWindow);
	gWindow->display();
}
