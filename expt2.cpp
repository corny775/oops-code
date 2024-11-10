#include <iostream>
using namespace std;
class Square;
class Rectangle
{
    int length, breadth;

public:
    void input()
    {
        int l, b;
        printf("Enter length of rectangle: ");
        scanf("%d", &l);
        printf("Enter breadth of rectangle: ");
        scanf("%d", &b);
        length = l;
        breadth = b;
    }
    friend void compareArea(Rectangle, Square);
};
class Square
{
private:
    int side;

public:
    void input()
    {
        int s;
        printf("Enter length of side of square: ");
        scanf("%d", &s);
        side = s;
    }
    friend void compareArea(Rectangle, Square);
};
void compareArea(Rectangle r, Square s)
{
    if (r.length * r.breadth == s.side * s.side)
    {
        printf("Same area\n");
    }
    else
    {
        printf("Not same area");
    }
}
int main()
{
    Rectangle rect;
    Square sqr;
    rect.input();
    sqr.input();
    compareArea(rect, sqr);
    return 0;
}