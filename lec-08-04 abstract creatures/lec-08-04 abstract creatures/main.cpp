#include "Orc.h"
#include "Troll.h"
#include "Unicorn.h"
#include <vector>


int main()
{
    Creature* pCreatureO = new Orc();
    pCreatureO->Greet();
    pCreatureO->DisplayHealth();
	pCreatureO->DisplaySpeed();
	Creature* pCreatureT = new Troll();
	pCreatureT->Greet();
	pCreatureT->DisplayHealth();
	pCreatureT->DisplaySpeed();
	Creature* pCreatureU = new Unicorn();
	pCreatureU->Greet();
	pCreatureU->DisplayHealth();
	pCreatureU->DisplaySpeed();

	vector<Creature*> vpCreatures; //created a vector of Creature pointers
	vpCreatures.push_back(pCreatureO); //added an Orc to the vector
	vpCreatures.push_back(pCreatureT);
	vpCreatures.push_back(pCreatureU);

	vector<Creature*>::const_iterator iter;
	cout << "Using a vector to cycle through all the Creatures \n";

	for (int x = 0; x < 10; x++) {
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->Greet();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->DisplaySpeed();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->DisplayHealth();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->DisplaySpeed();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->DisplaySpeed();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->Update();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			(*iter)->DisplayHealth();
		}
		for (iter = vpCreatures.begin(); iter != vpCreatures.end(); ++iter)
		{
			if ((*iter)->healthCheck() == true) {
				vpCreatures.(iter);
				vpCreatures.push_back(*iter);
			}
		}

	}

	getchar();
    
    return 0;
}
