#include "GameCharacter.h";

class Player : public GameCharacter {
private:

public:
	Player() {
		string name = "P";
		int health = 170;
		int speed = rand() % 3 + 1;
		srand(rand());
		int x = rand() % 12 + 1;
		srand(rand());
		int y = rand() % 12 + 1;
		this->spawn(name, health, speed, x, y);
	}


	virtual void update() { //virtual function
		cout << "Where would you like to go??" << endl;
		cout << "Type in the corrisponding nuber to go in that direction: " << endl;
		cout << "	1	2	3" << endl;
		cout << "	4	5	6" << endl;
		cout << "	7	8	9" << endl;
		int direction;
		cin >> direction;
		if (direction > 0 && direction < 10) {
			if (direction == 1) { // northwest
				for (int i = 0; i < m_speed; i++) {
					if (this->m_x > 1 && this->m_y > 1) { //
						this->m_x--;
						this->m_y--;
					}
					else if (this->m_x > 1 && this->m_y <= 1) {
						this->m_x --;
						this->m_y ++;
					}
					else if (this->m_x <= 1 && this->m_y > 1) {
						this->m_x ++;
						this->m_y --;
					}
				}
			}
			else if (direction == 2) { // north
				for (int i = 0; i < m_speed; i++) {
					if (this->m_y > 1) {
						this->m_y --;
					}
					else if (this->m_y >= 1) {
						this->m_y ++;
					}
				}
			}
			else if (direction == 3) { // northeast
				for (int i = 0; i < m_speed; i++)
					if (this->m_x < 12 && this->m_y > 1) {
						this->m_x ++;
						this->m_y --;
					}
					else if (this->m_x < 12 && this->m_y <= 1) {
						this->m_x ++;
						this->m_y ++;
					}
					else if (this->m_x >= 12 && this->m_y > 1) {
						this->m_x --;
						this->m_y --;
					}
			}
			else if (direction == 4) { //west
				for (int i = 0; i < m_speed; i++) {
					if (this->m_x > 1) {
						this->m_x--;
					}
					else if (this->m_x <= 1) {
						this->m_x++;
					}
				}
			}
			else if (direction == 5) {
				// yeah we aint moving
			}
			else if (direction == 6) { //east
				for (int i = 0; i < m_speed; i++) {
					if (this->m_x <= 12) {
						this->m_x++;
					}
					else if (this->m_x + 12) {
						this->m_x--;
					}
				}
			}
			else if (direction == 7) { //southwest
				for (int i = 0; i < m_speed; i++) {
					if (this->m_x > 1 && this->m_y < 12) { // ok
						this->m_x--;
						this->m_y++;
					}
					else if (this->m_x > 1 && this->m_y >= 12) {
						this->m_x--;
						this->m_y--;
					}
					else if (this->m_x <= 1 && this->m_y < 12) {
						this->m_x++;
						this->m_y++;
					}
				}
			}
			else if (direction == 8) { //south
				for (int i = 0; i < m_speed; i++) { // okey
					if (this->m_y < 12) {
						this->m_y++;
					}
					else if (this->m_y <= 12) { // y bounce
						this->m_y--;
					}
				}
			}
			else if (direction == 9) { //southeast
				for (int i = 0; i < m_speed; i++) {
					if (this->m_x < 12 && this->m_y < 12) { // both ok
						this->m_x++;
						this->m_y++;
					}
					else if (this->m_x < 12 && this->m_y >= 12) { // y bounce
						this->m_x++;
						this->m_y--;
					}
					else if (this->m_x >= 12 && this->m_y < 12) { // x bounce
						this->m_x--;
						this->m_y++;
					}
				}
			}
			else {
				cout << "please enter a valid input" << endl;
				this->update();
			}
		}
		this->m_health -= m_speed * 2;
	}
};