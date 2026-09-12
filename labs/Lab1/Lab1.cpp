#include <iostream>
#include <cstdlib>

int promptUserForMaximumRange()
{
    std::cout << "Enter the maximum range: ";

    int max{};
    std::cin >> max;

    return max;
}

int pickRandomNumberInRange(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

int promptUserForGuess(int maxRange)
{
    std::cout << "Guess a number between 0 and " << maxRange << ": ";

    int guess{};
    std::cin >> guess;

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
        return true;
    }

    if (answer == 'n' || answer == 'N')
    {
        return false;
    }
    
}

int main()
{
    // Tests
    // --------------------------------------------------
    // 
    // Test promptUserForMaximumRange()
    //std::cout << promptUserForMaximumRange();
    // 
    // Test pickRandomNumberInRange()
    //for (int i = 0; i < 20; i++)
    //{
    //    std::cout << pickRandomNumberInRange(5, 7) << '\n';
    //}
    // 
    // Test promptUserForGuess()
    //std::cout << promptUserForGuess(5) << '\n';
    //
    // Test promptForPlayAgain()
    std::cout << promptForPlayAgain() << '\n';
}