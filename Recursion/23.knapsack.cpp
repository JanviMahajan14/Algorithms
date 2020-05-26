// given an array of prices and weights find the max profit earned by the thief by putting the items in a given weight of knapsack
#include<iostream>
using namespace std;

int knapsack_profit(int n, int capacity, int weight[], int prices[]){
    if(n==0 || capacity<=0){
        return 0;
    }
    int include = prices[n-1]+knapsack_profit(n-1,capacity-weight[n-1],weight,prices);
    int exclude = knapsack_profit(n-1,capacity,weight,prices);
    return max(include,exclude);
}

int main(){
    int n = 4;
    int capacity = 6;
    int weights[10]={1,2,3,5};
    int prices[10]={40,20,35,100};
    cout << knapsack_profit(n,capacity,weights,prices);
}