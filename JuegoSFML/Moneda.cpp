#include "Moneda.h"

Moneda::Moneda(std::string apath) : Sprites(apath), disappearTime(false)
{
}

Moneda::Moneda(std::string apath, float time) : Sprites(apath), disappearTime(true), disappearTimer(time)
{
}

Moneda::Moneda(std::string apath, int posX, int posY) : Sprites(apath), disappearTime(false)
{
	sprite.setPosition(posX, posY);
}
 
Moneda::Moneda(std::string apath, int posX, int posY, float time) : Sprites(apath), disappearTime(true), disappearTimer(time)
{
	sprite.setPosition(posX, posY);
}

void Moneda::Update(sf::Time dt)
{

}

Moneda::~Moneda()
{
}
