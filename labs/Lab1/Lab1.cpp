#include <iostream>
#include <cstdlib>

// discards all characters in the input stream up to and including \n
void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool clearFailedExtraction()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			std::exit(0);
		}

		std::cin.clear();
		ignoreLine();

		return true;
	}

	return false;
}

int getIntFromUser()
{
	int value{};

	while (true)
	{
		std::cin >> value;

		if (clearFailedExtraction())
		{
			std::cout << "Invalid input. Input must be a valid int. Please try again: ";
			continue;
		}

		ignoreLine();
		return value;
	}
}

int promptUserForMaximumRange()
{
	std::cout << "Enter the maximum range: ";
	int max{getIntFromUser()};
	return max;
}

int pickRandomNumberInRange(int min, int max)
{
	return min + (rand() % (max - min + 1));
}

int promptUserForGuess(int maxRange)
{
	std::cout << "Guess a number between 0 and " << maxRange << ": ";
	int guess{getIntFromUser()};
	return guess;
}

bool promptForPlayAgain()
{
	std::cout << "Do you wish to play again [y/n]: ";

	char answer{};
	std::cin >> answer;

	if (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
	{
		std::cout << "invalid input - try again\n";
		promptForPlayAgain();
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

	return false; // default behavior for UB is to quit out
}

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