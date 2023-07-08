#pragma once

namespace sf{
	class RenderWindow;
	class RectangleShape;
}

class Player;

class Game {
	private:
		sf::RenderWindow* gWindow;
		sf::RectangleShape* gBackground;
		Player* gPlayer;
		float deltaTime;
		void Events();
		void Update();
		void Render();
	public:
		Game();
		~Game();
		void Run();
};