//Simple Boss
//Demonstrates inheritance

#include "Simple_boss.h"

Boss::Boss() :
	m_DamageMultiplier(3)
{}

void Boss::SpecialAttack() const
{
	cout << "Special Attack inflicts " << (m_DamageMultiplier * m_Damage);
	cout << " damage points!\n";
}

Boss::~Boss() {
	cout << "Boss Destructure called" << endl;
}



