#include "Player.h"
#include "Reg.h"
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics/Image.hpp>

Player::Player(std::string apath) : Sprites(apath), maxSpeed(250), timerAnim(0.2f)
{
	speed = maxSpeed;
	dead = false;
	timer = 0;
	moving = false;
}

Player::Player(std::string apath, float _speed, int spriteSize) : Sprites(apath), maxSpeed(_speed), timerAnim(0.2f)
{
	animPos.x = 0;
	animPos.y = 0;
	animSize.x = spriteSize;
	animSize.y = spriteSize;
	sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
	dead = false;
	speed = maxSpeed;
	timer = 0;
	moving = false;
}

Player::Player(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize) : Sprites(apath, xSprite, ySprite, xSize, ySize), maxSpeed(_speed), timerAnim(0.2f)
{
	animPos.x = xSprite;
	animPos.y = ySprite;
	animSize.x = xSize;
	animSize.y = ySize;
	speed = maxSpeed;
	dead = false;
	timer = 0;
	moving = false;
}

Player::Player(std::string apath, float _speed, int xSprite, int ySprite, int xSize, int ySize, int posX, int posY) : Sprites(apath, xSprite, ySprite, xSize, ySize), maxSpeed(_speed), timerAnim(0.2f)
{
	animPos.x = xSprite;
	animPos.y = ySprite;
	animSize.x = xSize;
	animSize.y = ySize;
	speed = maxSpeed;
	SetPosition(posX, posY);
	dead = false;
	timer = 0;
	moving = false;
}

Player::~Player()
{

}

void Player::Update(sf::Time dt)
{
	Move(dt);
	timer += dt.asSeconds();
	Animation(direction);
}

bool Player::Move(sf::Time dt)
{
	moving = false;
	if (!dead) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite.getPosition().x > limitSize.x)
		{
			sprite.move(sf::Vector2f(-speed*dt.asSeconds(), 0));
			direction = 2;
			moving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite.getPosition().x + animSize.x < Reg::sizeWidth - limitSize.x)
		{
			sprite.move(sf::Vector2f(speed*dt.asSeconds(), 0));
			direction = 3;
			moving = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sprite.getPosition().y > limitSize.y)
		{
			sprite.move(sf::Vector2f(0, -speed*dt.asSeconds()));
			direction = 4;
			moving = true;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sprite.getPosition().y + animSize.y < Reg::sizeHeigh - limitSize.y)
		{
			sprite.move(sf::Vector2f(0, speed*dt.asSeconds()));
			direction = 1;
			moving = true;
		}

		return moving;
	}
}

void Player::SetDead(bool death)
{
	dead = death;
}

void Player::Animation(int direction)
{
	if (moving == false) // iddle
	{		
		if (timer > timerAnim)
		{
			timer = 0;
			animPos.x = 0;
			sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
		}
	}
	else 
	{
		if (direction == 1) // down
		{
			animPos.y = 0;
			if (timer > timerAnim)
			{
				timer = 0;
				animPos.x += animSize.x;
				if (animPos.x >= animSize.x * 4)
				{
					animPos.x = 0;
				}
				sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
			}
		}
		if (direction == 2) // left
		{
			animPos.y = animSize.y;
			if (timer > timerAnim)
			{
				timer = 0;
				animPos.x += animSize.x;
				if (animPos.x >= animSize.x * 4)
				{
					animPos.x = 0;
				}
				sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
			}
		}
		if (direction == 3) // right
		{
			animPos.y = animSize.y * 2;
			if (timer > timerAnim)
			{
				timer = 0;
				animPos.x += animSize.x;
				if (animPos.x >= animSize.x * 4)
				{
					animPos.x = 0;
				}
				sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
			}
		}
		if (direction == 4) // up
		{
			animPos.y = animSize.y * 3;
			if (timer > timerAnim)
			{
				timer = 0;
				animPos.x += animSize.x;
				if (animPos.x >= animSize.x * 4)
				{
					animPos.x = animSize.x * 3;
				}
				sprite.setTextureRect(sf::IntRect(animPos.x, animPos.y, animSize.x, animSize.y));
			}
		}
	}
}

bool Player::GetDead()
{
	return dead;
}