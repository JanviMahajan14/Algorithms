/* If we can find all the subarrays then we can find the sum of all the subarrays and 
then we can find the maximum subaray sum also. Time complexity: O(n^3) */

#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n, maxSum=INT_MIN, left=-1, right=-1;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){

            // Finding sum of subaray
            int countSum = 0;

            for(int k=i; k<=j; k++){
                countSum+= a[k];
            }
            // Finding maximum sum of the subarray
            if(countSum > maxSum){
                maxSum = countSum;
                left = i;
                right = j;
            }
        }
    }
    cout << maxSum << endl;
    for(int k=left; k<=right; k++){
        cout << a[k] << " ";
    }
}