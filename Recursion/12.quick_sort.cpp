#include <iostream>
using namespace std;

int find_pivot(int *a, int s, int e){
    int i=s-1;
    for(int j=s; j<e; j++){
        if(a[j] < a[e]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[e],a[i+1]);
    return i+1;
}

void quick_sort(int *a, int s, int e){
    if(s >= e){
        return;
    }
    int pivot = find_pivot(a,s,e);
    quick_sort(a,s,pivot-1);
    quick_sort(a,pivot+1,e);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    quick_sort(a,0,n-1);

    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}