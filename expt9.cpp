#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class VectorOperations
{
public:
    vector<T> vec1, vec2;
    VectorOperations(vector<T> v1, vector<T> v2)
    {
        vec1 = v1;
        vec2 = v2;
    }
    vector<T> add()
    {
        vector<T> result(vec1.size());
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] + vec2[i];
        }
        return result;
    }
    vector<T> subtract()
    {
        vector<T> result(vec1.size());
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] - vec2[i];
        }
        return result;
    }
    vector<T> multiply()
    {
        vector<T> result(vec1.size());
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] * vec2[i];
        }
        return result;
    }
    vector<T> divide()
    {
        vector<T> result(vec1.size());
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            if (vec2[i] != 0)
            {
                result[i] = vec1[i] / vec2[i];
            }
            else
            {
                cout << "Division by zero error at index " << i << endl;
                result[i] = 0;
            }
        }
        return result;
    }
    void display(const vector<T> &v)
    {
        for (const auto &elem : v)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
};
int main()
{
    int size;
    cout << "Enter the size of the vectors: ";
    cin >> size;
    vector<int> v1(size), v2(size);
    cout << "Enter elements of vector 1:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> v1[i];
    }
    cout << "Enter elements of vector 2:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> v2[i];
    }
    VectorOperations<int> intOps(v1, v2);
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Addition: ";
            intOps.display(intOps.add());
            break;
        case 2:
            cout << "Subtraction: ";
            intOps.display(intOps.subtract());
            break;
        case 3:
            cout << "Multiplication: ";
            intOps.display(intOps.multiply());
            break;
        case 4:
            cout << "Division: ";
            intOps.display(intOps.divide());
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
