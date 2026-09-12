#include <iostream>

int promptUserForMaximumRange()
{
    std::cout << "Enter the maximum range: ";

    int max{};
    std::cin >> max;

    return max;

}

int main()
{
    std::cout << promptUserForMaximumRange();
}