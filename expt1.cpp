#include <iostream>
using namespace std;
class employee
{
private:
    string name;
    string number;
    float CurrSalary;
    float UpSalary;

public:
    int cnt;
    void getdata();
    void display1();
    void display2();
    float status();
};
void employee::getdata()
{

    cout << "Enter the name of employee: ";
    cin >> name;
    cout << "Enter the employee number: ";
    cin >> number;
    cout << "Enter the current salary: ";
    cin >> CurrSalary;
}
void employee::display1()
{
    cout << " \t" << name << "\t " << number << "\t\t " << CurrSalary << endl;
}
void employee::display2()
{
    if (cnt == 0)
    {
        cout << " \t" << name << "\t " << number << "\t\t " << CurrSalary << "\t " << UpSalary << "\t\t " << " Promoted " << endl;
    }
    else if (cnt == 1)
    {
        cout << " \t" << name << "\t " << number << "\t\t " << CurrSalary << "\t " << UpSalary << "\t\t " << " Demoted " << endl;
    }
    else if (cnt == 2)
    {
        cout << " \t" << name << "\t " << number << "\t\t " << CurrSalary << "\t " << UpSalary << "\t\t " << " Not Promoted " << endl;
    }
    else if (cnt == 3)
    {
        cout << " \t" << name << "\t " << number << "\t\t " << CurrSalary << "\t " << UpSalary << "\t\t " << " Same " << endl;
    }
    else if (cnt == 4)
    {
        cout << " \t" << name << "\t " << number << "\t\t " << CurrSalary << "\t " << " NA " << "\t\t " << " Same " << endl;
    }
}
float employee::status()
{
    int choice;
    cout << "Update Salary?\n";
    cout << "1. Yes \n";
    cout << "2. NO \n";
    cout << "Enter your choice: \n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter your Updated Salary: " << endl;
        cin >> UpSalary;

        if (UpSalary > CurrSalary && UpSalary >= 50000)
            cnt = 0;
        else if (UpSalary < CurrSalary)
            cnt = 1;
        else if (UpSalary >= CurrSalary && UpSalary < 50000)
            cnt = 2;
        else if (UpSalary == CurrSalary)
            cnt = 3;
        break;
    case 2:
        cnt = 4;
        break;
    default:
        cout << "Invalid input";
    }
}
int main()
{
    int n, i;

    cout << "Enter the number of employees: ";
    cin >> n;
    employee *a = new employee[n + 1];
    for (i = 0; i < n; i++)
    {
        cout << "Employee No." << i + 1 << endl;
        a[i].getdata();
    }
    cout << endl
         << endl;
    cout << " \tName \t Employee number\t Salary\t" << endl;
    for (i = 0; i < n; i++)
    {
        a[i].display1();
    }
    cout << endl
         << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Employee No. " << i + 1 << endl;
        a[i].status();
    }
    cout << endl
         << endl;
    cout << " \tName\t Employee number\tOld Salary\tUpdated Salary\t Status" << endl;
    for (i = 0; i < n; i++)
    {
        a[i].display2();
    }
    return 0;
}
