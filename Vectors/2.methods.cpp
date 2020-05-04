#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int>d;
    d.reserve(1000); //To avoid reallocation of memory on pushback
    d.push_back(10); //O(1)
    d.push_back(15);
    d.push_back(25);
    d.push_back(35);

    d.pop_back(); //Delete element at the end O(1)

    d.insert(d.begin()+2,100); // O(n)
    d.insert(d.begin(),4,100); //Inserts 4 elemets of value 100 at 0th address

    // Erase single element
    d.erase(d.begin()+4);
    // Erase multiple elements
    d.erase(d.begin()+1,d.begin()+4);

    // Erase all the elements of vector
    d.clear();
    cout << d.size();

    if(d.empty()){
        cout << "\nThis is empsty vector" << endl;
    }

    for(auto it = d.begin(); it!=d.end(); it++){
        cout << *it << " ";
    }
}