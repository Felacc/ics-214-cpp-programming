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

int main()
{
    //std::cout << promptUserForMaximumRange();

    for (int i = 0; i < 20; i++)
    {
        std::cout << pickRandomNumberInRange(5, 7) << '\n';
    }

}