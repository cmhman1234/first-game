#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
     std::cout << "Hello weary traveler. You look tired.\n";
    
    std::cout << "If you can beat me in this 7 level game\n I will let you stay in for the night, free of charge\n\n";
    std::cout << "You have made it to level " << Difficulty;
}

bool PlayGame(int Difficulty)
{
    
    PrintIntroduction(Difficulty);

    //initial declarations
    const int Num1 = rand() % Difficulty + Difficulty;
    const int Num2 = rand() % Difficulty + Difficulty;
    const int Num3 = rand() % Difficulty + Difficulty;

    //arithmetic declarations
    const int NumSum = Num1 + Num2 + Num3;
    const int NumProduct = Num1 * Num2 * Num3;

    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "I am thinking of three numbers\n" ;
    std::cout << "The numbers add up to: "<< NumSum ;
    std::cout << "\nthe numbers multiply to give: " << NumProduct << std::endl;
    std::cout << std::endl;
    
    //store player guess
    int GuessA, GuessB, GuessC;
    std::cin>> GuessA;
    std::cin>> GuessB;
    std::cin>> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check to see if guess is correct
    if(GuessSum == NumSum && GuessProduct == NumProduct)
        {
            std::cout << "Great job, Traveler. You move on to the next round \n";
            return true;
        }
    else
        {
            std::cout << "\nSorry, Traveler. That is incorrect. Try again";
            return false;
        }

        

   
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 7;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame( LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            //increase level difficulty
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n Good Job Traveler. You can stay here for the night";
    return 0;
}