#include "SceneCredits.h"
#include "SceneMenu.h"
#include <iostream>
#include "Reg.h"

SceneCredits::SceneCredits(sf::RenderWindow* window, Scene* mainScene) : Scene(window), MainScene(mainScene)
{
	if (!fuenteTexto.loadFromFile(DIRECTORY"ComicSansMS.ttf"))
	{
		std::cout << "Error al leer la funte." << std::endl;
	}
	text_Title = new sf::Text("Creditos", fuenteTexto, 24);
	text_Title->setFillColor(sf::Color::White);
	text_Title->setStyle(sf::Text::Bold);
	text_Title->setPosition(20, 20);
	text_Body = new sf::Text("Desarrollado por Francisco Montarce\n\n\Programas usados:\n	Visual Studio 2015\n	Adobe Photoshop\n\n\Fuente: Comic Sans MC (dafont.com/es/)\n\n\Arte de \"Kenney\"(opengameart.org/content/platformer-art-deluxe)\n\n\Gracias por Jugar.\n\nPrecione 'F' para Volver a Jugar!", fuenteTexto, 18);
	text_Body->setFillColor(sf::Color::White);
	text_Body->setStyle(sf::Text::Bold);
	text_Body->setPosition(100, 100);
}

void SceneCredits::Update(sf::Time dt)
{
	window->draw(*text_Title);
	window->draw(*text_Body);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		MainScene->ChanceScene(new SceneMenu(window, MainScene));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window->close();
}

SceneCredits::~SceneCredits()
{
	delete text_Title;
	delete text_Body;
}
