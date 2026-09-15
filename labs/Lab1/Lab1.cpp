// ICS 214 - C++ Programming
// LAb 1: Mystery Number Game
//
// Description:
// A number-guessing game that generates a random number within a
// user-defined range and prompts the user to guess until correct.
// The program validates user input and allows for multiple rounds
// to be played.


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>


// Purpose: Discard the remaining characters on the current input line
//			up to and including '\n'.
// Returns: void.
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Purpose: Check std::cin for a failed extraction and restore it to a valid state.
// Returns: true if an extraction failure was handled; false otherwise.
// Side effects: Clears std::cin and discards the current input line on failure.
//               Exits the program if EOF is encountered.
bool clearFailedExtraction()
{
	if (!std::cin)
	{
		// checks for user-entered EOF (CTRL+Z/CTRL+D) and exits program
		if (std::cin.eof()) 
		{
			std::exit(0);
		}

		std::cin.clear();
		ignoreLine(); // discards current input line

		return true;
	}

	return false;
}

// Purpose: Read and validate an int from the user.
// Returns: A successfully parsed int.
int getIntFromUser()
{
	int value{};

	while (true)
	{
		std::cin >> value;

		if (clearFailedExtraction()) // deals with extraction and int overflow errors
		{
			std::cout << "Invalid input. Input must be a valid int. Please try again: ";
			continue;
		}

		ignoreLine(); // deals with extraneous input by discarding additional input
		return value;
	}
}

// Purpose: Read an int from the user within the inclusive range [min, max].
// Parameters:
//   * min - lower bound of the allowed range.
//   * max - upper bound of the allowed range.
// Returns: A valid int within [min, max].
// Precondition: min <= max.
int getIntFromUserInRange(int min, int max)
{
	int value{ getIntFromUser() };

	while (value < min || value > max)
	{
		std::cout << "Invalid input. Range is [" << min << " to " << max << "]. Please try again: ";
		value = getIntFromUser();
	}

	return value;
}

// Purpose: Prompt the user for the maximum value used by the game.
// Returns: An int greater than or equal to 1.
int promptUserForMaximumRange()
{
	std::cout << "Enter the maximum range: ";
	int max{ getIntFromUserInRange(1, INT_MAX) }; // INT_MAX = 2147483647
	return max;
}

// Purpose: Generate a pseudorandom int within the inclusive range [min, max].
// Parameters:
//   * min - lower bound of the range.
//   * max - upper bound of the range.
// Returns: A pseudorandom int within [min, max].
// Precondition: min <= max and std::srand() should be called before this function to seed the randomizer.
int pickRandomNumberInRange(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

// Purpose: Prompt the user for a guess within the inclusive range [0, maxRange].
// Parameters:
//   * maxRange - upper bound of the allowed range.
// Returns: The user's validated guess.
// Precondition: maxRange > 0.
int promptUserForGuess(int maxRange)
{
	std::cout << "Guess a number between 0 and " << maxRange << ": ";
	int guess{ getIntFromUserInRange(0, maxRange) };
	return guess;
}

// Purpose: Ask the user whether they want to play again.
// Returns: true if user answers 'y' or 'Y', false if 'n' or 'N'.
bool promptForPlayAgain()
{
	char answer{};

	while (true)
	{
		std::cout << "Do you wish to play again [y/n]: ";
		std::cin >> answer;

		if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
		{
			std::cout << "invalid input - try again\n";
			continue;
		}

		if (answer == 'y' || answer == 'Y')
		{
			std::cout << '\n'; // prints a new line to create space between the game rounds 
			return true;
		}

		if (answer == 'n' || answer == 'N')
		{
			return false;
		}
	}
}

// Purpose: Play one complete round of the mystery-number guessing game.
// Returns: void.
void playOneRound()
{
	std::cout << "*** Welcome to mystery number ***\n";

	int maxRange{ promptUserForMaximumRange() };

	int randomNumber{ pickRandomNumberInRange(0, maxRange) };
	//std::cout << "randomNunmber is " << randomNumber << '\n'; // debug statement

	int guess{ promptUserForGuess(maxRange) };
	int guessCount{ 1 };
	while (guess != randomNumber)
	{
		std::cout << (guess > randomNumber ? "guess lower..." : "guess higher...") << '\n';
		guessCount++;
		guess = promptUserForGuess(maxRange);
	}

	std::cout << "Correct, it took you " << guessCount << " guesses.\n";
}

// Purpose: Seed the pseudorandom number generator and run game rounds until the user quits.
// Returns: 0 on normal termination.
int main()
{
	srand(static_cast<unsigned int>(time(0))); // seed randomizer - without this line the random numbers will be the same for every run

	bool playing{ true };
	while (playing)
	{
		playOneRound();
		playing = promptForPlayAgain();
	}

	std::cout << "Thanks for playing!\n";


	// Tests
	// --------------------------------------------------
	// 
	// Test promptUserForMaximumRange()
	//std::cout << promptUserForMaximumRange();
	// 
	// Test pickRandomNumberInRange()2
	//for (int i = 0; i < 20; i++)
	//{
	//    std::cout << pickRandomNumberInRange(5, 7) << '\n';
	//}
	// 
	// Test promptUserForGuess()
	//std::cout << promptUserForGuess(5) << '\n';
	//
	// Test promptForPlayAgain()
	//std::cout << promptForPlayAgain() << '\n';
	//
	// Test playOneRound()
	//playOneRound();
}