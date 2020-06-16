// Remove consective duplicate letters from the string

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    // ways of initialisation
    string s0;
    string s1("hello");
    string s2 = "hello world";
    string s3(s2); /*copy constructor*/

    char a[] = {'a', 'b', 'c', '\0'};
    string s4(a);

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    // empty
    if (s0.empty())
    {
        cout << "s0 is empty";
    }

    // Append
    s0.append("I love c++ and JS");

    // Remove
    cout << s0.length() << endl;
    s0.clear();
    cout << s0.length() << endl;

    // Compare two strings
    string s5 = "Apple";
    string s6 = "Mango";
    cout << s6.compare(s5) << endl; /* returns 0 if s5=s6, else >0 or <0 (lexographical comparision)*/

    // Finding substrings
    string s = "I want to drink apple juice";
    cout << s << endl;
    int inx = s.find("apple");
    cout << inx << endl;

    //Remove substrings
    string sub = "apple";
    s.erase(inx, sub.length());
    cout << s << endl;

    // Iteration methods over the strings
    for (int i = 0; i < s1.length(); i++)
    {
        cout << s1[i] << ",";
    }
    cout << endl;

    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << ":";
    }
    cout << endl;

    for (char c : s1)
    {
        cout << c << "*";
    }
    cout << endl;
}