#include <iostream>
#include <string.h>
using namespace std;
class bankAccount
{
    string name;
    int acc_num;
    string type;
    double bal;
    static double interest;

public:
    bankAccount();
    bankAccount(string, int, string, double);
    bankAccount(const bankAccount &);
    void deposit(double);
    void withdraw(double);
    void display() const;
    static void displayInterest();
    ~bankAccount();
};
double bankAccount::interest = 0.1;
bankAccount::bankAccount(string n, int acc, string t, double b)
{
    name = n;
    acc_num = acc;
    type = t;
    bal = b;
}
bankAccount::bankAccount(const bankAccount &b)
{
    name = b.name;
    acc_num = b.acc_num;
    type = b.type;
    bal = b.bal;
}
bankAccount::bankAccount()
{
    bal = 0;
}
void bankAccount::deposit(double dp)
{
    bal += dp;
}
void bankAccount::withdraw(double w)
{
    if (bal - w < 2000)
    {
        cout << "\nInsufficient Balance\n";
        return;
    }
    bal -= w;
}
void bankAccount::display() const
{
    cout << "\nName: " << name;
    cout << "\nAccount number: " << acc_num;
    cout << "\nType: " << type;
    cout << "\nBalance: " << bal;
    cout << "\n";
}
void bankAccount::displayInterest()
{
    cout << "\nInterest: " << interest << "\n";
}
bankAccount::~bankAccount()
{
    cout << "\nDeleted the Object for Account Number: " << acc_num << "\n";
}
int main()
{
    int n;
    cout << "Enter the number of bank accounts to create: ";
    cin >> n;
    bankAccount *accounts = new bankAccount[n];
    for (int i = 0; i < n; ++i)
    {
        string name;
        int acc_num;
        string type;
        double bal;
        cout << "\nEnter details for account " << i + 1 << ": ";
        cout << "\nName: ";
        cin >> ws;
        getline(cin, name);
        cout << "Account number: ";
        cin >> acc_num;
        cout << "Type: ";
        cin >> type;
        cout << "Initial Balance: ";
        cin >> bal;
        new (&accounts[i])
            bankAccount(name, acc_num, type, bal);
    }
    for (int i = 0; i < n; ++i)
    {
        accounts[i].display();
    }
    for (int i = 0; i < n; ++i)
    {
        double depositAmount,
            withdrawalAmount;
        cout << "\nDepositing into account " << i + 1 << ": ";
        cout << "\nEnter deposit amount: ";
        cin >> depositAmount;
        accounts[i].deposit(depositAmount);
        accounts[i].display();
        cout << "\nWithdrawing from account " << i + 1 << ": ";
        cout << "\nEnter withdrawal amount: ";
        cin >> withdrawalAmount;
        accounts[i].withdraw(withdrawalAmount);
        accounts[i].display();
    }
    bankAccount::displayInterest();
    return 0;
}