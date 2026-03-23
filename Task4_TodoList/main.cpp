#include <iostream>
#include <vector>
using namespace std;

struct Task
{
    string text;
    bool done;
};

void showTasks(vector<Task> &list)
{
    if (list.empty())
    {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (int i = 0; i < list.size(); i++)
    {
        cout << i + 1 << ". " << list[i].text;
        if (list[i].done)
            cout << " [Done]";
        else
            cout << " [Pending]";
        cout << "\n";
    }
}

int main()
{
    vector<Task> list;
    int choice;

    do
    {
        cout << "\n1. Add Task";
        cout << "\n2. View Tasks";
        cout << "\n3. Mark Task as Completed";
        cout << "\n4. Remove Task";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Task t;
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, t.text);
            t.done = false;
            list.push_back(t);
            cout << "Task added.\n";
        }
        else if (choice == 2)
        {
            showTasks(list);
        }
        else if (choice == 3)
        {
            showTasks(list);
            int num;
            cout << "Enter task number: ";
            cin >> num;

            if (num >= 1 && num <= list.size())
            {
                list[num - 1].done = true;
                cout << "Task marked as completed.\n";
            }
            else
            {
                cout << "Invalid number.\n";
            }
        }
        else if (choice == 4)
        {
            showTasks(list);
            int num;
            cout << "Enter task number to remove: ";
            cin >> num;

            if (num >= 1 && num <= list.size())
            {
                list.erase(list.begin() + num - 1);
                cout << "Task removed.\n";
            }
            else
            {
                cout << "Invalid number.\n";
            }
        }

    } while (choice != 5);

    cout << "\nExiting To-Do List.\n";
    return 0;
}
