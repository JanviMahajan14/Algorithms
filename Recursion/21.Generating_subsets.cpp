#include<iostream>
using namespace std;

void generate_subsequences(char *input, int i, char *output, int j){
    if(input[i] == '\0'){
        output[j]='\0';
        cout << output << " ";
        return;
    }

    // Including the input character
    output[j] = input[i];
    generate_subsequences(input,i+1,output,j+1);

    // Excluding the input character
    output[j] = '\0';
    generate_subsequences(input,i+1,output,j);

}

int main(){
    char input[100];
    char output[100] = {'\0'};
    cin >> input;
    int i=0;
    int j=0;
    generate_subsequences(input,i,output,j);
}