#ifndef SPRITES_H
#define SPRITES_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Sprites 
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f spriteSize;
	sf::Vector2f limitSize;

public:
	Sprites();
	Sprites(std::string s);
	Sprites(std::string s, int locationHeigh, int locationWidth, int sizeHeight, int sizeWidht);
	sf::Texture getTexture() const;
	sf::Sprite getSprite() const;
	sf::Vector2f GetPosition();
	void virtual Update(sf::Time dt) = 0;
	void SetPosition(int x, int y);
	void SetLimits(int heightLimit, int widthLimit);
	~Sprites();
};
#endif //SPRITES

