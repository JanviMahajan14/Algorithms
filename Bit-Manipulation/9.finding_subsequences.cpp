// given a string of length n find all the subsequences/subsets
#include<iostream>
using namespace std;

string filter(string s, int i){
    string ans = "";
    int j = 0;
    while(i > 0){
        if(i&1){
            ans = ans + s[j];
        }
        j++;
        i = i >> 1;
    }
    return ans;
}

int main(){
    int n; string s;
    cin >> n;
    cin >> s;
    for(int i=0; i< (1<<n); i++){
        cout << filter(s,i) << " ";
    }
}
