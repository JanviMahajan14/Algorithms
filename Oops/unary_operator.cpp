#include <iostream>
using namespace std;

class Complex
{
public:
    int real, img;

    Complex()
    {
    }

    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    void show()
    {
        cout << real << " + i" << img << endl;
    }

    Complex operator-() //for overloading of unary operator don't pass second argument
    {
        Complex temp;
        temp.real = -1 * real;
        temp.img = -1 * img;
        return temp;
    }
};

int main()
{
    Complex c1(1, 2);
    Complex c2 = -c1; //unary operator-----1st way of calling
    // Complex c2 = c1.operator-(); //------2nd way of calling
    c2.show();
}