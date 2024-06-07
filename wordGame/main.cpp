#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>
//used for a timer
#include<chrono>
#include<thread>

using namespace std;

void menu()
{
    cout<<"\tWelcome to word game"<<endl;
    cout<<"\nEnter 'hint' for a hint"<<endl;
    cout<<"Enter 'quit' to quit the game"<<endl;
    cout<<"Your score will be measured by "<<endl;
    cout<<"The length of the word and time taken to solve"<<endl;
    std::cout<<"\nYour jumbled word is : ";
}

std::string storage(std::string choice)
{
    const int columns = 2;
    const int rows = 7;
    srand(static_cast<unsigned int>(time(0) * 10));
    int randomNum = (rand() % rows);

    std::string wordsAndHints[rows][columns] = {
    {"water", "The body is made up of 70% of it"},
    {"orange", "A fruit that as a name of a color"},
    {"tree", "A source of oxygen and food"},
    {"road", "We travel using it"},
    {"glasses", "I SEE clearly now"},
    {"internet", "we Download and Upload things because of it"},
    {"phone", "I will call you on my ?"}
    };

    std::string guessWord = wordsAndHints[randomNum][0];
    std::string giveHint = wordsAndHints[randomNum][1];
    if(choice == "Word")
    {
        return guessWord;
    }
    else if(choice == "Hint")
    {
        return giveHint;
    }

}
int scoreManager(int hintChecker, int length, auto startTime)
{
     //Timer stops here
    auto stop = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - startTime);
    int timeTaken = duration.count();
    int score = 0;
    if (timeTaken >= 30)
    {
        score += (length*5 + 10);
    }
    else if (timeTaken <= 29 && timeTaken >= 25)
    {
        score += (length*5 + 30);
    }
    else if (timeTaken <= 24 && timeTaken >= 15)
    {
        score += (length*5 + 50);
    }
    else if (timeTaken <= 14 && timeTaken >= 2)
    {
        score += (length*5 + 70);
    }
    //Subtract hintChecker
    score -= hintChecker;
    return score;
}

int main()
{

    menu();
    //All required declaration for the loop
    string yourWord = "NULL";
    const string endGame = "quit";
    int checkForHint = 0;
    string theWord;
    string theHint;
    const string hint = "hint";
    int length;
    //auto start
    do
    {

    srand(static_cast<unsigned int>(time(0)));
    theWord = storage("Word");
    theHint = storage("Hint");

    std::string jumbo = theWord;
    length = jumbo.size();
    for(int i=0; i<length; i++)
    {
        char temp;

        int index1 = (rand() % length);
        int index2 = (rand() % length);

        temp = jumbo[index1];
        jumbo[index1] = jumbo[index2];
        jumbo[index2] = temp;

    }
    //displaying the jumbled word



    //Timer starts here
    auto start = std::chrono::steady_clock::now();
    do
    {
    cout<<jumbo<<endl;
    cout<<"\nEnter your guess :";
    cin>>yourWord;
        if((yourWord != endGame && yourWord != theWord) && yourWord != hint)
        {
            cout<<"Thats not it, Try again"<<endl;
        }
        else if(yourWord == hint)
        {
            checkForHint += 10;
            cout<<theHint<<endl;
            cout<<"\nYour jumbled word is :";

        }


        int totalScore = scoreManager(checkForHint,length,start);
        if (yourWord == theWord)
        {
            cout<<"Your score: "<<totalScore<<endl;
            cout<<"Congratulations you did it, with frying colors\n"<<endl;
        }
        if (yourWord == theWord)
        {
            int choice = 0;
            cout<<"Do you want to continue playing ?"<<std::endl;
            std::cout<<"1.Yes \n2.No"<<std::endl;
            std::cout<<"choice :";
            cin>>choice;
            if(choice == 1)
            {
                std::cout<<"Your jumbled word is : ";
            }
            else
            {
                yourWord = endGame;
            }
        }

    }while(yourWord != endGame && yourWord != theWord);

    }while(yourWord != endGame);
    cout<<"Thank you for playing"<<endl;


    return 0;
}
