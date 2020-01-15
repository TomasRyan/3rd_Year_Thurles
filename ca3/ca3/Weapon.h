#pragma once
#include <sstream>
class Weapon {
private:
	int ammoReserve = 24;
	int bulletsInClipCurrently = 6;
	int maxClipSize = 6;
	float fireRate = 1;
public:
	Weapon(int ammo, int clipSize, float fire);
	bool shoot(int gameTime, int lastPressed);
	// reloads teh weapon, returns if reload is successful
	bool reload();
	void getAmmo();
	std::stringstream getAmmoCount();
};