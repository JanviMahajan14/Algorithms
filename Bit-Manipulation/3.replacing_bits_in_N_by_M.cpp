/*Given n number of bits of a number N (int) replace bits of n from i to j 
with M such that M becomes substring of N.
Input N : 1000000000
M = 10101 i=2, j=6;
output = 10001010100
*/


#include<iostream>
using namespace std;

int main(){
    int n = 15;
    int i = 3,j = 1,m = 2;
    // cin >> n >> i >> j >> m;

    // Clear all the bits of  n ranging from index i to j given i > j
    int a = -1 << (i+1);
    int b = ~(-1 << j);
    int mask = a | b;
    int cleared_n = n & mask;

    // And the m to n but before the add some zero bits before m
    int req_m = m << j;
    int result = req_m | cleared_n;
    cout << result;
}
