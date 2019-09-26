#include <iostream>

using namespace std;

class Critter
{
private:
	int m_Hunger;

public:
	static int s_Total;     //static member variable declaration
							//total number of Critter objects in existence
	/*
	Critter(int hunger = 0);
	static int GetTotal();  //static member function prototype*/

	Critter(int hunger = 0) :
		m_Hunger(hunger)
	{
		cout << "A critter has been born!" << endl;
		++s_Total;
	}

	static int GetTotal()     //static member function definition
	{
		return s_Total;
	}
};