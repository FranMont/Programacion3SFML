#ifndef SCENECREDITS_H
#define SCENECREDITS_H
#include "Scene.h"
class SceneCredits :
	public Scene
{
protected:
	Scene * MainScene;
	sf::Text* text_Title;
	sf::Text* text_Body;
	sf::Font fuenteTexto;
public:
	void Update(sf::Time dt);
	SceneCredits(sf::RenderWindow* window, Scene* mainScene);
	~SceneCredits();
};
#endif // SCENECREDITS_H