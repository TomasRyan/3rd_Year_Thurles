#ifndef Boss_H
#define Boss_H

#include "Enemy.h"

class Boss : public Enemy
{
public:
	int m_DamageMultiplier;

	Boss();
	void SpecialAttack() const;
	~Boss();
};
#endif Boss_H
