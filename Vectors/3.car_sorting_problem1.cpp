// Given (x,y) coordinates of various cars. we are at origin. Sort the cars as per their
// distance from origin

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b){
    int d1 = (a.first * a.first) +( a.second * a.second);
    int d2 = (b.first * b.first) +( b.second * b.second);

    // if both the distances are same return one with smaller x-coorinate
    if(d1 = d2){
        return a.first < b.first;
    }
    return d1 < d2;
}

int main(){
    // Vector of pairs
    vector<pair<int,int>>cab;

    int n,x,y;
    cin >> n;
    cab.reserve(n);
    for(int i=0; i<n; i++){
        cin >> x;
        cin >> y;
        cab.push_back(make_pair(x,y));
    }

    sort(cab.begin(), cab.end(), compare);

    for(auto it:cab){
        cout << "Car is " << it.first << " " << it.second << endl;
    }
}