// Hangman
// The classic game of hangman

#include <iostream>
#include"hangmanHeader.h"

void TopOfRound(int max, int w, string usedLetters, string usedWords) {
	cout << "\n\nYou have " << (max - w);
	cout << " incorrect guesses left.\n";
	cout << "\nYou've used the following letters:\n" << usedLetters << endl;
	cout << "\nSo far, the word is:\n" << usedWords << endl;
}

void GameOver(int max, int wrongLtters, string theWord) {
	// shut down
	if (wrongLtters == max)
		cout << "\nYou've been hanged!";
	else
		cout << "\nYou guessed it!";

	cout << "\nThe word was " << theWord << endl;
}

void gameLoop(string * pusedLetters, string theWord, string * pwordSoFar, int * pwrongGuesses) {
	char guess;
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess); //make uppercase since secret word in uppercase
	while ((*pusedLetters).find(guess) != string::npos)
	{
		cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}

	*pusedLetters += guess;

	if (theWord.find(guess) != string::npos)
	{
		cout << "That's right! " << guess << " is in the word.\n";

		// update soFar to include newly guessed letter
		for (unsigned int i = 0; i < theWord.length(); ++i)
		{
			if (theWord[i] == guess)
			{
				(*pwordSoFar)[i] = guess;
			}
		}
	}
	else
	{
		cout << "Sorry, " << guess << " isn't in the word.\n";
		++*pwrongGuesses;
	}
}

int main()
{
	// set-up
	const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

	vector<string> words;  // collection of possible words to guess
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];            // word to guess
	int wrong = 0;                               // number of incorrect guesses
	string soFar(THE_WORD.size(), '-');          // word guessed so far
	string used = "";                            // letters already guessed

	cout << "Welcome to Hangman.  Good luck!\n";

	// main loop
	while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
	{
		TopOfRound(MAX_WRONG, wrong, used, soFar);
		gameLoop(&used, THE_WORD, &soFar, &wrong);
		
	}
	GameOver(MAX_WRONG, wrong, THE_WORD);
	// shut down
	return 0;
}