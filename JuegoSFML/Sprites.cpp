#include "Sprites.h"

Sprites::Sprites()
{
}

Sprites::Sprites(std::string s)
{
	if (!texture.loadFromFile(s))
	{
		std::cout << "Error al cargar la imagen " << s << std::endl;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
}

Sprites::Sprites(std::string s, int locationHeigh, int locationWidth, int sizeHeight, int sizeWidht)
{
	if (!texture.loadFromFile(s, sf::IntRect(locationHeigh, locationWidth, sizeHeight, sizeWidht)))
	{
		std::cout << "Error al cargar la imagen " << s << std::endl;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
}

sf::Texture Sprites::getTexture() const
{
	return texture;
}

sf::Sprite Sprites::getSprite() const
{
	return sprite;
}

sf::Vector2f Sprites::GetPosition()
{
	return sprite.getPosition();
}

void Sprites::SetPosition(int x, int y)
{
	sprite.setPosition(sf::Vector2f(x, y));
}

void Sprites::SetLimits(int heightLimit, int widthLimit)
{
	limitSize.x = heightLimit;
	limitSize.y = widthLimit;
}

Sprites::~Sprites()
{
}
