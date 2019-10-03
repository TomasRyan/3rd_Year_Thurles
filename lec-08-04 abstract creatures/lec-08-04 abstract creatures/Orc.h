#ifndef ORC_H
#define ORC_H
#include "Creature.h"

class Orc : public Creature
{
public:
	Orc(int health = 120, int speed=7);
	virtual void Greet() const;
	void DisplayHealth() const;
	virtual void DisplaySpeed() const;
};
#endif