#include<iostream>
#include<set>
using namespace std;

void permuatations(char *s, int i, char *out, int j, set<string>&set_array){
    if(s[i]=='\0'){
        out[j]='\0';
        string t(out);
        set_array.insert(t);
        return;
    }

    for(int k=i; s[k]!='\0'; k++){
        out[j]=s[k];
        swap(s[k],s[i]);
        permuatations(s,i+1,out,j+1,set_array);
        swap(s[i],s[k]);
    }

}

int main(){
    char s[100];
    cin >> s;
    char out[100];
    set<string>set_array;
    permuatations(s,0,out,0,set_array);

    for(auto x:set_array){
        cout << x << " ";
    }
}