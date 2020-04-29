#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    // returning in lexographical if they are of equal lengths
    if(a.length() == b.length()){
        return a < b;
    } 
    return a.length() < b.length();
}

int main(){
    // Arrays of strings
    string s[100];
    int n;
    cin >> n;
    cin.get();

    for(int i=0; i<n; i++){
        // cin.getline(s[i],100); this doesn't work in case of strings
        getline(cin,s[i]);
    }

    // Sorting all the strings in lexographical order
    sort(s,s+n);

    for(int i=0; i<3; i++){
        cout << s[i] << endl;
    }

    // If we want to sort on the basis of length of strings
    sort(s,s+n,compare);
    for(int i=0; i<3; i++){
        cout << s[i] << endl;
    }
}