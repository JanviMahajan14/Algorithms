#include <iostream>
using namespace std;

// int convertToInt(string s, int length){
//     int p,res;
//     if(length == 0){
//         res = 0;
//         p = 1;
//         return s[length]-'0';
//     }

//     int res = res + convertToInt(s,length-1)*p;
//     p = p*10;
//     return s[length]-'0';   
// }

int main(){
    string s;
    cin >> s;
    cout << convertToInt(s,s.size());
}