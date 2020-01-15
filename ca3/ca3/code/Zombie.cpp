
#include "zombie.h"
#include "TextureHolder.h"
#include <cstdlib>
#include <ctime>

using namespace std;


void Zombie::spawn(float startX, float startY, int type, int seed)
{
	this->enemyType = type;
	switch (type)
	{
	case 0:
		// Bloater
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"C:/Users/tomas/source/repos/ca3/ca3/graphics/bloater.png"));

		m_Speed = 40;
		m_Health = 5;
		break;

	case 1:
		// Chaser
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"C:/Users/tomas/source/repos/ca3/ca3/graphics/chaser.png"));

		m_Speed = 70;
		m_Health = 1;
		break;

	case 2:
		// Crawler
		m_Sprite = Sprite(TextureHolder::GetTexture(
			"C:/Users/tomas/source/repos/ca3/ca3/graphics/crawler.png"));

		m_Speed = 20;
		m_Health = 3;
		break;
	}
	// set sight
	
	// Modify the speed to make the zombie unique
	// Every zombie is unique. Create a speed modifier
	srand((int)time(0) * seed);
	// Somewhere between 80 an 100
	float modifier = (rand() % MAX_VARRIANCE) + OFFSET;
	// Express as a fraction of 1
	modifier /= 100; // Now equals between .7 and 1
	m_Speed *= modifier;

	m_Position.x = startX;
	m_Position.y = startY;

	m_Sprite.setOrigin(25, 25);
	m_Sprite.setPosition(m_Position);
	this->distanceToAttackPlayer = m_Speed * 2;
	this->distanceToSeePlayer = m_Speed * 5;
	this->dashSpeed = m_Speed * 2;
}

bool Zombie::hit()
{
	m_Health--;

	if (m_Health < 0)
	{
		// dead
		m_Alive = false;
		m_Sprite.setTexture(TextureHolder::GetTexture(
			"C:/Users/tomas/source/repos/ca3/ca3/graphics/blood.png"));

		return true;
	}

	// injured but not dead yet
	return false;
}

bool Zombie::isAlive()
{
	return m_Alive;
}

FloatRect Zombie::getPosition()
{
	return m_Sprite.getGlobalBounds();
}


Sprite Zombie::getSprite()
{
	return m_Sprite;
}

void Zombie::update(float elapsedTime,
	Vector2f playerLocation)
{
	float playerX = playerLocation.x;
	float playerY = playerLocation.y;
	float dashSpeed = 0;
	// if dashing
	if (attackPlayerCheck(playerX, playerY) == true) {
		dashSpeed = this->dashSpeed;
	}
	// Update the zombie position variables
	if (playerX > m_Position.x)
	{
		m_Position.x = m_Position.x +
			(m_Speed + this->dashSpeed) * elapsedTime;
	}

	if (playerY > m_Position.y)
	{
		m_Position.y = m_Position.y +
			(m_Speed + this->dashSpeed) * elapsedTime;
	}

	if (playerX < m_Position.x)
	{
		m_Position.x = m_Position.x -
			(m_Speed + this->dashSpeed) * elapsedTime;
	}

	if (playerY < m_Position.y)
	{
		m_Position.y = m_Position.y -
			(m_Speed + this->dashSpeed) * elapsedTime;
	}

	// Move the sprite
	m_Sprite.setPosition(m_Position);

	// Face the sprite in the correct direction
	float angle = (atan2(playerY - m_Position.y,
		playerX - m_Position.x)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);

}

int Zombie::getType()
{
	return this->enemyType;
}

bool Zombie::SeePlayerCheck(float targetX, float targetY)
{
	if (abs(sqrt(pow(targetX - this->m_Sprite.getPosition().x, 2) + pow(targetY - this->m_Sprite.getPosition().y, 2))) <= this->distanceToSeePlayer) {
		this->seePlayer = true;
		return true;
	}
	else {
		return false;
	}
}


bool Zombie::attackPlayerCheck(float targetX, float targetY)
{
	if (this->isDashing == true) {
		this->dashTimer++;
		if (this->dashTimer <= this->dashTimerLimit) {
			return true;
		}
		else {
			this->dashTimer = 0;
			this->isDashing = false;
			return false;
		}
	}
	else if (abs(sqrt(pow(targetX - this->m_Sprite.getPosition().x, 2) + pow(targetY - this->m_Sprite.getPosition().y, 2))) <= this->distanceToAttackPlayer) {
		this->isDashing = true;
		return true;
	}
	else {
		return false;
	}
}

void Zombie::stopAttack() {
	this->isDashing = false;
}