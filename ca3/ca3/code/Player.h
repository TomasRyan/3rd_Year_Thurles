#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

enum weapon {
	pistol,
	SubmachineGun,
	DoubleBarreledShotgun,
	MachineGun
};

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	int currentWeapon = 0;
	bool hasSubmachineGun = false;
	bool hasDoubleBarreledShotgun = false;
	bool hasMachineGun = false;
	bool hasRpg = false;
	// Where is the player
	Vector2f m_Position;

	// Of course we will need a sprite
	Sprite m_Sprite;
	Sprite invincableSprite;
	Color playerTint;
	// And a texture
	// !!Watch this space!!
	Texture m_Texture;
	
	// What is the screen resolution
	Vector2f m_Resolution;

	// What size is the current arena
	IntRect m_Arena;

	// How big is each tile of the arena
	int m_TileSize;

	// Which directions is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	// How much health has the player got?
	int m_Health;
	// What is the maximum health the player can have
	int m_MaxHealth;

	// When was the player last hit
	Time m_LastHit;

	// Speed in pixels per second
	float m_Speed;

	// exp
	int experiance = 0;
	int expLevelCap = 100;
	int playerLevel = 1;
	// money
	int cash = 0;
	// dashes
	bool isDashing = false;
	int dashingTimer = 0;
	int dashingTimerLimit = 3;
	bool dashLockout = false;
	int dashLockoutTimer = 0;
	int dashLockoutTimerLimit = 30;
public:

	Player();

	// Call this at the end of every game
	void resetPlayerStats();

	void spawn(IntRect arena, Vector2f resolution, int tileSize);

	// Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	// How long ago was the player last hit
	Time getLastHitTime();

	// Where is the player
	FloatRect getPosition();

	// Where is the center of the player
	Vector2f getCenter();

	// Which angle is the player facing
	float getRotation();

	// Send a copy of the sprite to main
	Sprite getSprite();

	// How much health has the player currently got?
	int getHealth();

	// The next four functions move the player
	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	// Stop the player moving in a specific direction
	void stopLeft();

	void stopRight();

	void stopUp();

	void stopDown();

	// We will call this function once every frame
	void update(float elapsedTime, Vector2i mousePosition);

	// Give player a speed boost
	void upgradeSpeed();

	// Give the player some health
	void upgradeHealth();

	// Increase the maximum amount of health the player can have
	void increaseHealthLevel(int amount);
	// switch weapon
	void weaponSwitch();
	// get the enum of the weapon equiped currently
	int getWeaponEquiped();
	// unlocking weapons
	void unlockSubmachineGun();
	void unlockDoubleBarreledShotgun();
	void unlockMachineGun();
	void resetGunPrivilage();

	void addCash(int payday);
	void loseCash(int bill);
	bool checkIfRichEnough(int price);
	// add exp, aslo level up the player if they reach enough exp
	void addExp(int expGain);
	// dash logic
	bool getIsDashing();
	void dashStart();
	void stopDashCheck();
};
#pragma once
