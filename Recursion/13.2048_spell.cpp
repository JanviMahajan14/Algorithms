#include <iostream>
using namespace std;

void spell(int n, string a[] ){
    if(n==0){
        return;
    }
    spell(n/10,a);
    cout << a[n%10] << " ";
}

int main(){
    int n;
    cin >> n;
    string a[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    spell(n,a);

}