#include "GameCharacter.h";
#include "Game.h";

int main() {
	Game gameloop = Game();
	for (int i = 0; i < 20; i++) {
		gameloop.render();
		gameloop.update();
		gameloop.battle();
		gameloop.stats();
		gameloop.clean();
	}
}