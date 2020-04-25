// Finding pairs whose sum is equal to key(given) in a sorted array 

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, key;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> key;

    int i=0, j=n-1;
    while(i<j){
        if(a[i] + a[j] < key){
            i++;
        }
        else if(a[i] + a[j] > key){
            j--;
        }
        else if(a[i] + a[j] == key){
            cout << a[i] << " " << a[j] << endl;
            i++;
            j--;
        }
    }
}