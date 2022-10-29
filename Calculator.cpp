#include <iostream>
#include "Calculator.h"
#include "Conversor.h"

using namespace std;
using namespace NSP_Conversor;

void AskForOperation(int* const& firstNumber, int* const& secondNumber, string* const& mathOperator);
void PrintResult(int number);
int MakeOperation(int firstNumber, int secondNumber, string mathOperation);
void PrintPresentation();

int main()
{
    int firstNumber;
    int secondNumber;
    int resultOperation;
    string mathOperator;
    PrintPresentation();

    while (true)
    {
        AskForOperation(&firstNumber, &secondNumber , &mathOperator);
        resultOperation = MakeOperation(firstNumber, secondNumber, mathOperator);
        PrintResult(resultOperation);
    }
}

//----------------------------------------
void PrintPresentation()
//----------------------------------------
{
    cout << "Welcome to the calculator Conversor \n";
    cout << "operations : \n" << "+ \n" << "- \n" << "* \n" << "/ \n";
   
};

//----------------------------------------
int MakeOperation(int firstNumber, int secondNumber, string mathOperation)
//----------------------------------------
{
    int result = 1;
    if (mathOperation == "+")       result = firstNumber + secondNumber; 
    else if (mathOperation == "-")  result = firstNumber - secondNumber;
    else if (mathOperation == "*")  result = firstNumber * secondNumber;
    else if (mathOperation == "/")  result = firstNumber / secondNumber;

    return result;

}

//----------------------------------------
void AskForOperation(int* const& firstNumber, int* const& secondNumber, string* const& mathOperator)
//----------------------------------------
{
    string operation;
    string mathOperators[4] = { "+" , "-" , "*" , "/"};
    cout << "insert operation\n";
    cin >> operation;

    for (int index = 0; index < 4; index++) {
        int indexOperation = operation.find(mathOperators[index]);
        if (indexOperation != -1)
        {
            string firstNumberString = operation.substr(0, indexOperation);
            string secondNumberString = operation.substr(indexOperation + 1, operation.length());
            *firstNumber = stoi(firstNumberString);
            *secondNumber = stoi(secondNumberString);
            *mathOperator = operation.substr(indexOperation, 1);
            break;
        }
    }
};

//----------------------------------------
void PrintResult(int number)
//----------------------------------------
{
    string result;
    Conversor conversor;

    cout << "The number in decimal is: " << number << "\n";

    result = conversor.DecimalToHexadecimalConversion(number);
    cout << "The number in hexadecimal is: " << result << "\n";

    result = conversor.DecimalToBinaryConversion(number);
    cout << "The number in binary is: " << result << "\n";
 
    result = conversor.DecimalToRomanConversion(number);
    cout << "The number in Roman is: " << result << "\n";

}

