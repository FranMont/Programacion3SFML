#ifndef ENEMIGOBOMB_H
#define ENEMIGOBOMB_H
#include "Sprites.h"
class EnemigoBomb :
	public Sprites
{
protected:
	int speed;
	const int maxSpeed;
	int movingDirection;
	bool movingLRight;
	float timer;
	const float timerAnim;
	sf::Vector2i animPos;
	sf::Vector2i animSize;
public:
	EnemigoBomb();
	EnemigoBomb(std::string apath, float _speed, bool movingLR, int posX, int posY);
	EnemigoBomb(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize, bool movingLR);
	EnemigoBomb(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize, int posX, int posY, bool movingLR);
	void Animation();
	void Update(sf::Time dt);
	void Move(sf::Time dt);
	~EnemigoBomb();
};
#endif // ENEMIGOBOMB_H