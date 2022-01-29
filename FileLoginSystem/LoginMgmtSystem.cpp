#include "LoginMgmtSystem.h"

int main()
{
    std::cout << "This project aims to give sign up and login form and create a requisite folder\n";
    
    char temp;
    
    std::cout << "Enter Y for signup and N for Login..: ";
    std::cin >> temp;
    
    if(temp != 'Y' && temp != 'y' && temp != 'N' && temp != 'n')
    {
        std::cout << "Error..\n";
    }
    else
    {
        std::cout << "\nEnter username: ";
        std::cin >> username;

        if (username.find(".txt") != std::string::npos) { }
        else { username += ".txt"; }

        std::fstream myFile;
        if (temp == 'Y' || temp == 'y') //register
        {
            myFile.open(username);
            if (!myFile)
            {
                std::cout << "Valid ID..\n";

                std::cout << "\nEnter pwd: ";
                std::cin >> pwd;
                myFile.open(username, std::ios::out);
                myFile << pwd; //writing file content
            }
            else std::cout << "Username not spare..\n";
            myFile.close();
        }
        else //login
        {
            std::cout << "\nEnter pwd: ";
            std::cin >> pwd;
            myFile.open(username, std::ios::in);

            if (!myFile.is_open())  std::cout << "Error opening file..\n";
            else
            {
                std::string temp;

                std::getline(myFile, temp); //reading file content

                if (pwd == temp) std::cout << "Authorized Login\n"; //comparing input pwd with stored pwd
                else std::cout << "Username or pwd incorrect..\n";
            }
            myFile.close();
        }
    }
    return 0;
}