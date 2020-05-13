// Given a set of nos. where every number occurs thrice except 1 no. find the no.
// ex: [2,2,3,2,3,3,8] ans = 8
// We need to do this in O(n) and in constant space

#include <iostream>
#include <math.h>
using namespace std;

int convertToBinary(int num){
    int ans = 0, p = 1;
    while(num > 0){
        ans = ans + (num&1)*p;
        p = p*10;
        num = num >> 1;
    }
    return ans;
}

int main(){
    int n,num,ans=0,sum=0,p=1,result=0,j=0;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum = sum + convertToBinary(a[i]);
    }
    //sum is stored in decimal form
    while(sum > 0){
        ans = ans + ((sum%10)%3)*p;
        p = p*10;
        sum = sum/10;
    }
    // ans storing the reqd ans in the form of 0's and 1's

    // Getting the decimal number from the ans
    while(ans > 0){
        result = result + (pow(2,j)*(ans%10));
        j++;
        ans = ans/10;
    }
    cout << result;

}