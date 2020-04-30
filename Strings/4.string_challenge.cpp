#include<iostream>
#include <string.h>
#include <algorithm>
using namespace std;
// important qs

string extractTokens(string str, int key){
    char *ptr = strtok((char *)str.c_str()," ");
    key--;
    while(key--){
        ptr = strtok(NULL," ");
    }
    return string(ptr);

}

int convertToInt(string s){
    int ans = 0;
    int p =1;
    for(int i=s.length()-1; i>=0; i--){
        ans+=((s[i] - '0')*p);
        p = p*10;
    }
    return ans;
}

bool numericCompare(pair<string,string>s1, pair<string,string>s2){
    string firstToken = s1.second;
    string secondToken = s2.second;
    return convertToInt(firstToken) < convertToInt(secondToken);
}

bool lexcoCompare(pair<string,string>s1, pair<string,string>s2){
    return s1.second < s2.second;
}

int main(){
    int n;
    cin >> n;
    cin.get();
    string s[n];
    for(int i=0; i<n; i++){
        getline(cin,s[i]);
    }
    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    // Extract the tokens and storing the string and token in pairs
    pair<string, string> strpair[n];

    for(int i=0; i<n; i++){
        strpair[i].first = s[i];
        strpair[i].second = extractTokens(s[i], key);
    }

    // Sorting of strings
    if(ordering == "numeric"){
        sort(strpair, strpair+n, numericCompare);
    }
    else{
        sort(strpair, strpair+n, lexcoCompare);
    }

    if(reversal == "true"){
       for(int i=n-1; i>=0; i--){
           cout << strpair[i].first << endl;
       }
    } else {
        for(int i=0; i<n; i++){
            cout << strpair[i].first << endl;
        }
    }
    
}