#include<iostream>
#include<time.h>

int RNG(int , int );

int main()
{
    std::cout << "This program is for number guessing game..\n";

    int input = -1, temp = 0, counter = 10;
    bool isWon = false;

    std::cout << "Choose a number from 0-9: ";    
    std::cin >> input;
    std::cout << std::endl;

    srand(time(0));

    while(counter--)
    {
        temp = RNG(0, 9);
        std::cout << temp  << std::endl;
        if (temp == input)
        {
            isWon = true;
            break;
        }
        _sleep(10);              
    }
    if (isWon) std::cout << "You Won!!!" << std::endl;
    else std::cout << "You Lost the lottery!!!" << std::endl;

    return 0;
}

int RNG(int minimum_number, int max_number)
{
    return rand() % (max_number + 1 - minimum_number) + minimum_number;
}