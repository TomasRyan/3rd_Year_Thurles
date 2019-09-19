#include "GameCharacter.h";
#include "Game.h";

int main() {
	Game gameloop = Game();
	gameloop.render();
	//gameloop.update();
	gameloop.battle();
	gameloop.stats();
	gameloop.clean();
}