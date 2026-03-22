#include <iostream>
using namespace std;

int main()
{
    double a, b;
    char op;
    char again;

    cout << "Simple Calculator\n";

    do
    {
        cout << "\nEnter first number: ";
        cin >> a;

        cout << "Enter second number: ";
        cin >> b;

        cout << "\nChoose operation (+, -, *, /): ";
        cin >> op;

        if (op == '+')
        {
            cout << "Result: " << a + b << endl;
        }
        else if (op == '-')
        {
            cout << "Result: " << a - b << endl;
        }
        else if (op == '*')
        {
            cout << "Result: " << a * b << endl;
        }
        else if (op == '/')
        {
            if (b == 0)
            {
                cout << "Cannot divide by zero.\n";
            }
            else
            {
                cout << "Result: " << a / b << endl;
            }
        }
        else
        {
            cout << "Invalid operation.\n";
        }

        cout << "\nDo another calculation? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nCalculator closed.\n";
    return 0;
}
