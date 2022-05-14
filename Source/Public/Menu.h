#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Button;
class Menu{
    private:
        sf::RenderWindow menuWin;
        Button* btnCreate;
        sf::Vector2i cursor;
		void Events();
		void Update();
		void Render();
    public:
        Menu();
        void Run();
};

#endif