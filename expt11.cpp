#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class dofile
{
public:
    class FileError
    {
    public:
        string message;
        FileError(const string &msg) : message(msg) {}
    };
    dofile(const string &filename)
    {
        file.open(filename.c_str(), ios::in | ios::out | ios::app);
        if (!file.is_open())
        {
            throw FileError("Error: Unable to open file '" + filename + "'");
        }
    }
    ~dofile()
    {
        if (file.is_open())
        {
            file.close();
        }
    }
    void writeToFile(const string &data)
    {
        if (!file.is_open())
        {
            throw FileError("Error: File is not open for writing.");
        }
        file << data << endl;
    }
    void readFromFile()
    {
        if (!file.is_open())
        {
            throw FileError("Error: File is not open for reading.");
        }
        string line;
        file.seekg(0, ios::beg);
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    void resetFilePointer()
    {
        if (!file.is_open())
        {
            throw FileError("Error: File is not open.");
        }
        file.clear();
        file.seekg(0, ios::beg);
    }
private:
    fstream file;
};
void displayMenu()
{
    cout << "\nFile Operation Menu:" << endl;
    cout << "1. Write to File" << endl;
    cout << "2. Read from File" << endl;
    cout << "3. Reset File Pointer" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;
    try
    {
        dofile fileHandler(filename);
        int choice;
        string data;
        do
             {
            displayMenu();

            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter data to write to file: ";
                cin.ignore();
                getline(cin, data);
                fileHandler.writeToFile(data);
                cout << "Data written to file successfully." << endl;
                break;
            case 2:
                cout << "Reading from file:" << endl;
                fileHandler.readFromFile();
                break;
            case 3:
                fileHandler.resetFilePointer();
                cout << "File pointer reset successfully." << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);
    }
    catch (const dofile::FileError &e)
    {
        cerr << e.message << endl;
    }
    return 0;
}
