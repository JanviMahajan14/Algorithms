// Kadane's algorithm: O(n)

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int n, maxSum=INT_MIN;
    cin >> n;
    int a[n], countSum = 0;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // In case all the elements are negative then res is max element else run kadane's 
    if(*max_element(a, a+ n) < 0){
        cout << *max_element(a, a+ n) << endl;
    }
    else{
        // Kadane's algo
        for(int i=0; i<n; i++){
            countSum = countSum + a[i];
            if(countSum < 0){
                countSum = 0;
            }
            maxSum = max(countSum, maxSum);
        }
    cout << maxSum << endl;
    }
}