#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
class Show
{
public:
    int roomNo;
    string roomType;
    int adults, children, days;
    string fromDate, toDate;
    double rate, amount;
    Show()
    {
        roomNo = 0;
        roomType = "";
        adults = 0;
        children = 0;
        fromDate = "";
        toDate = "";
        days = 0;
        rate = 0;
        amount = 0;
    }
    void inputDetails()
    {
        cout << "Enter room number: ";
        cin >> roomNo;
        cin.ignore();
        cout << "Enter room type (e.g., AC ROOM): ";
        getline(cin, roomType);
        cout << "Enter number of adults: ";
        cin >> adults;
        cout << "Enter number of children: ";
        cin >> children;
        cin.ignore();
        cout << "Enter stay from date (DD/MM/YYYY): ";
        getline(cin, fromDate);
                }
        cout<<"Enter stay to date (DD/MM/YYYY): ";
        getline(cin, toDate);
        cout << "Enter number of days: ";
        cin >> days;
        cout << "Enter room rate per day: ";
        cin >> rate;
        amount = rate * days;
    }
};
int main()
{
    const int maxCustomers = 5;
    Show customers[maxCustomers];
    int customerCount = 0;
    int choice;
    double otherCharges;
    double advancePaid;
    cout << "enter cost of other charges ";
    cin >> otherCharges;
    cout << "enter the payment in advance ";
    cin >> advancePaid;
    while (true)
    {
        cout << "\n---- Cash Bill Menu ----" << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Generate Bill" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        if (choice == 1)
        {
            if (customerCount < maxCustomers)
            {
                customers[customerCount].inputDetails();
                customerCount++;
            }
            else
            {
                cout << "Maximum customer limit reached!" << endl;
        }
    else if (choice == 2)
        {
            if (customerCount > 0)
            {
                time_t currentTime = time(0);
                tm *localTime = localtime(&currentTime);
                srand(time(0));
                int randomno = rand() % 10000 + 1;
                cout << setw(50) << "GOA TOURISM DEVELOPMENT\n";
                cout << setw(49) << "CORPORATION LTD - GOA\n";
                cout << setw(48) << "FARMAGUDI RESIDENCY\n";
                cout << endl;
                cout << setw(92) << setfill('-') << "" << endl;
                cout << setfill(' ');
                cout << setw(40) << "CASH BILL " << "\n";
                cout << setw(92) << setfill('-') << "" << endl;
                cout << setfill(' ');
                cout << "| " << left << setw(40) << "Hotel: FARMAGUDI RESIDENCY"
                     << "| " << right << setw(43) << "Bill No: " << randomno << " |" << endl;
                cout << "| " << left << setw(40) << "Guest: Dr Arun Shandilya"
                     << "| " << right << setw(38) << "Date:" << 1900 + localTime->tm_year << "-"
                     << 1 + localTime->tm_mon << "-"
                     << localTime->tm_mday << " |" << endl;
                cout << "|" << setw(92) << setfill('-') << "|" << endl;
                cout << setfill(' ');
                cout << "| " << setw(5) << "Room1"
                    cout << setfill(' ');
                     << "| " << setw(9) << "Type of Room"
                     << "| " << setw(10) << "No. of Persons"
                     << "| " << setw(21) << "Period of Stay"
                     << "| " << setw(7) << "Days"
                     << "| " << setw(5) << "Rate"
                     << "| " << setw(5) << "Amount in Rs. |"
                     << endl;
                cout << "| " << setw(7) << "No"
                                           "| "
                     << setw(14)
                     << "| " << setw(5) << "Adult"
                     << "|" << setw(8) << "Children"
                     << "| " << setw(12) << "From"
                     << "| " << setw(8) << right << "To|" << setw(32) << "|" << endl;
                cout << "|" << setw(92) << setfill('-') << "|" << endl;
                cout << setfill(' ');
                for (int i = 0; i < customerCount; i++)
                {
                    cout << "| " << setw(5) << customers[i].roomNo
                         << "| " << setw(11) << customers[i].roomType
                         << "| " << setw(6) << customers[i].adults << "| " << setw(7) << customers[i].children
                         << "| " << setw(12) << customers[i].fromDate
                         << "| " << setw(7) << customers[i].toDate
                         << "| " << setw(7) << customers[i].days
                         << "| " << setw(5) << customers[i].rate
                         << "| " << setw(13) << customers[i].amount << " |"
                         << endl;
                    cout << "|" << setw(92) << setfill('-') << "|" << endl;
                }
                double ztotal = 0;
                for (int i = 0; i < customerCount; i++)
                {
                    ztotal += customers[i].amount;
                }
                double totalRoomCharges = ztotal;
                double finalTotal = totalRoomCharges + otherCharges;
                double balanceAmount = finalTotal - advancePaid;
                cout << "| Total Room Charges " << right << setw(70) << totalRoomCharges << " |" << endl;
                cout << "| Other Service Charges " << right << setw(67);
                cout << fixed << setprecision(2) << (totalRoomCharges / 7);
                cout << " |" << endl;
                cout << "| Cancellation Charges " << right << setw(68);
                cout << fixed << setprecision(2) << (totalRoomCharges / 7);
                cout << " |" << endl;
                cout << "| Luxury Tax @ 0.00% " << right << setw(70);
                cout << fixed << setprecision(2) << (otherCharges / 2);
                cout << " |" << endl;
                cout << "| Service Tax @ 0.00% " << right << setw(69);
                cout << fixed << setprecision(2) << (otherCharges / 2);
                cout << " |" << endl;
                cout << "| C.E.S.T. " << right << setw(80);
                cout << fixed << setprecision(2) << otherCharges;
                cout << " |" << endl;
                cout << "| Other Tax " << right << setw(79);
                     << localTime->tm_min << ":"
                     << localTime->tm_sec << endl;
                cout << fixed << setprecision(2) << (otherCharges / 10);
                cout << " |" << endl;
                cout << "|" << setw(92) << setfill('-') << "|" << endl;
                cout << setfill(' ');
                cout << "| Final Total " << right << setw(77) << (finalTotal + 2 * otherCharges + (2 / 7) * totalRoomCharges) << " |" << endl;
                cout << "| Less Advance " << right << setw(76) << advancePaid << " |" << endl;
                cout << "| Balance Amount " << right << setw(74) << balanceAmount << " |" << endl;
                cout << "| Payment Mode: Cash " << setw(72) << " |" << endl;
                cout << setw(92) << setfill('-') << "" << endl;
                cout << setfill(' ');
                cout << "| Signature of the Receptionist " << right << setw(60) << "Signature of the Guest |" << endl
                     << endl;
                cout << setw(92) << setfill('-') << "" << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << setw(92) << setfill('-') << "" << endl;
                cout << setfill(' ');
                cout << setw(57) << "Regt Office TRIONARA APTS, DR ALVARES\n";
                cout << setw(49) << "COSTA ROAD, PANJIM-GOA\n";
                cout << endl;
                cout << setw(48) << "Phone No: 0832-2335122\n";
                cout << "Current Time: "
                     << localTime->tm_hour << ":"

            }
            else
            {
                cout << "No customers added yet!" << endl;
            }
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}