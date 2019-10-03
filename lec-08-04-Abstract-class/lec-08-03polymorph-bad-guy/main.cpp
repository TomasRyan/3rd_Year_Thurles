#include "Critter.h"
#include "Farm.h"

void testDestructor();
void testCopyConstructor(Critter aCopy);
void testAssignmentOp();

void Peek(const Critter& aCritter); // function prototype
ostream& operator<<(ostream& os, const Critter& aCritter); // function prototype

int main()
{

	 Critter crit("Poochie");
    cout << "My critter's name is " << crit.GetName() << endl; 

    cout << "\nCreating critter farm.\n";
    Farm myFarm(3);
    
    cout << "\nAdding three critters to the farm.\n";
    myFarm.Add(Critter("Moe"));
    myFarm.Add(Critter("Larry"));
    myFarm.Add(Critter("Curly"));

    cout << "\nCalling Roll...\n";
    myFarm.RollCall();
       
/*
    testDestructor();
    cout << endl;
    
    Critter crit("Poochie", 5);
    crit.Greet();
	cout << "about to call test copy constructor " << endl;
		cout << " Object Crit address " << &crit << endl;
    testCopyConstructor(crit);
	cout << "finished copy constructor " << endl;
	cout << " Object Crit address " << &crit << endl;
    crit.Greet();
    cout << endl;

		cout << "about to call test assignment " << endl;
    
    testAssignmentOp();

	*/

    return 0;
}

void testDestructor()
{
    Critter toDestroy("Rover", 3);
    toDestroy.Greet();
}

void testCopyConstructor(Critter aCopy)  
{
    aCopy.Greet();
}

void testAssignmentOp()
{
    Critter crit1("crit1", 7);
    Critter crit2("crit2", 9);
    crit1 = crit2;
    crit1.Greet();  
    crit2.Greet();
    cout << endl;
        
    Critter crit3("crit3", 11);
    crit3 = crit3;
    crit3.Greet();
	cout << "Testing Overloading of << " << crit3 << endl;
}

void Peek(const Critter& aCritter)
{
    cout << aCritter.m_pName << endl;
}

//global friend function which can access all of Critter object's members
//overloads the << operator so you can send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& aCritter)
{
    os << "Critter Object - ";
    os << "m_pName: " << *aCritter.m_pName << " Age " << aCritter.m_Age;
    return os;
}

