#ifndef PLAYER_H
#define PLAYER_H
#include"Sprites.h"
class Player : public Sprites
{
private:
	float speed;
	const float maxSpeed;
	bool dead;
	float timer;
	int direction;
	const float timerAnim;
	bool moving;
	sf::Vector2i animPos;
	sf::Vector2i animSize;
public:
	void Update(sf::Time dt);
	bool Move(sf::Time dt);
	void SetDead(bool death);
	void Animation(int direction);
	bool GetDead();
	Player(std::string apath);
	Player(std::string apath, float _speed, int spriteSize);
	Player(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize);
	Player(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize, int posX, int posY);
	~Player();
};
#endif //PLAYER