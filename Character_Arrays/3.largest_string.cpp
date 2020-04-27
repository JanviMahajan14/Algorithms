// given a array of strings find out the string of maximum length
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    char s[1000],a[1000];
    int current_length = 0, max_length = 0;
    cin.get();
    
    for(int i=0; i<n; i++){
        cin.getline(s, 1000);
        current_length = strlen(s);
        if(max_length < current_length){
            max_length = current_length;
            strcpy(a,s);
        }
    }
    cout << a << " " << max_length;
}