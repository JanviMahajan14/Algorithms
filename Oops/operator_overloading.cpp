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

    Complex add(Complex c)
    {
        Complex res;
        res.real = real + c.real;
        res.img = img + c.img;
        return res;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
};

int main()
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    // Complex c3 = c1.add(c2); // works fine
    // c3.show();

    // Complex c3 = c1.operator+(c2); // second way
    // c3.show();

    Complex c3 = c1 + c2; // alternative of second method;
    c3.show();
}