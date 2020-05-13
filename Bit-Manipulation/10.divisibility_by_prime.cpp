/* Given a number N. Find the number of nos. <N which are divisible by all the prime numbers
between 1 to 20*/

#include <iostream>
# define ll long long
using namespace std;

int main(){
    ll prime[] = {2,3,5,7,11,13,17,19};
    ll n,result = 0;
    cin >> n;
    for(ll k=1; k< (1 << 8); k++){
        ll i = k;
        ll ans = 1, j = 0;
        // iterating over the binary subset 1010 to find single digit subset or product of subsets in case of multiple digits
        while(i > 0){
            if(i&1){
                ans = ans * prime[j];
            }
            j++;
            i = i >> 1;
        }

        // Finding length of subset is odd/even based on no. of set bits
        if(__builtin_popcount(k)&1){
            ll den = (n/ans);
            result = result + den;
        }
        else{
            ll den = (n/ans);
            result = result - den;
        }
    }
    cout << result << endl;
    
}