#include "../Public/Menu.h"
#include "../Public/Button.h"

Menu::Menu(){
    menuWin.create(sf::VideoMode(800, 800), "Menu", sf::Style::Close);
	menuWin.setFramerateLimit(60);
	btnCreate = new Button();
    btnCreate->config("a",sf::Vector2f(0,0),sf::Color::Blue, sf::Color::Black, sf::Color::Black);
}

void Menu::Events(){
    sf::Event eventmenu;
	if (menuWin.pollEvent(eventmenu)) {
		if (eventmenu.type == sf::Event::Closed) {
			menuWin.close();
		}
		if(eventmenu.type = sf::Event::MouseMoved){
			cursor = sf::Mouse::getPosition(menuWin);
		}
	}
}

void Menu::Render(){
	menuWin.clear(sf::Color::Green);
    btnCreate->display(menuWin);
    menuWin.display();
}

void Menu::Run(){
	while (menuWin.isOpen()) {
		Events();
        Render();		
	}
}