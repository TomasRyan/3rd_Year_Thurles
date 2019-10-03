#include "Critter.h"

Critter::Critter(const string& name, int age)
{
    cout << "Constructor called\n";
    m_pName = new string(name);
    m_Age = age;  
}

Critter::~Critter()                        //destructor definition
{
    cout << "Destructor called\n";
    delete m_pName;
}

Critter::Critter(const Critter& c)        //copy constructor definition
{
    cout << "Copy Constructor called\n";
    m_pName = new string(*(c.m_pName));
    m_Age = c.m_Age;
}


Critter& Critter::operator=(const Critter& c)  //overloaded assignment op def
{
    cout << "Overloaded Assignment Operator called\n";
    if (this != &c)
    {
        delete m_pName;
        m_pName = new string(*(c.m_pName));
        m_Age = c.m_Age;
    }
    return *this;
}

void Critter::Greet() const
{
     cout << "&m_pName: " << &m_pName << endl; 
	 cout <<" " << m_Age << " years old. " << endl;

	cout << " I'm " << *m_pName << " and I'm " << m_Age << " years old. " << endl;

}

string Critter::GetName() const 
{
    return *m_pName;
}
