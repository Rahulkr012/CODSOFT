#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int number, Guess_number;
    int guess = 0; // inital guess
    srand(time(0));
    number = rand() % 100 + 1; // generating random number
    cout << "Enter number to guess ";
    // loop for guessing number untill correct guess found
    while (true)
    {
        cin >> Guess_number;
        guess++;
        if (Guess_number < number)
        {
            cout << "Your guess number is low, Try Again!!" << endl;
            cout << "enter number again to guess ";
        }
        else if (Guess_number > number)
        {
            cout << " Your guess number is high, Try Again!!" << endl;
            cout << "enter number again to guess ";
        }
        else
        {
            // Dispaly the output and number of attempts

            cout << " Congratulations! You guessed the correct  number in " << guess << " attempts! ";
            break;
        }
    }
    return 0;
}