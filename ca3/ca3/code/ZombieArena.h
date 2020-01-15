#pragma once
#include "Zombie.h"
#include "Bullet.h"
#include <list>
using namespace std;
using namespace sf;

int createBackground(VertexArray& rVA, IntRect arena);
list<Zombie*> createHorde(int numZombies, IntRect arena);
bool collisionCheck(Zombie* z, Bullet* b);