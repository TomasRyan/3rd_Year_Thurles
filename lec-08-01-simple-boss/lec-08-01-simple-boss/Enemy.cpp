#include "Enemy.h"

Enemy::Enemy() :
	m_Damage(10)
{}

void Enemy::Attack() const
{
	cout << "Attack inflicts " << m_Damage << " damage points!\n";
}

Enemy::~Enemy() {
	cout << "Enemy Destructure called" << endl;
}