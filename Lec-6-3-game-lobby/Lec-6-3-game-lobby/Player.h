#include <iostream>
#include <string>

using namespace std;

class Player
{
	friend ostream& operator<<(ostream& os, const Player& p);
public:
	Player(const string& name = "");
	string GetName() const;
	Player* GetNext() const;
	void SetNext(Player* next);
	
private:
	string m_Name;
	Player* m_pNext;  //Pointer to next player in list
};