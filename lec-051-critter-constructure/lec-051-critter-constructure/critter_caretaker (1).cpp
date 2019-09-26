//Critter Caretaker
//Simulates caring for a virtual pet

#include "Critter_CareTaker.h";


int main()
{
    Critter crit;

    int choice = 1;  //start the critter off talking
    while (choice != 0)
    {
        cout << "\nCritter Caretaker\n\n";
        cout << "0 - Quit\n";
        cout << "1 - Listen to your critter\n";
        cout << "2 - Feed your critter\n";
        cout << "3 - Play with your critter\n\n";
		cout << "4 - See your critter's hunger and boredom!\n\n";

        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:	
            cout << "Good-bye.\n";
			break;
        case 1:	
            crit.Talk();
			break;
        case 2:	
            crit.Eat();
			break;
        case 3:	
            crit.Play();
			break;
		case 4:
			crit.GetStats();
			break;
        default:
            cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
        }
    }

    return 0;
}

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger),
	m_Boredom(boredom)
{}

inline int Critter::GetMood() const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	cout << "I'm a critter and I feel ";

	int mood = GetMood();
	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "okay.\n";
	}
	else
	{
		cout << "happy.\n";
	}

	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp.\n";

	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}

	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Wheee!\n";

	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}

	PassTime();
}

void Critter::GetStats() {
	if (m_Boredom > 15)
	{
		cout << "I'M SO BORE GIVE ME SOMETHING TO DOOOOOOOOOOO.\n";
	}
	else if (m_Boredom > 10)
	{
		cout << "okey, I'm pretty bored atm.\n";
	}
	else if (m_Boredom > 5)
	{
		cout << "I'm getting a tad bored.\n";
	}
	else
	{
		cout << "I'm doing pretty excited!\n";
	}

	if (m_Hunger > 15)
	{
		cout << "and im gonna eat my leg off\n";
	}
	else if (m_Hunger > 10)
	{
		cout << "and i could do with something to eat\n";
	}
	else if (m_Hunger > 5)
	{
		cout << "and I'm getting a tad peckish.\n";
	}
	else
	{
		cout << "and I'm super full!\n";
	}
}
