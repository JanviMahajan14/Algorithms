#include<iostream>
using namespace std;

void generate_sequences(char alpha[],char *s, char *o, int i, int j){
    if(s[i]=='\0'){
        o[j]='\0';
        cout << o << " ";
        return;
    }
    o[j]= alpha[(s[i]-'0')];
    generate_sequences(alpha,s,o,i+1,j+1);

    if(s[i+1]!='\0'){
        int index = (s[i]-'0')*10 + (s[i+1]-'0')*1;
        if(index <= 26){
            o[j]= alpha[index];
            generate_sequences(alpha,s,o,i+2,j+1);
        }
    }
}

int main(){
    char s[100];
    cin >> s;
    char o[100];
    char alpha[27]= {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    generate_sequences(alpha,s,o,0,0);
}