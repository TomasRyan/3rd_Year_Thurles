#include "GameCharacter.h";
#include "Player.h";
#include "Enemy.h";
#include <list>;
#include <vector>

class Game {
private:
	list<GameCharacter*> vpGameCharacters;
public:
	Game() {
		init();
	}
	void init() { // create the objects and assign each enemy and player unique typeID, health and x and y coords max health should be 170, speed is between 1 and 3. Place these GameCharacters in a vector of GameCharacter pointers e.g. vpGameCharacters
		//vpGameCharacters.empty();
		Player* pPlayer = new Player();
		pPlayer->RandomPos();
		vpGameCharacters.push_back(pPlayer);
		for (int i = 0; i < 4; i++) {
			Enemy* pEnemy = new Enemy();
			pEnemy->RandomPos();
			vpGameCharacters.push_back(pEnemy);
		}
		//Enemy e = Enemy();
		/*e.RandomPos();
		vpGameCharacters.push_back(e);
		//----------
		Enemy a = Enemy();
		a.RandomPos();
		vpGameCharacters.push_back(a);
		//----------
		Enemy b = Enemy();
		b.RandomPos();
		vpGameCharacters.push_back(b);
		//----------
		Enemy c = Enemy();
		c.RandomPos();
		vpGameCharacters.push_back(c);
		//----------
		Enemy d = Enemy();
		d.RandomPos();
		vpGameCharacters.push_back(d);
		//----------*/
	}

	void render() { // cycle through the vector of GameCharacter ( enemy and player objects) and call the render function for each object
		vpGameCharacters.sort();
		bool isDrawn = false;
		for (int i = 0; i < 144; i++) {
			isDrawn = false;
			if (i % 12 == 0) {
				cout << endl;
			}
			int y = i+1;
			for (GameCharacter *g : vpGameCharacters) {
				if ((*g).getPos() == y && isDrawn == false) {
					(*g).render();
					isDrawn = true;
				}
			}
			if (isDrawn == false) {
				cout << " o ";
				//cout << i << endl;
			}
		}
		cout << "" << endl;
		cout << "----------------------------------" << endl;
	}

	void update() { //cycle through the vector of GameCharacter (enemy and player objects) and call the update function for each object
		for (GameCharacter  *g : vpGameCharacters) {
			(*g).update();
		}
	}
	void battle() {  // Check the vector to see if two objects occupy the same coords declare that a battle must take  place. The object with the higher health wins. The loser will have its health set to 0.
		vector<GameCharacter*> gca;
		for (GameCharacter* g : vpGameCharacters) {
			gca.push_back(g);
		}
		vector<GameCharacter*>::const_iterator iter1;
		vector<GameCharacter*>::const_iterator iter2;
		for (iter1 = iter1; iter1 != gca.end(); ++iter1)
		{
			for (iter2 = gca.begin()++; iter2 != gca.end(); ++iter2)
			{
				(*iter1)->Collision(iter2);
			}
		}
	}
	void stats() { // cycle through the vector of GameCharacters ( enemy and player objects) and call the stats function for each object
		for (GameCharacter  *g : vpGameCharacters) {
			(*g).stats();
		}  
	}
	void clean() { //remove any objects from the list whose health is 0 (Hint use isAlive function)
		for (GameCharacter* g : vpGameCharacters) {
			if (*g->isAlive != true) {
				vpGameCharacters.remove(g);
			}
		}
	}
};