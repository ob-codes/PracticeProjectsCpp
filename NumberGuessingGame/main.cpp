#include <iostream>
#include <time.h>

int calculate(int);
bool isBallRollOk();
int RNG(int, int);

int main()
{
    std::cout << "This program is for number guessing game..\n";

    int amount = 0, prizemoney;
    std::cout << "How many coins do you want to buy? Each round fee is 10 coins.. \n";
    std::cin >> amount;

    prizemoney = calculate(amount);
    
    if (prizemoney >= 500) std::cout << "You have won max coins!! Game Over" << std::endl;
    else std::cout << "You Dont have enough coins.. Game Over" << std::endl;

    return 0;
}

int calculate(int amount)
{
    int money = 0;
    while (amount > 10 && amount < 500)
    {
        if (isBallRollOk())
        {
            amount /=  0.7;
            std::cout << "You Won!!!" << std::endl;
            std::cout << "Bank Balance: " << amount << std::endl;
        }
        else
        {
            amount *= 0.7;
            std::cout << "You Lost the lottery.." << std::endl;
            std::cout << "Remaining Balance: " << amount << std::endl;
        }
    }
    return money;
}
bool isBallRollOk()
{
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
    return isWon;
}

int RNG(int minimum_number, int max_number)
{
    return rand() % (max_number + 1 - minimum_number) + minimum_number;
}