#include <iostream>
#include <string>
#include <ctime>

void PrintIntro()
{
    // Game Backstory
    std::cout << "\nYou have been caught by a master puzzler and are now in the middle of his greatest creation...\n";
    std::cout << "You must figure out the correct codes to escape the rooms with your life!\n\n";
}

std::string EnterName()
{
    std::string PlayerName;

    std::cout << "Please enter your name: ";
    std::cin >> PlayerName;
    return PlayerName;
}

bool PlayGame(int LevelDifficulty)
{
    std::cout << "This is room " << LevelDifficulty << std::endl;
    // Code Numbers
    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    // Encrypt Code
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Code Numbers Hint
    std::cout << "-- The code consists of 3 numbers!! \n";
    std::cout << "-- The sum of the numbers is: " << CodeSum << std::endl;
    std::cout << "-- The product of the numbers is: " << CodeProduct << std::endl;

    // Player Guesses & Their Results
    int PlayerGuessOne, PlayerGuessTwo, PlayerGuessThree;

    std::cin >> PlayerGuessOne >> PlayerGuessTwo >> PlayerGuessThree;

    int GuessSum = PlayerGuessOne + PlayerGuessTwo + PlayerGuessThree;
    int GuessProduct = PlayerGuessOne * PlayerGuessTwo * PlayerGuessThree;

    // Win/Lose State
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nWow, You're good at this...\n\n";
        return true;
    }
    else
    {
        std::cout << "NOT EVEN CLOSE, TRY IT AGAIN:(\n\n";
        return false;
    }
}

int main()
{
    // Variables for game
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevelDifficulty = 5;
    std::string PlayerName;

    // Do intro and get players name
    PrintIntro();
    PlayerName = EnterName();

    // Play game until win/lose state
    while (LevelDifficulty <= MaxLevelDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "DAMN " << PlayerName << ", YOU GOT OUT, NICE WORK\n\n";
    return 0;
}