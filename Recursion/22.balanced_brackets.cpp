#include<iostream>
using namespace std;

void generate_brackets(int n, char *output, int i, int o, int c){
    if(i==2*n){
        output[i] = '\0';
        cout << output << " ";
        return;
    }
    if(o < n){
        output[i] = '(';
        generate_brackets(n,output,i+1,o+1,c);
    }
    if(c < o){
        output[i] = ')';
        generate_brackets(n,output,i+1,o,c+1);
    }
}

int main(){
    int n;
    cin >> n;
   //C: Count of closing bracket; 
   //O: Count of opening bracket; 
    int c = 0, o = 0;
    char output[(2*n)+1];
    generate_brackets(n,output,0,o,c);
}