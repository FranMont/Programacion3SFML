#include "Scene.h"

Scene::Scene(sf::RenderWindow* win) : window(win)
{
	weather = "";
}

void Scene::ChanceScene(Scene * s)
{
	escenaActual = s;
}

void Scene::Update(sf::Time dt)
{
	escenaActual->Update(dt);
}

Scene::~Scene()
{
}
