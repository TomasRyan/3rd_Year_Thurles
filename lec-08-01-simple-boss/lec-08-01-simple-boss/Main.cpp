#include "Enemy.H";
#include "Simple_boss.h";
#include "MegaBoss.h"
int main()
{
	cout << "Creating an enemy.\n";
	Enemy enemy1;
	enemy1.Attack();

	cout << "\nCreating a boss.\n";
	Boss boss1;
	boss1.Attack();
	boss1.SpecialAttack();
	MegaBoss bfg;
	bfg.MegaAttack();
	return 0;
}