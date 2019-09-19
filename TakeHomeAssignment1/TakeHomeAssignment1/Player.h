#include "GameCharacter.h";

class Player : public GameCharacter {
private:

public:
	Player() {
		string name = "P";
		int health = 3;
		int speed = rand() % 3 + 1;
		int x = rand() % 12 + 1;
		int y = rand() % 12 + 1;
		this->spawn(name, health, speed, x, y);
	}


	virtual void update() { //virtual function

	}
};