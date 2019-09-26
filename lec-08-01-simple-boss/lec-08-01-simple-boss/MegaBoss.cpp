#include "MegaBoss.h"

MegaBoss::MegaBoss() :
	m_MegaDamageMultiplier(10)
{}

void MegaBoss::MegaAttack() const
{
	cout << "Mega Special Attack inflicts " << (m_DamageMultiplier * m_Damage * m_MegaDamageMultiplier);
	cout << " damage points!\n";
}

MegaBoss::~MegaBoss() {
	cout << "MegaBoss Destructure called" << endl;
}