#include "EnemigoCaracol.h"
#include <math.h>

EnemigoCaracol::EnemigoCaracol(std::string apath, float _speed, int posX, int posY, Player * target) : Sprites(apath), maxSpeed(_speed), timerAnim(0.2f)
{
	py = target;
	facingLeft = false;
	animPos.x = 0;
	animPos.y = 0;
	animSize.x = 57;
	animSize.y = 32;
	sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
	speed = maxSpeed;
	SetPosition(posX, posY);
	timer = 0;
}

void EnemigoCaracol::Update(sf::Time dt) 
{
	timer += dt.asSeconds();
	Move(dt);
	Animation();
}

void EnemigoCaracol::Move(sf::Time dt)
{
	sf::Vector2f diff = py->GetPosition() - GetPosition();
	sf::Vector2f dir = normalize(diff);
	sf::Vector2f offset = dir * speed * dt.asSeconds();
	if (offset.x > 0) {
		facingLeft = false;
	}
	else {
		facingLeft = true;
	}
	sprite.move(offset);
}

void EnemigoCaracol::Animation()
{
	if (facingLeft)
	{
		animPos.y = 0;
		if (timer > timerAnim)
		{
			timer = 0;
			animPos.x += animSize.x;
			if (animPos.x >= animSize.x * 2)
			{
				animPos.x = 0;
			}
			sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
		}
	}
	else
	{
		animPos.y = animSize.y;
		if (timer > timerAnim)
		{
			timer = 0;
			animPos.x += animSize.x;
			if (animPos.x >= animSize.x * 2)
			{
				animPos.x = 0;
			}
			sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
		}
	}
}

sf::Vector2f EnemigoCaracol::normalize(const sf::Vector2f& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

EnemigoCaracol::~EnemigoCaracol()
{

}