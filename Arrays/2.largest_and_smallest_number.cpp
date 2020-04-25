#include <iostream>
#include <climits> //include this library for INT_MIN, INT_MAX
using namespace std;

int main(){
    int largest = INT_MIN;
    int smallest = INT_MAX;

    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i] > largest){
            largest = a[i];
        }
        if(a[i] < smallest){
            smallest = a[i];
        }
    }
    cout << "Largest no is " << largest << endl;
    cout << "Smallest no is " << smallest << endl;
}