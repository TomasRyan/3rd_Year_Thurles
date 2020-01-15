#pragma once
class HudManager {
private:
	// Create a view for the HUD
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	View hudView(sf::FloatRect(0, 0, resolution.x, resolution.y));
	// Health bar
	RectangleShape healthBar;
	healthBar.setFillColor(Color::Red);
	healthBar.setPosition(450, 980);

	// Hi Score
	Text hiScoreText;
	hiScoreText.setFont(font);
	hiScoreText.setCharacterSize(55);
	hiScoreText.setFillColor(Color::White);
	hiScoreText.setPosition(1400, 0);
	std::stringstream s;
	s << "Hi Score:" << hiScore;
	hiScoreText.setString(s.str());
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
	// experiance
	RectangleShape experianceBar;
	experianceBar.setFillColor(Color::Blue);
	experianceBar.setPosition(450, 980);
	// experiance OutLine
	RectangleShape experianceBar;
	experianceBar.setSize(sf::Vector2f(100, 50));
	experianceBar.setOutlineColor(Color::White);
	experianceBar.setPosition(450, 980);

	// cash
	Text cashText;
	cashText.setFont(font);
	cashText.setCharacterSize(55);
	cashText.setFillColor(Color::White);
	cashText.setPosition(20, 0);
public:

};