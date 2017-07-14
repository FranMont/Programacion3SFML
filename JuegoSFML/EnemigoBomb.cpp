#include "EnemigoBomb.h"
#include "Reg.h"

EnemigoBomb::EnemigoBomb() : Sprites(), maxSpeed(250), timerAnim(0.2f)
{

}
EnemigoBomb::EnemigoBomb(std::string apath, float _speed, bool movingLR, int posX, int posY) : Sprites(apath), maxSpeed(_speed), timerAnim(0.2f)
{
	movingLRight = movingLR;
	movingDirection = 1;
	animPos.x = 0;
	animPos.y = 0;
	animSize.x = 72;
	animSize.y = 36;
	sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
	speed = maxSpeed;
	SetPosition(posX, posY);
	timer = 0;
}

EnemigoBomb::EnemigoBomb(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize, bool movingLR) : Sprites(apath, xSprite, ySprite, xSize, ySize), maxSpeed(_speed), timerAnim(0.2f)
{
	movingLRight = movingLR;
	movingDirection = 1;
	speed = maxSpeed;
	timer = 0;
}

EnemigoBomb::EnemigoBomb(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize, int posX, int posY, bool movingLR) : Sprites(apath, xSprite, ySprite, xSize, ySize), maxSpeed(_speed), timerAnim(0.2f)
{
	movingLRight = movingLR;
	movingDirection = 1;
	speed = maxSpeed;
	SetPosition(posX, posY);
	timer = 0;
}

void EnemigoBomb::Animation()
{
	if (movingLRight)
	{
		if (movingDirection == 1)
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
		if (movingDirection == -1)
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
	}
	else
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
}

void EnemigoBomb::Update(sf::Time dt)
{
	this->Move(dt);
	timer += dt.asSeconds();
	Animation();
}

void EnemigoBomb::Move(sf::Time dt)
{
	if (movingLRight)
	{
		if (movingDirection == -1)
		{
			if (sprite.getPosition().x > limitSize.x)
			{
				sprite.move(sf::Vector2f(movingDirection*speed*dt.asSeconds(), 0));
			}
			else
			{
				movingDirection = 1;
			}
		}
		if (movingDirection == 1)
		{
			if (sprite.getPosition().x + animSize.x < Reg::sizeWidth - limitSize.x)
			{
				sprite.move(sf::Vector2f(movingDirection*speed*dt.asSeconds(), 0));
			}
			else
			{
				movingDirection = -1;
			}
		}
	}
	else
	{
		if (movingDirection == -1)
		{
			if (sprite.getPosition().y > limitSize.y)
			{
				sprite.move(sf::Vector2f(0, movingDirection*speed*dt.asSeconds()));
			}
			else
			{
				movingDirection = 1;
			}
		}
		if (movingDirection == 1)
		{
			if (sprite.getPosition().y + animSize.y < Reg::sizeHeigh - limitSize.y)
			{
				sprite.move(sf::Vector2f(0, movingDirection*speed*dt.asSeconds()));
			}
			else
			{
				movingDirection = -1;
			}
		}
	}
}

EnemigoBomb::~EnemigoBomb()
{
}
