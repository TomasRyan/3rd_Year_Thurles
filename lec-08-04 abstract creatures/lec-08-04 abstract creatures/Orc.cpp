#include "Orc.h"
Orc::Orc(int health, int speed) :
	Creature(health,speed)
{}

void Orc::Greet() const
{
	cout << "The orc grunts hello.\n";
}
void Orc::DisplayHealth() const
{
	cout << "The orcs health is " << m_Health << "\n";
}
void Orc::DisplaySpeed() const
{
	cout << "The Orc's speed is " << m_Speed << "\n";
}
