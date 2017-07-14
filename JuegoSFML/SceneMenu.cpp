#include "SceneMenu.h"
#include "SceneCredits.h"
#include <SFML/Network.hpp>
#include <rapidjson\document.h>
#include <fstream>

SceneMenu::SceneMenu(sf::RenderWindow* window, Scene* mainScene) : Scene(window), MainScene(mainScene)
{
	bc = new Background(DIRECTORY"Escenario/FondoMenu.png");
	LoadCity();
	bool internet = true;
	if (MainScene->weather == "" && system("ping www.google.com")) {
		internet = false;
	}
	if (internet) {
		if (MainScene->weather == "") {
			CheckWeather();
		}
	}
	else {
		MainScene->weather = "Sin Conexion";
	}
	LoadHighScore();
	if (!fuenteHighscore.loadFromFile(DIRECTORY"ComicSansMS.ttf"))
	{
		std::cout << "Error al leer la funte." << std::endl;
	}
	text_MainText = new sf::Text("Precione Espacio para inciar el juego!\n    Precione Enter para los Creditos", fuenteHighscore, 24);
	text_MainText->setFillColor(sf::Color::Black);
	text_MainText->setStyle(sf::Text::Bold);
	text_MainText->setPosition(170, 500);
	text_HighScore = new sf::Text("HighScore: " + std::to_string(highScore), fuenteHighscore, 16);
	text_HighScore->setFillColor(sf::Color::Black);
	text_HighScore->setStyle(sf::Text::Bold);
	text_HighScore->setPosition(0, 0);
	text_WheaterText = new sf::Text("Clima: " + MainScene->weather, fuenteHighscore, 16);
	text_WheaterText->setFillColor(sf::Color::Black);
	text_WheaterText->setStyle(sf::Text::Bold);
	text_WheaterText->setPosition(650, 0);
}

void SceneMenu::Update(sf::Time dt)
{	
	window->draw(bc->getSprite());
	window->draw(*text_HighScore);
	window->draw(*text_WheaterText);
	window->draw(*text_MainText);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		MainScene->ChanceScene(new SceneJuego(window, MainScene));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		MainScene->ChanceScene(new SceneCredits(window, MainScene));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window->close();
}

void SceneMenu::LoadHighScore()
{
	std::ifstream file(DIRECTORY"highscore.txt");
	if (file)
	{
		std::string input;
		file >> input;
		highScore = atof(input.c_str());
	}
	else
	{
		std::ofstream highScoreFile(DIRECTORY"highscore.txt");
		highScoreFile << "0" << std::endl;
		highScoreFile.close();
		highScore = 0;
	}
	file.close();
}

void SceneMenu::LoadCity()
{
	std::ifstream file(DIRECTORY"city.txt");
	ciudad = file.get();
	file.close();
}

void SceneMenu::CheckWeather()
{
	sf::Http http("http://query.yahooapis.com/");
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Get);
	request.setUri("v1/public/yql?q=select%20item.condition.text%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22" + ciudad + "%22)&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");

	sf::Http::Response response = http.sendRequest(request);
	std::string s;
	rapidjson::Document document;
	document.Parse(response.getBody().c_str());
	if (document["query"]["count"].GetInt() == 1)
	{
		assert(document["query"]["results"]["channel"]["item"]["condition"]["text"].IsString());
		printf("Weather = %s\n", document["query"]["results"]["channel"]["item"]["condition"]["text"].GetString());
		s = document["query"]["results"]["channel"]["item"]["condition"]["text"].GetString();
	}
	else
	{
		s = "DOES NOT EXIST";
	}
	MainScene->weather = s;
}

SceneMenu::~SceneMenu()
{
	delete text_MainText;
	delete text_HighScore;
	delete text_WheaterText;
}
