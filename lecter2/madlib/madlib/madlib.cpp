// Mad-Lib
// Creates a story based on user input

#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string prompt);
void tellStory(string* const pname,  string* const pnoun,  int* const pnumber,  string* const pbodyPart,  string* const pverb);

int main()
{
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a verb: ");

	tellStory(&name, &noun, &number, &bodyPart, &verb);

	return 0;
}

string askText(string prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory( string* const pname, string* const pnoun, int* const pnumber, string* const pbodyPart, string* const pverb)
{
	cout << "\nHere's your story:\n";
	cout << "The famous explorer ";
	cout << *pname;
	cout << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of ";
	cout << *pnoun;
	cout << " when one day, the ";
	cout << *pnoun;
	cout << " found the explorer.\n";
	cout << "Surrounded by ";
	cout << *pnumber;
	cout << " " << *pnoun;
	cout << ", a tear came to ";
	cout << *pname << "'s ";
	cout << *pbodyPart << ".\n";
	cout << "After all this time, the quest was finally over. ";
	cout << "And then, the ";
	cout << *pnoun << "\n";
	cout << "promptly devoured ";
	cout << *pname << ". ";
	cout << "The moral of the story? Be careful what you ";
	cout << *pverb;
	cout << " for.";
}
