#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class fun
{
public:
    //writing overloading of ()
    void operator()(string s)
    {
        cout << "having fun with " << s;
    }
};

class Person
{
public:
    string name;
    int age;

    Person(string n, int a)
    {
        name = n;
        age = a;
    }
};

class PersonCompare
{
public:
    //class that needs to be passed as a comparator to the priority_queue
    bool operator()(Person A, Person B)
    {
        return A.age < B.age;
    }
};

int main()
{

    // fun f;
    // f("c++");

    priority_queue<Person, vector<Person>, PersonCompare> pq;
    int n;
    cin >> n;
    while (n--)
    {
        string name;
        int age;
        cin >> name >> age;
        Person t(name, age);
        pq.push(t);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << pq.top().name << " " << pq.top().age << endl;
        pq.pop();
    }
}