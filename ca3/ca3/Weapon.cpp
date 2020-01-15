#include "Weapon.h"


Weapon::Weapon(int ammo, int clipSize, float fire) {
	this->ammoReserve = ammo;
	this->bulletsInClipCurrently = clipSize;
	this->maxClipSize = clipSize;
	this->fireRate = fire;
}

bool Weapon::shoot(int gameTime, int lastPressed)
{
	if (gameTime - lastPressed > 1000 / this->fireRate&& this->bulletsInClipCurrently > 0) {
		this->bulletsInClipCurrently--;
		return true;
	}
	else {
		return false;
	}
}

bool Weapon::reload() {
	if (this->ammoReserve >= this->maxClipSize)
	{
		// Plenty of bullets. Reload.
		this->ammoReserve -= this->maxClipSize - this->bulletsInClipCurrently;
		this->bulletsInClipCurrently = this->maxClipSize;
		
		return true;
	}
	else if (this->ammoReserve > 0)
	{
		// Only few bullets left
		this->bulletsInClipCurrently = this->ammoReserve;
		this->ammoReserve = 0;
		return true;
	}
	else
	{
		// More here soon?!
		return false;
	}
}

void Weapon::getAmmo() {
	int ammoToAdd = this->maxClipSize;
	this->ammoReserve += ammoToAdd;
}

std::stringstream Weapon::getAmmoCount() {
	std::stringstream ammoCount;
	ammoCount  << this->bulletsInClipCurrently << "/" << this->ammoReserve;
	return ammoCount;
}
