// Remove consective duplicate letters from the string

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char s[1000], a[1000];
    int j=0;
    cin >> s;
    for(int i=0; i < strlen(s); i++){
        if(s[i] != s[i+1]){
            a[j++] = s[i];
        }
    }
    cout << a;
}