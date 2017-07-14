#ifndef SCENEJUEGO_H
#define SCENEJUEGO_H

#include "Scene.h"
#include "Reg.h"
#include "Player.h"
#include "Background.h"
#include "EnemigoBomb.h"

class SceneJuego :
	public Scene
{
protected:
	sf::Text* text_CoinsScore;
	sf::Text* text_TimeText;
	sf::Font fuenteTexto;
	Scene* MainScene;
	Player * py;
	Sprites * en;
	Sprites * en2;
	Sprites * bc;
	Sprites * bc2;
	Sprites * en3;
	Sprites * enemigo;
	float score;
	int monedasRecogidas;
	float highScore;
	std::vector<Sprites*> vMonedas;
public:
	void Update(sf::Time dt);
	void Collisiones(Player * py, Sprites * en);
	bool CollisionMoneda(Player * py, Sprites * mon);
	void loadHighScore();
	void saveHighScore();
	SceneJuego(sf::RenderWindow* window, Scene* mainScene);
	~SceneJuego();
};

#endif // SCENEJUEGO_H