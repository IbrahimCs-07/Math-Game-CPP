#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>    
#include "MyLib.h"

using namespace std; 

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, mix = 5 };

struct stGameInfo
{
    short HowManyQuestion = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OperationType;
    short RightAnswer = 0;
    short WrongAnswer = 0;

    string FinalResult(short RightAnswer, short WorngAnswer)
    {
        if (RightAnswer >= WorngAnswer)
        {
            system("color 02");
            return" Pass :-) ";
        }

        else
        {
            system("color 04");
            return " Fail :-( ";
        }
    }
};

short ReadNumber(string Message,short From,short To)
{
    short Number = 0;
    do
    {

        cout << Message;
        cin >> Number;

    } while (Number < From || Number > To);

    return Number;
}

string Tabs(short Number)
{
    string Tabs = "";
    for (short i = 0; i < Number; i++)
    {
        Tabs = Tabs + "\t";
    }

    return Tabs;
}

enQuestionLevel GetQuestionLevel()
{
    return (enQuestionLevel)ReadNumber(("Enter Question Level : [1] Easy, [2] Med, [3] Hard, [4] Mix ? "),1,4);
}

enOperationType GetOperationType()
{
    return (enOperationType)ReadNumber(("Enter Operation Type : [1] Add, [2] Sub, [3] Mult, [4] Div, [5] Mix ? "), 1, 5);
}

short RandomNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

short NumberInLevel(enQuestionLevel QuestionLevel)
{
    if (QuestionLevel == enQuestionLevel::Mix)
    {
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    }

    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy: return RandomNumber(1, 10);
        break;

    case enQuestionLevel::Med: return RandomNumber(25, 45);
        break;

    case enQuestionLevel::Hard: return RandomNumber(50, 89);
        break;
    }
}

char GetOperationTypeOfchar(enOperationType OperationType)
{
    if (OperationType == enOperationType::mix)
    {
        OperationType = (enOperationType)RandomNumber(1, 4);
    }

    switch (OperationType)
    {

    case enOperationType::Add: return '+';
        break;
    case enOperationType::Div: return '/';
        break;
    case enOperationType::Sub: return '-';
        break;
    case enOperationType::Mult: return '*';
        break;

    }
}

string GetOperationTypeOfString(enOperationType OperationType)
{

    switch (OperationType)
    {

    case enOperationType::Add: return "+";
        break;
    case enOperationType::Div: return "/";
        break;
    case enOperationType::Sub: return "-";
        break;
    case enOperationType::Mult: return "*";
        break;
    case enOperationType::mix: return "Mix";
        break;
    }
}

string GetQuestionLevelofString(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy: return "Easy";
        break;
    case enQuestionLevel::Hard: return "Hard";
        break;
    case enQuestionLevel::Med: return "Med";
        break;
    case enQuestionLevel::Mix: return "Mix";
        break;
    }
}

int GetRightAnswer(short Number1, short Number2, char OperationProcess)
{
    switch (OperationProcess)
    {
    case '+': return Number1 + Number2;
        break;
    case '-':return Number1 - Number2;
        break;
    case '*': return Number1 * Number2;
        break;
    case '/': return Number1 / Number2;
        break;
    }
}

stGameInfo MakeQuizz(short QuestionNumber)
{
    stGameInfo GameInfo;
    short Answer = 0,Number1 = 0,Number2 = 0,CorrectAnswer = 0;
    char OperationProcess = ' ';

    GameInfo.HowManyQuestion = QuestionNumber;
    GameInfo.QuestionLevel = GetQuestionLevel();
    GameInfo.OperationType = GetOperationType();
    GameInfo.RightAnswer = 0;
    GameInfo.WrongAnswer = 0;

    for (short i = 1;i <= GameInfo.HowManyQuestion;i++)
    {

        Number1 = NumberInLevel(GameInfo.QuestionLevel);
        Number2 = NumberInLevel(GameInfo.QuestionLevel);
        OperationProcess = GetOperationTypeOfchar(GameInfo.OperationType);

        cout << "\nQuestion[" << i << '/' << GameInfo.HowManyQuestion << "] : \n";
        cout << '\n' << Tabs(1) << Number1 << '\n';
        cout << Tabs(1) <<Number2 << " " << OperationProcess << '\n';
        cout << Tabs(1) <<"------------------\n" << Tabs(1);
        cin >> Answer;

        CorrectAnswer = GetRightAnswer(Number1, Number2, OperationProcess);

        if (Answer == CorrectAnswer)
        {
            cout << '\n' << Tabs(1) << "Right Answer :-) \n";
            system("color 2F");
            GameInfo.RightAnswer++;
        }

        else 
        {
            cout << '\n' << Tabs(1) << "Worng Answer :-( \n";
            cout << Tabs(1) <<"The Right Answer is : " << CorrectAnswer << endl;
            system("color 4F");
            GameInfo.WrongAnswer++;
        }

    }

    return GameInfo;
}

void ResetGame()
{
    system("cls");
    system("color 0F");
}

void ShowGameResult(stGameInfo GameResults)
{
    cout << "\n==========================================================================================================================\n";
    cout << "\n\n" << Tabs(5) << "--------------------------------------\n";
    cout << Tabs(6) << " Final Results" << GameResults.FinalResult(GameResults.RightAnswer, GameResults.WrongAnswer) << endl;
    cout << Tabs(5) << "--------------------------------------\n";
    cout << '\n' << Tabs(5) << "Number of Question     : " << GameResults.HowManyQuestion;
    cout << '\n' << Tabs(5) << "Question Level         : " << GetQuestionLevelofString(GameResults.QuestionLevel);
    cout << '\n' << Tabs(5) << "OpType                  : " << GetOperationTypeOfString(GameResults.OperationType);
    cout << '\n' << Tabs(5) << "Number of Right Answer : " << GameResults.RightAnswer;
    cout << '\n' << Tabs(5) << "Number of Wrong Answer : " << GameResults.WrongAnswer;
    cout << "\n\n" << Tabs(5) << "--------------------------------------\n";

}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetGame();
        stGameInfo GameResults = MakeQuizz(ReadNumber(("Pleas Enter how many question you need ? 1 to 20 ? "),1,20));

        ShowGameResult(GameResults);

        cout << '\n' << Tabs(5) << "Do you want to play again? (Y/N): ";
        cin >> PlayAgain;

        cout << endl;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;  
}