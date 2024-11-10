#include <iostream>
#include <stack>
using namespace std;
class StackAdapter
{
private:
    stack<int> stk; 
public:
    void push(int value)
    {
        stk.push(value);
        cout << "Pushed " << value << " onto the stack." << endl;
    }
    void pop()
    {
        if (!stk.empty())
        {
            cout << "Popped " << stk.top() << " from the stack." << endl;
            stk.pop();
        }
        else
        {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }
    void top() 
    {
        if (!stk.empty())
        {
            cout << "Top element is: " << stk.top() << endl;
        }
        else
        {
            cout << "Stack is empty." << endl;
        }
    }
    void display() 
    {
        if (stk.empty())
        {
cout << "Stack is empty." << endl;
            return;
        }
        stack<int> temp = stk;
        cout << "Stack elements (from top to bottom): ";
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    bool isEmpty() 
    {
        return stk.empty();
    }
};
int main()
{
    StackAdapter stackAdapter;
    int choice, value;
    do
    {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display Top\n";
        cout << "4. Display All Elements\n";
        cout << "5. Check if Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a value to push: ";
            cin >> value;
            stackAdapter.push(value);
            break;
        case 2:
            stackAdapter.pop();
            break;

        case 3:
            stackAdapter.top();
            break;
        case 4:
            stackAdapter.display();
            break;
        case 5:
            if (stackAdapter.isEmpty())
            {
                cout << "Stack is empty." << endl;
            }
            else
            {
                cout << "Stack is not empty." << endl;
            }
            break;
        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
