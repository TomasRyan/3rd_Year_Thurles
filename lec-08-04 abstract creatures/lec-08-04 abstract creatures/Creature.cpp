#include "Creature.h"

Creature::Creature(int health, int speed) :
	m_Health(health),m_Speed(speed)
{}


void Creature::DisplayHealth() const
{
	cout << "Health: " << m_Health << endl;
}

void Creature::DisplaySpeed() const
{
	cout << "Speed: " << m_Speed << endl;
}

void Creature::Update()
{
	this->m_Health -= this->m_Speed;
}

bool Creature::healthCheck()
{
	if (this->m_Health < 0) {
		return true;
	}
	else {
		return false;
	}
}