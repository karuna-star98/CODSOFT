#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void game(int chances, string name)
{
    int number = rand() % 100 + 1;
    int guess;
    int used = 0;

    cout << name << ", I have picked a number between 1 and 100.";
    cout << "\nYou have " << chances << " chances. Try to guess it.\n";

    while (used < chances)
    {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess < 1 || guess > 100)
        {
            cout << "Enter a valid number between 1 and 100.";
            continue;
        }

        used++;

        if (guess == number)
        {
            cout << "\nNice! You guessed the number in " << used << " tries.";

            int score = (chances - used + 1) * 10;
            cout << "\nYour score is: " << score << "\n";
            return;
        }
        else if (guess > number)
        {
            cout << "Too high.";
        }
        else
        {
            cout << "Too low.";
        }

        if (used == 2)
        {
            if (number % 2 == 0)
                cout << "\nHint: number is even.";
            else
                cout << "\nHint: number is odd.";
        }

        cout << "\nChances left: " << chances - used << "\n";
    }

    cout << "\nYou lost. The number was " << number << ".\n";
}

int main()
{
    srand(time(0));

    string name;
    cout << "Enter your name: ";
    cin >> name;

    char again;

    do
    {
        int choice;

        cout << "\n1. Easy\n2. Medium\n3. Hard\nChoose level: ";
        cin >> choice;

        if (choice == 1)
            game(10, name);
        else if (choice == 2)
            game(7, name);
        else if (choice == 3)
            game(5, name);
        else
        {
            cout << "Wrong choice.";
            continue;
        }

        cout << "\nPlay again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nBye " << name << "\n";
    return 0;
}
