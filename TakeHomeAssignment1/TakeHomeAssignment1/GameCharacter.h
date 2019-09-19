#ifndef GameCharacter_HEADER
#define GameCharacter_HEADER
#include <iostream>
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
	// for sort function
	bool operator<(const GameCharacter& a) const
	{
		return ((m_x * m_y) < (a.m_x * a.m_y));
	}

	void spawn(std::string typeID, int health, int speed, int x, int y) { // create an object
		this->m_typeID = typeID;
		this->m_health = health;
		this->m_speed = speed;
		this->m_x = x;
		this->m_y = y;
	}

	void render() { // print to the screen the typeID and its x and y coords
		cout << this->m_typeID;
		//cout << "Co-ordinates: (" << this->m_x << "," << this->m_y << ")" << endl;
	}
	virtual void update() { //virtual function
		cout << "I feel like you messed up if you are reading this" << endl;
		system("Pause");
	}

	void stats() const { // print all stats relating to the object
		cout << "Type: " << this->m_typeID << endl;
		cout << "Remaining Health: " << this->m_health << endl;
		cout << "Speed: " << this->m_speed << endl;
		cout << "Co-ordinates: (" << this->m_x << "," << this->m_y << ")" << endl;
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
		this->m_x = rand() % 12 + 1;
		this->m_y = rand() % 12 + 1;
	}

	int getPos() {
		return m_x*m_y;
	}
};
#endif