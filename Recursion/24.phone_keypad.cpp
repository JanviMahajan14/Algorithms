#include<iostream>
using namespace std;

void form_permuatations(string arr[], char *in, char *out, int i, int j){

    if(in[i]=='\0'){
        out[j]='\0';
        cout << out << endl;
        return;
    }

    while((in[i]-'0') <= 1){
        i++;
    }

    int cases = arr[(in[i]-'0')].length();
    for(int k=0; k<cases; k++){
        out[j] = arr[(in[i]-'0')][k];
        form_permuatations(arr,in,out,i+1,j+1);
    }
}

int main(){
    string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    char in[10];
    cin >> in; //say 234
    char out[16];
    form_permuatations(arr,in,out,0,0);
}