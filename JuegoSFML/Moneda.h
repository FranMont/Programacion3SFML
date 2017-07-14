#pragma once
#include"Sprites.h"
class Moneda :
	public Sprites
{
protected:
	bool disappearTime;
	float disappearTimer;
	float timer;
public:
	Moneda(std::string apath);
	Moneda(std::string apath, float time);
	Moneda(std::string apath, int posX, int posY);
	Moneda(std::string apath, int posX, int posY, float time);
	void Update(sf::Time dt);
	~Moneda();
};

