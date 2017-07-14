#include "SceneJuego.h"
#include "Moneda.h"
#include "SceneCredits.h"
#include "EnemigoCaracol.h"
#include "SceneMenu.h"
#include <fstream>

#define MAX_MONEDAS 3
#define COIN_SCORE 20

SceneJuego::SceneJuego(sf::RenderWindow* window, Scene* mainScene) : Scene(window), MainScene(mainScene)
{
	if (!fuenteTexto.loadFromFile(DIRECTORY"ComicSansMS.ttf"))
	{
		std::cout << "Error al leer la funte." << std::endl;
	}
	text_CoinsScore = new sf::Text("Mondeas: 0/20", fuenteTexto, 24);
	text_CoinsScore->setFillColor(sf::Color::Black);
	text_CoinsScore->setStyle(sf::Text::Bold);
	text_CoinsScore->setPosition(Reg::sizeWidth - 200, 0);
	text_TimeText = new sf::Text("Tiempo: 0", fuenteTexto, 24);
	text_TimeText->setFillColor(sf::Color::Black);
	text_TimeText->setStyle(sf::Text::Bold);
	text_TimeText->setPosition(0, 0);
	py = new Player(DIRECTORY"Personaje/Mage192.png", 250, 48);
	py->SetPosition(70, 70);
	en = new EnemigoBomb(DIRECTORY"Enemigo/Enemigo2.png", 300, true, 448, 348);
	en2 = new EnemigoBomb(DIRECTORY"Enemigo/Enemigo2.png", 300, false, 600, 200);
	en3 = new EnemigoBomb(DIRECTORY"Enemigo/Enemigo2.png", 300, false, 160, 200);
	enemigo = new EnemigoCaracol(DIRECTORY"Enemigo/Enemigo3.png", 65, 700, 500, py);
	bc = new Background(DIRECTORY"Escenario/back.png");
	bc2 = new Background(DIRECTORY"Escenario/Fondo.png");
	loadHighScore();
	for (int i = 0; i < MAX_MONEDAS; i++) {
		vMonedas.push_back(new Moneda(DIRECTORY"Escenario/coin.png", rand() % 600 + 70, rand() % 300 + 70));
	}
	py->SetLimits(70, 70);
	en->SetLimits(70, 70);
	en2->SetLimits(70, 70);
	en3->SetLimits(70, 70);
}

void SceneJuego::Update(sf::Time dt)
{
	
	bc->Update(dt);
	en->Update(dt);
	en2->Update(dt);
	en3->Update(dt);
	enemigo->Update(dt);
	window->draw(bc->getSprite());
	window->draw(bc2->getSprite());
	for (int i = 0; i < vMonedas.size(); i++)
	{
		vMonedas[i]->Update(dt);
		if (CollisionMoneda(py, vMonedas[i]))
		{
			delete vMonedas[i];
			vMonedas[i] = new Moneda(DIRECTORY"Escenario/coin.png", rand() % 600 + 70, rand() % 300 + 70);
		}
		window->draw(vMonedas[i]->getSprite());
	}
	if (!py->GetDead())
	{
		Collisiones(py, en);
		Collisiones(py, en2);
		Collisiones(py, en3);
		Collisiones(py, enemigo);
	}
	score += dt.asSeconds();
	text_TimeText->setString("Tiempo: " + std::to_string(score));
	
	window->draw(*text_CoinsScore);
	window->draw(*text_TimeText);

	window->draw(en->getSprite());
	window->draw(en2->getSprite());
	window->draw(en3->getSprite());
	window->draw(enemigo->getSprite());
	py->Update(dt);
	window->draw(py->getSprite());
}

SceneJuego::~SceneJuego()
{
	delete py;
	delete en;
	delete en2;
	delete en3;
	delete text_CoinsScore;
	delete text_TimeText;
	delete bc;
	delete bc2;
	for (int i = 0; i < MAX_MONEDAS; i++) {
		delete vMonedas[i];
	}
}

void SceneJuego::Collisiones(Player * py, Sprites * en)
{
	if (py->getSprite().getGlobalBounds().intersects(en->getSprite().getGlobalBounds()))
	{
		std::cout << "Collision" << std::endl;
		py->SetDead(true);
		MainScene->ChanceScene(new SceneMenu(window, MainScene));
	}
}
bool SceneJuego::CollisionMoneda(Player * py, Sprites * mon)
{
	if (py->getSprite().getGlobalBounds().intersects(mon->getSprite().getGlobalBounds()))
	{
		std::cout << "Collision Moneda" << std::endl;
		monedasRecogidas += 1;
		text_CoinsScore->setString("Monedas: " + std::to_string(monedasRecogidas) + "/" + std::to_string(COIN_SCORE));
		if (monedasRecogidas == COIN_SCORE)
		{
			highScore = score;
			saveHighScore();
			MainScene->ChanceScene(new SceneCredits(window, MainScene));
			std::cout << "you win!" << std::endl;//YOU WIN
		}
		return true;
	}
	else
	{
		return false;
	}
}

void SceneJuego::loadHighScore()
{
	std::ifstream file(DIRECTORY"highscore.txt");
	if (file)
	{
		std::string input;
		while (file >> input);
		highScore = atof(input.c_str());
	}
	else
	{		
		highScore = 0;
	}
	file.close();
}

void SceneJuego::saveHighScore()
{
	std::ofstream highScoreFile(DIRECTORY"highscore.txt");
	highScoreFile << highScore << std::endl;
	highScoreFile.close();
}
