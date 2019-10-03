#ifndef Critter_H
#define Critter_H
#include <iostream>
#include <string>

using namespace std;

class Critter
{
	friend void Peek(const Critter& aCritter);
    friend ostream& operator<<(ostream& os, const Critter& aCritter);
 

public: 
    Critter(const string& name = "", int age = 0);  
    ~Critter();                   //destructor prototype   
	Critter(const Critter& c);    //copy constructor prototype
    Critter& operator=(const Critter& c);  //overloaded assignment op
    void Greet() const; 
	string GetName() const; 

private:
    string* m_pName;
    int m_Age;
};





#endif