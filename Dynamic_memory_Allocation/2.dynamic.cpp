#include <iostream>
using namespace std;

int main(){
    // Static
    int b[100] = {0};
    cout << sizeof(b) << endl;
    cout << b << endl; /*from symbol table(mapping from virtual to physical) */
    // Here b can't be overwritten it's a part of read only memory

    // Dynamic memory allocation
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    delete [] a; 
    // a = new int[10];
    // a stored in static memory can be overwritten by declarlation of a
    // like char*a = new char;
}
