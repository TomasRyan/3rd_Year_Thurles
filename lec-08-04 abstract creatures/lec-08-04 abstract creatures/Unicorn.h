#ifndef Unicorn_H
#define Unicorn_H
#include "Creature.h"

class Unicorn : public Creature
{
public:
	Unicorn(int health = 90, int speed = 12);
	virtual void Greet() const;
	void DisplayHealth() const;
	virtual void DisplaySpeed() const;
};
#endif