#include "Unicorn.h"
Unicorn::Unicorn(int health, int speed) :
	Creature(health, speed)
{}

void Unicorn::Greet() const
{
	cout << "The Troll Neighs hello.\n";
}
void Unicorn::DisplayHealth() const
{
	cout << "The Unicorn's health is " << m_Health << "\n";
}
void Unicorn::DisplaySpeed() const
{
	cout << "The Unicorn's speed is " << m_Speed << "\n";
}