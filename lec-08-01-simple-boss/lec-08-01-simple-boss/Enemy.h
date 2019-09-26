#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;

class Enemy
{
public:
	int m_Damage;

	Enemy();
	void Attack() const;
	~Enemy();
};
#endif ENEMY_H