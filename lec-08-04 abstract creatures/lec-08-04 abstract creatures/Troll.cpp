#include "Troll.h"
Troll::Troll(int health, int speed) :
	Creature(health,speed)
{}

void Troll::Greet() const
{
	cout << "The Troll roars hello.\n";
}
void Troll::DisplayHealth() const
{
	cout << "The Troll's health is " << m_Health << "\n";
}
void Troll::DisplaySpeed() const
{
	cout << "The Troll's speed is " << m_Speed << "\n";
}