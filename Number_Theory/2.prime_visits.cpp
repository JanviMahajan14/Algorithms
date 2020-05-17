/* given Q no of queries and for each query given two numbers a and b find all the 
numbers between the range a to b; where Q can be max upto 1000 */

#include<iostream>
using namespace std;

void prime_sieve(int *p, int n){

    // mark all the numbers as prime
    for(int i=2; i<n; i++){
        p[i]=1;
    }

    // mark all the multiples of nos from 3 as 0
    for(int i=3; i<n; i=i+2){
        for(int j=i*i; j<n; j=j+i){
            p[j]=0;
        }
    }

    // mark all the even nos as not prime
    for(int i=2; i<n; i=i+2){
        p[i]=0;
    }

    // Special case
    p[2] = 1;
    p[0] = p[1] = 0;
}

int main(){
    int n = 1000000;
    int p[n]={0}; int cm[1000000]={0};

    prime_sieve(p,n);

    for(int i=1; i<=1000000; i++){
        cm[i] = cm[i-1] + p[i];
    }

    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << cm[b]-cm[a-1] << endl;
    }
}
