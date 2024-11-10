#include <iostream>
using namespace std;
class node
{
    int info;
    node *link;

public:
    void *operator new(size_t n)
    {
        return new size_t;
    }
    void operator delete(void *ptr)
    {
        free(ptr);
    }
    node()
    {
        info = 0;
        link = NULL;
    }
    node(int i, node *l = NULL)
    {
        info = i;
        link = l;
    }
    node operator+(int info)
    {
        node *tmp = new node(info);
        if (this == NULL)
        {
            return *tmp;
        }
        node *p = this;

        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = tmp;
        tmp->link = NULL;
        return *this;
    }
    node operator-(int item)
    {
        node *p = this, *tmp;
        while (p->link != NULL)
        {
            if (p->link->info == item)
            {
                tmp = p->link;
                p->link = tmp->link;
                delete tmp;
                return *this;
            }
            p = p->link;
        }
        cout << "Item with data=" << item << " not found\n";
        return *this;
    }
    void display()
    {
        node *p = this;
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->link;
        }
        cout << "\n";
    }
    void deleteAlloc()
    {
        node *prev, *p = this;
        while (p != NULL)
        {
            prev = p;
            p = p->link;
            delete prev;
        }
    }
};
int main()
{
    node p;
    p = p + 2;
    p = p - 3;
    while (1)
    {
        int choice, a;
        cout << "enter a choice" << endl;
        cout << "1=insert an element" << endl;
        cout << "2=delete an element" << endl;
        cout << "3=display the list" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter element to be inserted" << endl;
            cin >> a;
            p = p + a;
            break;
        case 2:
            cout << "enter element to be deleted" << endl;
            cin >> a;
            p = p - a;
            break;
        case 3:
            p.display();
            break;
        default:
            exit(0);
        }
    }
    p.deleteAlloc();
    return 0;
}
