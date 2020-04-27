#include <iostream>
using namespace std;

int main(){
   int n,i=0;
   cin >> n;
   char a[100][100];

    // For input of the 'enter' key pressed
   cin.get();
    // Since cin can't take space as input so we need getline   
   while(n--){
       cin.getline(a[i],100);
       cout << a[i++] << endl;
   }
}
