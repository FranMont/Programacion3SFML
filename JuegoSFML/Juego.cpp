#include "Juego.h"
#include "SceneJuego.h"
#include "SceneMenu.h"
Juego::Juego()
{	
}

Juego::~Juego()
{
}

void Juego::Run()
{
	window = new sf::RenderWindow(sf::VideoMode(Reg::sizeWidth, Reg::sizeHeigh), "Juego SFML!");
	sf::Clock deltaClock;
	scene = new Scene(window);
	scene->ChanceScene(new SceneMenu(window, scene));
	while (window->isOpen())
	{
		sf::Time dt = deltaClock.restart();
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		//Draw
		scene->Update(dt);
		window->display();
	}
	delete scene;
	delete window;
}
