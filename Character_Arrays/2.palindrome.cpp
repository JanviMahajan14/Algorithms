#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(char a[]){
    int i = 0, j = strlen(a)-1;
    while(j >= i){
        if(a[i] != a[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;

}

// Program to check if a given string is a palindrome or not
int main(){
    char a[1000];
    cin >> a;
    cout << checkPalindrome(a);
}