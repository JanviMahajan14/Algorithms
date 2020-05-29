#include<iostream>
using namespace std;

void permuatations(char *s, int i, char *out, int j){
    if(s[i]=='\0'){
        out[j]='\0';
        cout << out << " ";
        return;
    }

    for(int k=i; s[k]!='\0'; k++){
        out[j]=s[k];
        swap(s[k],s[i]);
        permuatations(s,i+1,out,j+1);
        swap(s[i],s[k]);
    }

}

int main(){
    char s[100];
    cin >> s;
    char out[100];
    permuatations(s,0,out,0);
}