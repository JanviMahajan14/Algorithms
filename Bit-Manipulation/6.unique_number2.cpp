// Given a set of nos where every number occurs twice except 2 nos. find those two nos.
// ex: [2,3,5,8,5,7,2,8] ans = 3,7
// We need to do this in O(n) and in constant space

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(int num, int index){
    int cnt = 0;
    while(num > 0){
        if((num&1) == 1 && (cnt==index)){
            return true;
        }
        cnt++;
        num = num >> 1;
    }
    return false;
}

int setbitIndex(int res){
    int index = 0;
    while((res&1) == 0){
        res = res >> 1;
        index++;
    }
    return index;
}

int main(){
    int n,res = 0,ans=0;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        res = res ^ a[i];
    }

    // Now res will contain xor of two nos

    // Find the position of first set bit in xor
    int index = setbitIndex(res);

    vector<int>possible;
    for(int i=0; i<n; i++){
        int num = a[i];
        if(isPossible(num,index)){
            possible.push_back(num);
        }
    }
    for(auto it = possible.begin(); it!=possible.end(); it++){
        ans = ans ^ *it;
    }
    int xornum = ans;
    for(int i=0; i<n; i++){
        xornum = xornum ^ a[i];
    }
    cout << min(xornum,ans) << " " << max(xornum,ans);
    
}