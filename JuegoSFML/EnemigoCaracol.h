#ifndef ENEMIGOCARACOL_H
#define ENEMIGOCARACOL_H
#include "Sprites.h"
#include "Player.h"
class EnemigoCaracol :
	public Sprites
{
protected:
	Player * py;
	int maxSpeed;
	float speed;
	float timer;
	bool facingLeft;
	const float timerAnim;
	sf::Vector2i animPos;
	sf::Vector2i animSize;
public:
	EnemigoCaracol(std::string apath, float _speed, int posX, int posY, Player * target);
	void Update(sf::Time dt);
	void Move(sf::Time dt);
	void Animation();
	sf::Vector2f normalize(const sf::Vector2f& source);
	~EnemigoCaracol();
};

#endif //ENEMIGOCARACOL_H