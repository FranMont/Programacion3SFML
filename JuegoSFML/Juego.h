#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Reg.h"
#include "Player.h"
#include "Background.h"
#include "EnemigoBomb.h"
class Juego
{
private: 
	sf::RenderWindow* window;
	Scene* scene = 0;
public:
	void Run();
	Juego();
	~Juego();
};
#endif // JUEGO