#include "GameCharacter.h";
#include "Player.h";
#include "Enemy.h";
#include <list>;

class Game {
private:
	list<GameCharacter> vpGameCharacters;
public:
	Game() {
		init();
	}
	void init() { // create the objects and assign each enemy and player unique typeID, health and x and y coords max health should be 170, speed is between 1 and 3. Place these GameCharacters in a vector of GameCharacter pointers e.g. vpGameCharacters
		vpGameCharacters.empty();
		Player p = Player();
		vpGameCharacters.push_back(p);
		for (int i = 0; i < 4; i++) {
			Enemy e = Enemy();
			vpGameCharacters.push_back(e);
		}
	}

	void render() { // cycle through the vector of GameCharacter ( enemy and player objects) and call the render function for each object
		//vpGameCharacters.sort();
		bool isDrawn = false;
		for (int i = 0; i <= 143; i++) {
			isDrawn = false;
			if (i % 12 == 0) {
				cout << endl;
			}
			for (GameCharacter g : vpGameCharacters) {
				if (g.getPos() == i && isDrawn == false) {
					g.render();
					isDrawn = true;
				}
			}
			if (isDrawn == false) {
				cout << "o";
			}
		}
		cout << "" << endl;
	}

	void update() { //cycle through the vector of GameCharacter (enemy and player objects) and call the update function for each object
		
		for (GameCharacter  g : vpGameCharacters) {
			g.update();
		}
	}
	void battle() {  // Check the vector to see if two objects occupy the same coords declare that a battle must take  place. The object with the higher health wins. The loser will have its health set to 0.

	}
	void stats() { // cycle through the vector of GameCharacters ( enemy and player objects) and call the stats function for each object
		for (GameCharacter  g : vpGameCharacters) {
			g.stats();
		}  
	}
	void clean() { //remove any objects from the list whose health is 0 (Hint use isAlive function)
		
	}
};