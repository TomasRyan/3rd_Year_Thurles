#include "GameCharacter.h";

class Enemy : public GameCharacter {
private:

public:
	Enemy() {
		string name = "E";
		int health = 170;
		srand(rand());
		int speed = rand() % 3 + 1;
		int x = rand() % 12 + 1;
		int y = rand() % 12 + 1;
		this->spawn(name, health, speed, x, y);
	}

	virtual void update() {
		/*for (int i = 0; i < this->m_speed; i++) {
			this->m_x += (this->m_speed/this->m_speed);
			this->m_y += (this->m_speed / this->m_speed);
			if (this->m_x < 1 || this->m_x < 12 || this->m_y < 1 || this->m_y < 12) {
				this->m_speed *= -1;
			}
		}
		this->m_health -= (this->m_speed * 3);
	}*/
		int x = this->m_x;
		int y = this->m_y;
		x += this->m_speed;
		y += this->m_speed;
		if (x < 1) {
			while (x < 1) {
				x++;
			}
			this->m_speed *= -1;
		}
		if (x > 12) {
			while (x > 12) {
				x--;
			}
			this->m_speed *= -1;
		}
		if (y < 1) {
			while (y < 1) {
				y++;
			}
			this->m_speed *= -1;
		}
		if (y> 12) {
			while (y > 12) {
				y--;
			}
			this->m_speed *= -1;
		}
		this->m_x = x;
		this->m_y = y;
		this->m_health -= (this->m_speed * 3);
	}
};