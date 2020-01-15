
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ZombieArena.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Bullet.h"
#include "Pickup.h"
#include <list>
#include "../Weapon.h"
using namespace std;

using namespace sf;

int main()
{
	// Here is the instabce of TextureHolder
	TextureHolder holder;

	// The game will always be in one of four states
	enum class State { PAUSED, SHOPPING, GAME_OVER, PLAYING };
	// Start with the GAME_OVER state
	State state = State::GAME_OVER;


	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"Zombie Arena");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	window.setVerticalSyncEnabled(true);

	// Create a an SFML View for the main action
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Here is our clock for timing everything
	Clock clock;
	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// Where is the mouse in relation to world coordinates
	Vector2f mouseWorldPosition;
	// Where is the mouse in relation to screen coordinates
	Vector2i mouseScreenPosition;

	// Create an instance of the Player class
	Player player;

	// The boundaries of the arena
	IntRect arena;

	// Create the background
	VertexArray background;
	// Load the texture for our background vertex array
	Texture textureBackground = TextureHolder::GetTexture(
		"C:/Users/tomas/source/repos/ca3/ca3/graphics/background_sheet.png");

	// Prepare for a horde of zombies
	int numZombies;
	int numZombiesAlive = 0;
	list<Zombie*> zombieList;

	//list of bullets
	list<Bullet*> bullets;
	// weapon stuff
	Weapon pistol(24, 6, 1);
	Weapon submachineGun(100, 20, 15);
	Weapon doubleBarreledShotgun(20, 2, 2);
	Weapon machineGun(300, 30, 10);

	// When was the fire button last pressed?
	Time lastPressed;
	Time lastWeaponSwap;

	// Hide the mouse pointer and replace it with crosshair
	window.setMouseCursorVisible(true);
	Sprite spriteCrosshair;
	Texture textureCrosshair = TextureHolder::GetTexture("C:/Users/tomas/source/repos/ca3/ca3/graphics/crosshair.png");
	spriteCrosshair.setTexture(textureCrosshair);
	spriteCrosshair.setOrigin(25, 25);

	// Create a couple of pickups
	Pickup healthPickup(1);
	Pickup ammoPickup(2);

	// About the game
	int score = 0;
	int hiScore = 0;

	// For the home/game over screen
	Sprite spriteGameOver;
	Texture textureGameOver = TextureHolder::GetTexture("C:/Users/tomas/source/repos/ca3/ca3/graphics/background.png");
	spriteGameOver.setTexture(textureGameOver);
	spriteGameOver.setPosition(0, 0);

	// Create a view for the HUD
	View hudView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// Create a sprite for the ammo icon
	Sprite spriteAmmoIcon;
	Texture textureAmmoIcon = TextureHolder::GetTexture("C:/Users/tomas/source/repos/ca3/ca3/graphics/ammo_icon.png");
	spriteAmmoIcon.setTexture(textureAmmoIcon);
	spriteAmmoIcon.setPosition(20, 980);

	// Load the font
	Font font;
	font.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/fonts/zombiecontrol.ttf");

	// Paused
	Text pausedText;
	pausedText.setFont(font);
	pausedText.setCharacterSize(155);
	pausedText.setFillColor(Color::White);
	pausedText.setPosition(400, 400);
	pausedText.setString("Press Enter \nto continue");

	// Game Over
	Text gameOverText;
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(125);
	gameOverText.setFillColor(Color::White);
	gameOverText.setPosition(250, 850);
	gameOverText.setString("Press Enter to play");

	// Levelling up
	Text levelUpText;
	levelUpText.setFont(font);
	levelUpText.setCharacterSize(80);
	levelUpText.setFillColor(Color::White);
	levelUpText.setPosition(150, 250);
	std::stringstream levelUpStream;
	levelUpStream <<
		"1- Buy SubMachineGun			- $100" <<
		"\n2- Buy SubmachineGun			- $300" <<
		"\n3- Buy DoubleBarrelShotgun	- $500" <<
		"\n4- Buy MachineGun				- $1000" <<
		"\n5- Health and Ammo			- $150";
	levelUpText.setString(levelUpStream.str());

	// Ammo
	Text ammoText;
	ammoText.setFont(font);
	ammoText.setCharacterSize(55);
	ammoText.setFillColor(Color::White);
	ammoText.setPosition(200, 880);

	// Score
	Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(55);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(20, 0);

	// Load the high score from a text file/
	std::ifstream inputFile("gamedata/scores.txt");
	if (inputFile.is_open())
	{
		inputFile >> hiScore;
		inputFile.close();
	}

	// Hi Score
	Text hiScoreText;
	hiScoreText.setFont(font);
	hiScoreText.setCharacterSize(55);
	hiScoreText.setFillColor(Color::White);
	hiScoreText.setPosition(1400, 0);
	std::stringstream s;
	s << "Hi Score:" << hiScore;
	hiScoreText.setString(s.str());

	// Zombies remaining
	Text zombiesRemainingText;
	zombiesRemainingText.setFont(font);
	zombiesRemainingText.setCharacterSize(55);
	zombiesRemainingText.setFillColor(Color::White);
	zombiesRemainingText.setPosition(1500, 980);
	zombiesRemainingText.setString("Zombies: 100");

	// Wave number
	int wave = 0;
	Text waveNumberText;
	waveNumberText.setFont(font);
	waveNumberText.setCharacterSize(55);
	waveNumberText.setFillColor(Color::White);
	waveNumberText.setPosition(1250, 980);
	waveNumberText.setString("Wave: 0");

	// Health bar
	RectangleShape healthBar;
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(450, 980);
		
	// When did we last update the HUD?
	int framesSinceLastHUDUpdate = 0;
	// What time was the last update
	Time timeSinceLastUpdate;
	// How often (in frames) should we update the HUD
	int fpsMeasurementFrameInterval = 1000;

	// Prepare the hit sound
	SoundBuffer hitBuffer;
	hitBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/hit.wav");
	Sound hit;
	hit.setBuffer(hitBuffer);

	// Prepare the splat sound
	SoundBuffer splatBuffer;
	splatBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/splat.wav");
	sf::Sound splat;
	splat.setBuffer(splatBuffer);

	// Prepare the shoot sound
	SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/shoot.wav");
	Sound shoot;
	shoot.setBuffer(shootBuffer);

	// Prepare the reload sound
	SoundBuffer reloadBuffer;
	reloadBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/reload.wav");
	Sound reload;
	reload.setBuffer(reloadBuffer);

	// Prepare the failed sound
	SoundBuffer reloadFailedBuffer;
	reloadFailedBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/reload_failed.wav");
	Sound reloadFailed;
	reloadFailed.setBuffer(reloadFailedBuffer);

	// Prepare the powerup sound
	SoundBuffer powerupBuffer;
	powerupBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/powerup.wav");
	Sound powerup;
	powerup.setBuffer(powerupBuffer);

	// Prepare the pickup sound
	SoundBuffer pickupBuffer;
	pickupBuffer.loadFromFile("C:/Users/tomas/source/repos/ca3/ca3/sound/pickup.wav");
	Sound pickup;
	pickup.setBuffer(pickupBuffer);

	// The main game loop
	while (window.isOpen())
	{
		/*
		************
		Handle input
		************
		*/

		// Handle events
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Pause a game while playing
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING) {
					state = State::PAUSED;
				}
				// Restart while paused
				else if (event.key.code == Keyboard::Return &&
					state == State::PAUSED)
				{
					state = State::PLAYING;
					// Reset the clock so there isn't a frame jump
					clock.restart();
				}

				// Start a new game while in GAME_OVER state
				else if (event.key.code == Keyboard::Return &&
					state == State::GAME_OVER)
				{
					state = State::SHOPPING;
					wave = 0;
					score = 0;

					// Prepare the gun and ammo for next game
					player.resetGunPrivilage();

					// Reset the player's stats
					player.resetPlayerStats();
				}
				// Spin and zoom the world
				
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					mainView.rotate(.5f);
				}

				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					mainView.rotate(-.5f);
				}

				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					mainView.zoom(.99f);
				}

				if (Keyboard::isKeyPressed(Keyboard::Down))
				{
					mainView.zoom(1.01f);
				}
				// End spinning and zooming

				if (state == State::PLAYING)
				{
					// Reloading
					if (event.key.code == Keyboard::R)
					{
						if (player.getWeaponEquiped() == 0) {
							pistol.reload();
						}
						else if (player.getWeaponEquiped() == 1) {
							submachineGun.reload();
						}
						else if (player.getWeaponEquiped() == 2) {
							doubleBarreledShotgun.reload();
						}
						else if (player.getWeaponEquiped() == 3) {
							machineGun.reload();
						}
					}
				}

			}
		}// End event polling


		 // Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle controls while playing
		if (state == State::PLAYING)
		{
			if (player.getIsDashing() == false) {
				// Handle the pressing and releasing of the WASD keys
				if (Keyboard::isKeyPressed(Keyboard::W))
				{
					player.moveUp();
				}
				else
				{
					player.stopUp();
				}

				if (Keyboard::isKeyPressed(Keyboard::S))
				{
					player.moveDown();
				}
				else
				{
					player.stopDown();
				}

				if (Keyboard::isKeyPressed(Keyboard::A))
				{
					player.moveLeft();
				}
				else
				{
					player.stopLeft();
				}

				if (Keyboard::isKeyPressed(Keyboard::D))
				{
					player.moveRight();
				}
				else
				{
					player.stopRight();
				}

				if (Keyboard::isKeyPressed(Keyboard::Space)) {
					player.dashStart();
				}

				if (Keyboard::isKeyPressed(Keyboard::Q))
				{
					if ((gameTimeTotal.asSeconds() - lastWeaponSwap.asSeconds()) > 1) {
						player.weaponSwitch();
						lastWeaponSwap = gameTimeTotal;
					}
				}

				// Fire a bullet
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (player.getWeaponEquiped() == 0) {
						if (pistol.shoot(gameTimeTotal.asMilliseconds(), lastPressed.asMilliseconds()))
						{
							// Pass the centre of the player and the centre of the crosshair
							// to the shoot function
							Bullet* b = new Bullet();
							b->shoot(player.getCenter().x, player.getCenter().y, mouseWorldPosition.x, mouseWorldPosition.y);
							bullets.push_back(b);
							lastPressed = gameTimeTotal;
							shoot.play();
						}
					}
					if (player.getWeaponEquiped() == 1) {
						if (submachineGun.shoot(gameTimeTotal.asMilliseconds(), lastPressed.asMilliseconds()))
						{
							// Pass the centre of the player and the centre of the crosshair
							// to the shoot function
							Bullet* b = new Bullet();
							b->shoot(player.getCenter().x, player.getCenter().y, mouseWorldPosition.x, mouseWorldPosition.y);
							bullets.push_back(b);
							lastPressed = gameTimeTotal;
							shoot.play();
						}
					}
					if (player.getWeaponEquiped() == 2) {
						if (doubleBarreledShotgun.shoot(gameTimeTotal.asMilliseconds(), lastPressed.asMilliseconds()))
						{
							// Pass the centre of the player and the centre of the crosshair
							// to the shoot function
							for (int i = 0; i < 10; i++) {
								Bullet* b = new Bullet();
								srand((int)time(0) * i);
								int tempXoffest = rand() % 15 + (-15);
								int tempYoffset = rand() % 15 + (-15);
								b->shoot(player.getCenter().x, player.getCenter().y, (mouseWorldPosition.x + tempXoffest), (mouseWorldPosition.y + tempYoffset), (600) + (tempXoffest * 5), 300);
								bullets.push_back(b);
							}
							lastPressed = gameTimeTotal;
							shoot.play();
						}
					}
					if (player.getWeaponEquiped() == 3) {
						if (machineGun.shoot(gameTimeTotal.asMilliseconds(), lastPressed.asMilliseconds()))
						{
							// Pass the centre of the player and the centre of the crosshair
							// to the shoot function
							Bullet* b = new Bullet();
							srand((int)time(0) * lastPressed.asMilliseconds());
							int tempXoffest = rand() % 5 + (-5);
							int tempYoffset = rand() % 5 + (-5);
							b->shoot(player.getCenter().x, player.getCenter().y, (mouseWorldPosition.x + tempXoffest), (mouseWorldPosition.y + tempYoffset), (800) + (tempXoffest * 3), 1000);
							bullets.push_back(b);
							lastPressed = gameTimeTotal;
							shoot.play();
						}
					}
				}// End fire a bullet
			}// end of is dashing
		}// End WASD while playing

		// Handle the levelling up state
		if (state == State::SHOPPING)
		{
			// Handle the player levelling up
			if (event.key.code == Keyboard::Num1)
			{
				// Increase fire rate
				player.unlockMachineGun();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num2)
			{
				// Increase clip size
				player.unlockDoubleBarreledShotgun();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num3)
			{
				player.unlockMachineGun();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num4)
			{
				// Increase speed
				//player.upgradeSpeed();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num5)
			{
				//healthPickup.upgrade();
				state = State::PLAYING;
			}

			if (event.key.code == Keyboard::Num6)
			{
				//ammoPickup.upgrade();
				state = State::PLAYING;
			}

			if (state == State::PLAYING)
			{
				// Increase the wave number
				wave++;

				// Prepare thelevel
				// We will modify the next two lines later
				arena.width = 500 * wave;
				arena.height = 500 * wave;
				arena.left = 0;
				arena.top = 0;

				// Pass the vertex array by reference 
				// to the createBackground function
				int tileSize = createBackground(background, arena);

				// Spawn the player in the middle of the arena
				player.spawn(arena, resolution, tileSize);

				// Configure the pick-ups
				healthPickup.setArena(arena);
				ammoPickup.setArena(arena);

				// Create a horde of zombies
				numZombies = 7 * wave;

				// Delete the previously allocated memory (if it exists)
				zombieList.clear();
				zombieList = createHorde(numZombies, arena);
				numZombiesAlive = numZombies;

				// Play the powerup sound
				powerup.play();

				// Reset the clock so there isn't a frame jump
				clock.restart();
			}
		}// End levelling up

		 /*
		 ****************
		 UPDATE THE FRAME
		 ****************
		 */
		if (state == State::PLAYING)
		{
			// Update the delta time
			Time dt = clock.restart();
			// Update the total game time
			gameTimeTotal += dt;
			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();

			// Where is the mouse pointer
			mouseScreenPosition = Mouse::getPosition();

			// Convert mouse position to world coordinates of mainView
			mouseWorldPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView);

			// Set the crosshair to the mouse world location
			spriteCrosshair.setPosition(mouseWorldPosition);

			// Update the player
			player.update(dtAsSeconds, Mouse::getPosition());

			// Make a note of the players new position
			Vector2f playerPosition(player.getCenter());

			// Make the view centre around the player				
			mainView.setCenter(player.getCenter());

			// Loop through each Zombie and update them
			for (Zombie* zomb : zombieList) {
				if (zomb->isAlive()) {
					zomb->update(dt.asSeconds(), playerPosition);
				}
			}

			// Update any bullets that are in-flight
			for (Bullet* bull: bullets) {
				if (bull->isInFlight()) {
					bull->update(dtAsSeconds);
				}
			}

			// Update the pickups
			healthPickup.update(dtAsSeconds);
			ammoPickup.update(dtAsSeconds);

			// Collision detection
			// Have any zombies been shot?

			for (Bullet* bull : bullets) {
				for (Zombie* zomb : zombieList) {
					if (bull->isInFlight() && zomb->isAlive()) {
						if (collisionCheck(zomb, bull) == true) {
							if (zomb->hit()) {
								score += 10;
								if (score >= hiScore)
								{
									hiScore = score;
								}

								numZombiesAlive--;
								player.addCash(zomb->getType() * 10);
								player.addExp(zomb->getType() * 10);
								// When all the zombies are dead (again)
								if (numZombiesAlive == 0) {
									state = State::SHOPPING;
								}
							}
							// Make a splat sound
							splat.play();
						}
					}
				}
			}
			// End zombie being shot

			// Have any zombies touched the player
			// if the player is dashing, make them invinvable ie skip the check
			if (player.getIsDashing() == false) {
				for (Zombie* zomb : zombieList) {
					if (player.getPosition().intersects
					(zomb->getPosition()) && zomb->isAlive()) {
						if (player.hit(gameTimeTotal))
						{
							// More here later
							hit.play();
						}

						if (player.getHealth() <= 0)
						{
							state = State::GAME_OVER;

							std::ofstream outputFile("gamedata/scores.txt");
							outputFile << hiScore;
							outputFile.close();

						}
					}
				}// End player touched
			}

			// Has the player touched health pickup
			if (player.getPosition().intersects
				(healthPickup.getPosition()) && healthPickup.isSpawned())
			{
				player.increaseHealthLevel(healthPickup.gotIt());
				// Play a sound
				pickup.play();
				
			}

			// Has the player touched ammo pickup
			if (player.getPosition().intersects
				(ammoPickup.getPosition()) && ammoPickup.isSpawned())
			{
				if (player.getWeaponEquiped() == 0) {
					pistol.getAmmo();
				}
				else if (player.getWeaponEquiped() == 1) {
					submachineGun.getAmmo();
				}
				else if (player.getWeaponEquiped() == 2) {
					doubleBarreledShotgun.getAmmo();
				}
				else if (player.getWeaponEquiped() == 3) {
					machineGun.getAmmo();
				}
				ammoPickup.gotIt();
				// Play a sound
				reload.play();
			}

			// size up the health bar
			healthBar.setSize(Vector2f(player.getHealth() * 3, 70));

			// Increment the amount of time since the last HUD update
			timeSinceLastUpdate += dt;
			// Increment the number of frames since the last HUD calculation
			framesSinceLastHUDUpdate++;
			// Calculate FPS every fpsMeasurementFrameInterval frames
				// Update game HUD text
				std::stringstream ssAmmo;
				std::stringstream ssScore;
				std::stringstream ssHiScore;
				std::stringstream ssWave;
				std::stringstream ssZombiesAlive;

				// Update the ammo text
				if (player.getWeaponEquiped() == 0) {
					ssAmmo  = pistol.getAmmoCount();
				}
				if (player.getWeaponEquiped() == 1) {
					ssAmmo = submachineGun.getAmmoCount();
				}
				if (player.getWeaponEquiped() == 2) {
					ssAmmo = doubleBarreledShotgun.getAmmoCount();
				}
				if (player.getWeaponEquiped() == 3) {
					ssAmmo = machineGun.getAmmoCount();
				}
				ammoText.setString(ssAmmo.str());

				// Update the score text
				ssScore << "Score:" << score;
				scoreText.setString(ssScore.str());

				// Update the high score text
				ssHiScore << "Hi Score:" << hiScore;
				hiScoreText.setString(ssHiScore.str());

				// Update the wave
				ssWave << "Wave:" << wave;
				waveNumberText.setString(ssWave.str());

				// Update the high score text
				ssZombiesAlive << "Zombies:" << numZombiesAlive;
				zombiesRemainingText.setString(ssZombiesAlive.str());

				framesSinceLastHUDUpdate = 0;
				timeSinceLastUpdate = Time::Zero;
			// End HUD update
			list<Bullet*>::iterator it = bullets.begin(); // iterater pointed at the start of list of GameCharecters
			while (it != bullets.end()) {
				if ((*it)->isInFlight() != true) {
					delete* it;
					it = bullets.erase(it); // deletes element that it is pointing at then points it to the element following the deleted element
				}
				else {
					it++;
				}
			}
		}// End updating the scene

		 /*
		 **************
		 Draw the scene
		 **************
		 */

		if (state == State::PLAYING)
		{
			window.clear();

			// set the mainView to be displayed in the window
			// And draw everything related to it
			window.setView(mainView);

			// Draw the background
			window.draw(background, &textureBackground);

			// Draw the zombies
			for (Zombie* zomb : zombieList) {
				window.draw(zomb->getSprite());
			}

			for (Bullet* bull : bullets) {
				window.draw(bull->getShape());
			}

			// Draw the player
			window.draw(player.getSprite());

			// Draw the pickups is currently spawned
			if (ammoPickup.isSpawned())
			{
				window.draw(ammoPickup.getSprite());
			}
			if (healthPickup.isSpawned())
			{
				window.draw(healthPickup.getSprite());
			}

			//Draw the crosshair
			window.draw(spriteCrosshair);

			// Switch to the HUD view
			window.setView(hudView);

			// Draw all the HUD elements
			window.draw(spriteAmmoIcon);
			window.draw(ammoText);
			window.draw(scoreText);
			window.draw(hiScoreText);
			window.draw(healthBar);
			window.draw(waveNumberText);
			window.draw(zombiesRemainingText);
		}

		if (state == State::SHOPPING)
		{
			window.draw(spriteGameOver);
			window.draw(levelUpText);
		}

		if (state == State::PAUSED)
		{
			window.draw(pausedText);
		}

		if (state == State::GAME_OVER)
		{
			window.draw(spriteGameOver);
			window.draw(gameOverText);
			window.draw(scoreText);
			window.draw(hiScoreText);
		}

		window.display();

	}// End game loop

	return 0;
}