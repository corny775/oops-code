#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    string engine;
    int wheelsize;
    string company;

public:
    Car(int n = 0, const string &comp = "", const string &eng = "");
    ~Car();
    int getNr() { return wheelsize; }
    void setNr(int n) { wheelsize = n; }
    const string &getcomp() const { return company; }
    void setcomp(const string &p) { company = p; }
    const string &getEng() const { return engine; }
    void setEng(const string &e) { engine = e; }
    void display();
};
class PassCar : public Car
{
private:
    int Seatingcapacity;
    bool sunRoof;

public:
    PassCar(int &tp, bool sd, int n = 0, const string &h = "", const string &k = "");
    ~PassCar();
    int &getType() { return Seatingcapacity; }
    void setType(const int s) { Seatingcapacity = s; }
    bool getSunRoof() const { return sunRoof; }
    void setSunRoof(bool b) { sunRoof = b; }
    void display();
};
class Truck : public Car
{
private:
    int axles;
    double tons;

public:
    Truck(int a, double t, int n, const string &hs, const string &k);
    ~Truck();
    void setAxles(int l) { axles = l; }
    int getAxles() { return axles; }
    void setCapacity(double t) { tons = t; }
    double getCapacity() const { return tons; }
    void display();
};
Car::Car(int n, const string &comp, const string &eng)
{
    cout << "Creating an object of type Car." << endl;
    wheelsize = n;
    company = comp;
    engine = eng;
}
Car::~Car()
{
    cout << "Destroying an object of type Car" << endl;
}
void Car::display()
{
    cout << "\nCar number: " << wheelsize << "\ncompany: " << company << "\nEngine: " << engine << endl;
}
PassCar::PassCar(int &tp, bool sd, int n, const string &hs, const string &k) : Car(n, hs, k), Seatingcapacity(tp), sunRoof(sd)
{
    cout << "Creating an object of type PassCar." << endl;
}
PassCar::~PassCar()
{
    cout << "Destroying an object of type PassCar" << endl;
}
void PassCar::display(void)
{
    Car::display();
    cout << "Type: " << Seatingcapacity << "\nSunroof: " << (sunRoof ? "Yes" : "No") << endl;
}
Truck::Truck(int a, double t, int n, const string &hs, const string &k) : Car(n, hs, k), axles(a), tons(t)
{
    cout << "Creating an object of type Truck." << endl;
}
Truck::~Truck()
{
    cout << "Destroying an object of type Truck" << endl;
}
void Truck::display()
{
    Car::display();
    cout << "Axles: " << axles << "\nCapacity: " << tons << " long tons" << endl;
}
int main()
{
    int choice;
    while (1)
    {
        cout << "\n---- Vehicle Creation Menu ----" << endl;
        cout << "1. Create a Truck" << endl;
        cout << "2. Create a PassCar" << endl;
        cout << "3. Create a Car" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        if (choice == 1)
        {
            string engine;
            int axles;
            double capacity;
            long carNumber;
            string company;
            cout << "Enter the number of axles: ";
            cin >> axles;
            cout << "Enter the capacity (in tons): ";
            cin >> capacity;
            cout << "Enter the car number: ";
            cin >> carNumber;
            cout << "Enter the engine: ";
            cin >> engine;
            cout << "Enter the company: ";
            cin >> company;
            Truck userTruck(axles, capacity, carNumber, company, engine);
            userTruck.display();
        }
        else if (choice == 2)
        {
            int seat;
            string company, engine;
            bool sunroof;
            long wheelsize;
            cout << "Enter the seating capacity of the PassCar: ";
            cin >> seat;
            cout << "Does the car have a sunroof? (1 for yes, 0 for no): ";
            cin >> sunroof;
            cout << "Enter the wheel size: ";
            cin >> wheelsize;
            cout << "Enter the engine: ";
            cin >> engine;
            cout << "Enter the company: ";
            cin >> company;
            PassCar userPassCar(seat, sunroof, wheelsize, company, engine);
            userPassCar.display();
        }
        else if (choice == 3)
        {
            string company, engine;
            int carNumber;
            cout << "Enter the engine: ";
            cin >> engine;
            cout << "Enter the car number: ";
            cin >> carNumber;
            cout << "Enter the company: ";
            cin >> company;
            Car userCar(carNumber, company, engine);
            userCar.display();
        }
        else if (choice == 4)
        {
            cout << "Exiting the program." << endl;
            exit(0);
        }
        else
        {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
