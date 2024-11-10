#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct contact
{
    string number;
    string name;
    string email;
};
void displayRecords(const string &filename)
{
    ifstream file(filename);
    string line;
    cout << "number, Name, email\n";
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}
void addRecord(const string &filename)
{
    ofstream file(filename, ios::app);
    contact contact;
    cout << "Enter number: ";
    cin >> contact.number;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, contact.name);
    cout << "Enter email: ";
    cin >> contact.email;
    file << contact.number << "," << contact.name << "," << contact.email << endl;
    file.close();
    cout << "Record added successfully.\n";
}
void editRecord(const string &filename)
{
    ifstream file(filename);
    ofstream tempFile("temp.txt");
    contact contact;
    string line, number;
    bool found = false;
    cout << "Enter number of the contact to edit: ";
    cin >> number;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, contact.number, ',');
        getline(ss, contact.name, ',');
        getline(ss, contact.email, ',');
        if (contact.number == number)
        {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, contact.name);
            cout << "Enter new email: ";
            cin >> contact.email;
            found = true;
        }
        tempFile << contact.number << "," << contact.name << "," << contact.email << endl;
    }
    file.close();
    tempFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    if (found)
    {
        cout << "Record updated successfully.\n";
    }
    else
    {
        cout << "Record with number " << number << " not found.\n";
}

}
void deleteRecord(const string &filename)
{
    ifstream file(filename);
    ofstream tempFile("temp.txt");
    contact contact;
    string line, number;
    bool found = false;
    cout << "Enter number of the contact to delete: ";
    cin >> number;
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, contact.number, ',');
        getline(ss, contact.name, ',');
        getline(ss, contact.email, ',');
        if (contact.number != number)
        {
            tempFile << contact.number << "," << contact.name << "," << contact.email << endl;
        }
        else
        {
            found = true;
        }
    }
    file.close();
    tempFile.close();
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
    if (found)
    {
        cout << "Record deleted successfully.\n";
    }
    else
    {
        cout << "Record with number " << number << " not found.\n";
    }
}
int main()
{
    int choice;
    string filename;
    cout << "Enter the file name to manage records (e.g., contacts.txt): ";
    cin >> filename;
    do
    {
        cout << "\ncontact Records Management System\n";
        cout << "1. Display Records\n";
        cout << "2. Add Record\n";
        cout << "3. Edit Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayRecords(filename);
            break;
        case 2:
            addRecord(filename);
            break;
        case 3:
            editRecord(filename);
            break;
        case 4:
            deleteRecord(filename);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
