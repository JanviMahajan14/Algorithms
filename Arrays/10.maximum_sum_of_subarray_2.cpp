/* We will find cummalative sum of the whole arary then find sum of the subaray. This 
will reduce to O(n^2)*/

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, maxSum=INT_MIN, cumalative_sum[] = {0};
    cin >> n;
    int a[n], countSum;

    cin >> a[0];
    cumalative_sum[0] = a[0];
    // Finding the cummalitive sum
    for(int i=1; i<n; i++){
        cin >> a[i];
        cumalative_sum[i] = cumalative_sum[i-1] + a[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            // Finding sum of subaray
            countSum = cumalative_sum[j] - cumalative_sum[i-1];
            
            
            // Finding maximum sum of the subarray
            if(countSum > maxSum){
                maxSum = countSum;
            }
        }
    }
    cout << maxSum << endl;
}