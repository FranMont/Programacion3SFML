#ifndef SCENE_H
#define SCENE_H

#include <SFML\Graphics.hpp>

class Scene
{
protected:
	Scene* escenaActual;
	sf::RenderWindow* window;	
public:
	std::string weather;
	Scene(sf::RenderWindow* win);
	void ChanceScene(Scene * s);
	virtual void Update(sf::Time dt);
	~Scene();
};

#endif // SCENE_H