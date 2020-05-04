#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int coins[] = {1,2,5,10,20,50,100,200,500,1000};
    int num;
    cin >> num;
    
    while(num > 0){
        auto it = lower_bound(coins, coins+10, num);
        int index = it - coins;
        if(coins[index] == num){
            cout << coins[index] << " ";
            num = num - coins[index];
        }
        else{
            cout << coins[index-1] << " ";
            num = num - coins[index-1];
        }
    }

}