#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char s[100] = "Today is a rainy season";
    // STRTOK accepts first parameter as character array and a deliminator as a second param
    char *ptr = strtok(s," ");
    cout << ptr << endl;

    while(ptr != NULL){
        ptr = strtok(NULL," ");
        cout << ptr << endl;
    }
}