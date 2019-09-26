//Private Critter
//Demonstrates setting member access levels
#include <iostream>

using namespace std;

class Critter
{
public:            // begin public section
    //Critter(int hunger = 0);
	Critter(int hunger = 0, int happyness = 0);
    int GetHunger() const; 
	int Gethappyness() const;
    void SetHunger(int hunger);
private:           // begin private section
    int m_Hunger;
	int m_happyness;
};

/*Critter::Critter(int hunger): 
    m_Hunger(hunger)
{
    cout << "A new critter has been born!" << endl;
}*/

Critter::Critter(int hunger, int happyness) :
	m_Hunger(hunger), m_happyness(happyness)
{
	cout << "A new critter has been born!" << endl;
}

int Critter::GetHunger() const
{
    return m_Hunger;
}

int Critter::Gethappyness() const
{
	return m_happyness;
}

void Critter::SetHunger(int hunger)
{
    if (hunger < 0)
	{
        cout << "You can't set a critter's hunger to a negative number.\n\n";
	}
    else
	{
        m_Hunger = hunger;
	}
}

int main()
{
    Critter crit(5);  
    //cout << crit.m_Hunger; -- illegal, m_Hunger is private!
    cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";
   
    cout << "Calling SetHunger() with -1.\n";
    crit.SetHunger(-1);
    
    cout << "Calling SetHunger() with 9.\n";    
    crit.SetHunger(9);
    cout << "Calling GetHunger(): " << crit.GetHunger() << "\n\n";
    
    return 0;
}
