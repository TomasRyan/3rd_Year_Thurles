#ifndef GameCharacter_HEADER
#define GameCharacter_HEADER
#include <iostream>
#include <time.h>
using namespace std;

class GameCharacter {
protected:
	std::string m_typeID;
	int m_health;
	int m_speed; // value between 1 and 3
	int m_x;
	int m_y;
public:
	GameCharacter() {
		this->m_typeID = "error";
		this->m_health = 0;
		this->m_speed = 0;
		this->m_x = 111;
		this->m_y = 111;
	}
	// for sort function with overloading the < function for comparing positions of 2 GameCHaretcters 
	bool operator<(const GameCharacter& a) const
	{
		return ((this->m_x * (this->m_y*12)) < (a.m_x * (a.m_y*12)));
	}

	void spawn(std::string typeID, int health, int speed, int x, int y) { // create an object
		this->m_typeID = typeID;
		this->m_health = health;
		this->m_speed = speed;
		this->m_x = x;
		this->m_y = y;
	}

	void render() { // print to the screen the typeID and its x and y coords
		cout << " " <<this->m_typeID << " ";
		//cout << "Co-ordinates: (" << this->m_x << "," << this->m_y << ")" << endl;
	}
	virtual void update();

	void stats() const { // print all stats relating to the object
		cout << "Type: " << this->m_typeID << endl;
		cout << "Remaining Health: " << this->m_health << endl;
		cout << "Speed: " << this->m_speed << endl;
		cout << "Co-ordinates: (" << this->m_x << "," << this->m_y << ")" << endl;
		cout << ((this->m_x + (this->m_y * 12)) - 1) << endl;
		cout << ((this->m_y - 1) * 12) + (this->m_x) << endl;
	}
	//return true if its  health is greater than 0
	bool isAlive() {
		if (this->m_health > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void RandomPos() {
		srand(rand());
		this->m_x = rand() % 13 + 0;
		srand(rand());
		this->m_y = rand() % 13 + 0;
	}

	int getPos() {
		return ((this->m_y-1) * 12) + (this->m_x);
	}
	// in case of collision, set lower health value GameCharecter to 0, in case of a tie then randomise this objects position
	bool Collision(GameCharacter g2) {
		if (this->getPos() == g2.getPos()) {
			if (this->m_health > g2.m_health) {
				g2.m_health = 0;
			}
			else if((this->m_health < g2.m_health)) {
				this->m_health = 0;
			}
			else {
				this->RandomPos();
			}
		}
	}
};
#endif