
#include "player.h"
#include "TextureHolder.h"


Player::Player()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;

	// Associate a texture with the sprite
	// !!Watch this space!!
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"C:/Users/tomas/source/repos/ca3/ca3/graphics/player.png"));

	// Set the origin of the sprite to the centre, 
	// for smooth rotation
	m_Sprite.setOrigin(25, 25);
}

void Player::resetPlayerStats()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;
}

void Player::spawn(IntRect arena, Vector2f resolution, int tileSize)
{
	// Place the player in the middle of the arena
	m_Position.x = arena.width / 2;
	m_Position.y = arena.height / 2;

	// Copy the details of the arena to the player's m_Arena
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;

	// Remember how big the tiles are in this arena
	m_TileSize = tileSize;

	// Strore the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y;
}

Time Player::getLastHitTime()
{
	return m_LastHit;
}

bool Player::hit(Time timeHit)
{
	if (timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200)// 2 tenths of second
	{
		m_LastHit = timeHit;
		m_Health -= 10;
		return true;
	}
	else
	{
		return false;
	}
}

FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
	return m_Position;
}

float Player::getRotation()
{
	return m_Sprite.getRotation();
}

Sprite Player::getSprite()
{
	if (this->isDashing == true) {
		Sprite invincableSprite = this->m_Sprite;
		Color playerTint(0, 255, 255);
		invincableSprite.setColor(playerTint);
		return invincableSprite;
	}
	else {
		return m_Sprite;
	}
}

int Player::getHealth()
{
	return m_Health;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition)
{
	int dashSpeed = 0;
	if (this->isDashing == true) {
		dashSpeed = this->m_Speed * 8;
	}

	if (m_UpPressed)
	{
		m_Position.y -= (m_Speed + dashSpeed) * elapsedTime;
	}

	if (m_DownPressed)
	{
		m_Position.y += (m_Speed + dashSpeed) * elapsedTime;
	}

	if (m_RightPressed)
	{
		m_Position.x += (m_Speed + dashSpeed) * elapsedTime;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= (m_Speed + dashSpeed) * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);

	// Keep the player in the arena
	if (m_Position.x > m_Arena.width - m_TileSize)
	{
		m_Position.x = m_Arena.width - m_TileSize;
	}

	if (m_Position.x < m_Arena.left + m_TileSize)
	{
		m_Position.x = m_Arena.left + m_TileSize;
	}

	if (m_Position.y > m_Arena.height - m_TileSize)
	{
		m_Position.y = m_Arena.height - m_TileSize;
	}

	if (m_Position.y < m_Arena.top + m_TileSize)
	{
		m_Position.y = m_Arena.top + m_TileSize;
	}

	// Calculate the angle the player is facing
	float angle = (atan2(mousePosition.y - m_Resolution.y / 2,
		mousePosition.x - m_Resolution.x / 2)
		* 180) / 3.141;

	m_Sprite.setRotation(angle);
	if (this->dashLockout == true) {
		if (this->dashLockoutTimer >= this->dashLockoutTimerLimit) {
			this->dashLockout = false;
			this->dashLockoutTimer = 0;
		}
		else {
			this->dashLockoutTimer++;
		}
	}
	
	if (this->isDashing == true) {
		this->stopDashCheck();
	}
}

void Player::upgradeSpeed()
{
	// 20% speed upgrade
	m_Speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	// 20% max health upgrade
	m_MaxHealth += (START_HEALTH * .2);
}

void Player::increaseHealthLevel(int amount)
{
	m_Health += amount;
	// But not beyond the maximum
	if (m_Health > m_MaxHealth)
	{
		m_Health = m_MaxHealth;
	}
}

void Player::weaponSwitch() {
	this->currentWeapon++;
	if (this->currentWeapon == 1 && this->hasSubmachineGun == false) {
		this->currentWeapon++;
	}
	if (this->currentWeapon == 2 && this->hasDoubleBarreledShotgun == false) {
		this->currentWeapon++;
	}
	if (this->currentWeapon == 3 && this->hasMachineGun == false) {
		this->currentWeapon++;
	}
	if (this->currentWeapon >= 4) {
		this->currentWeapon = 0;
	}
}

int Player::getWeaponEquiped() {
	return this->currentWeapon;
}

void Player::unlockSubmachineGun() {
	this->hasSubmachineGun = true;
}

void Player::unlockDoubleBarreledShotgun() {
	this->hasDoubleBarreledShotgun = true;
}

void Player::unlockMachineGun() {
	this->hasMachineGun = true;
}

void Player::resetGunPrivilage() {
	this->hasMachineGun = false;
	this->hasDoubleBarreledShotgun = false;
	this->hasSubmachineGun = false;
}

void Player::addCash(int payday) {
	this->cash += payday;
}

void Player::loseCash(int bill) {
	this->cash -= bill;
	if (cash <= 0) {
		cash = 0;
	}
}

bool Player::checkIfRichEnough(int price) {
	if (this->cash >= price) {
		return true;
	}
	else {
		return false;
	}
}

void Player::addExp(int expGain) {
	this->experiance += expGain;
	if (this->experiance >= this->expLevelCap) {
		this->expLevelCap += 50;
		this->playerLevel++;
		this->experiance = 0;
		this->upgradeHealth();
		this->upgradeSpeed();
	}
}

bool Player::getIsDashing() {
	return this->isDashing;
}

void Player::dashStart(){
	if (dashLockout == false) {
		this->isDashing = true;
		this->dashLockout = true;
	}
}

void Player::stopDashCheck() {
	if (this->dashingTimer >= this->dashingTimerLimit) {
		this->isDashing = false;
		this->dashingTimer = 0;
	}
	else {
		this->dashingTimer++;
	}
}
