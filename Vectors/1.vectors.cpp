#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;
    int n,num;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        v.push_back(num);
    }


    vector <int> d = {1,2,3,4,5};

    cout << v.size() << endl; /*size of vector*/
    cout << v.capacity() << endl; /*size of underlying array */
    cout << v.max_size() << endl; /* max no of elements vector can hold in worst case
    according to memory*/

    cout << d.size() << endl;
    cout << d.capacity() << endl;
    cout << d.max_size() << endl;

}

