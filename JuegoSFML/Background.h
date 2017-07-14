#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML\Graphics.hpp>
#include "Sprites.h"
class Background : public Sprites
{
protected:

public:
	Background(std::string s); 
	void Update(sf::Time dt);
	~Background();
};

#endif