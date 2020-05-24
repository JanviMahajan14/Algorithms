#include <iostream>
using namespace std;

void replace_pie(char *s, int i){
    // base case
    if(s[i]=='\0'){
        return;
    }
    else if(s[i]=='p' && s[i+1]=='i'){
        int j = i+2;

        while(s[j]!='\0'){
            j++;
        }

        // Start copying from null character. We need 4 characters for 3.14
        // got two from p and i and two more spaces are reqd
        while(j >= i+2){
            s[j+2] = s[j];
            j--;
        }

        s[i]='3';
        s[i+1]='.';
        s[i+2]='1';
        s[i+3]='4';

        replace_pie(s,i+4);
    }
    else{
        replace_pie(s,i+1);
    }
}

int main(){
    char s[100];
    cin >> s;
    replace_pie(s,0);
    cout << s;
}