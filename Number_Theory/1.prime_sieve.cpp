// given a number n find all the prime numbers <N

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
    int n;
    cin >> n;
    int p[n];
    for(int i=0; i<n; i++){
        p[i] = i;
    }

    // if a number is prime then mark it = 1 else mark it = 0
    prime_sieve(p,n);


    // printing only those num that are prime
    for(int i=0; i<n; i++){
        if(p[i]==1){
            cout << i << " ";
        }
    }
}
