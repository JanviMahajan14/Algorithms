// Given (x,y) coordinates of various cars. we are at origin. Sort the cars as per their
// distance from origin and also output their car names accordingly using class

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class car {
    public:
        string car_name;
        int x;
        int y;

    car(string name, int xcood, int ycood){
        car_name = name;
        x = xcood;
        y = ycood;
    }

    int distance(int x, int y){
        return x*x + y*y;
    }
};

bool compare(car obj1, car obj2){
    int d1 = obj1.distance(obj1.x,obj1.y);
    int d2 = obj2.distance(obj2.x,obj2.y);
    if(d1 == d2){
        return obj1.car_name < obj2.car_name;
    }
    return d1 < d2;
}

int main(){
    vector<car>v;
    string name;
    int n,x,y;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> name >> x >> y;
        car obj(name,x,y);
        v.push_back(obj);
    }
    sort(v.begin(),v.end(),compare);

    for(auto i:v){
        cout << i.car_name << " " << i.x << " " << i.y << endl;
    }
}