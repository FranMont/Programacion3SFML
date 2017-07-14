#ifndef SCENEMENU_H
#define SCENEMENU_H
#include "Scene.h"
#include "Background.h"
#include "SceneJuego.h"

class SceneMenu : public Scene
{
protected:
	Scene* MainScene;
	Background * bc;
	float highScore;
	sf::Text* text_HighScore;
	sf::Text* text_MainText;
	sf::Text* text_WheaterText;
	sf::Font fuenteHighscore;
	std::string ciudad;
public:
	void LoadHighScore();
	void LoadCity();
	void CheckWeather();
	SceneMenu(sf::RenderWindow* window, Scene * mainScene);
	void Update(sf::Time dt);
	~SceneMenu();
};

#endif // !SCENEMENU_H