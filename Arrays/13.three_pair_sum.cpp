#include<iostream>
#include <algorithm>
using namespace std;
int main() {
	int n,j,k;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
    sort(a,a+n);
	int target,t;
	cin >> target;

	for(int i=0; i<n; i++){
		j = i+1;
		k = n-1;
		t = target - a[i];
		while(j < k){
			if(a[j]+a[k] == t){
				cout << a[i] << ", " << a[j] << " and " << a[k] << endl;
                j++;
                k--;
			}
            else if(a[j]+a[k] < t){
                j++;
            }
			else{
                k--;
            }
		}
	}
	return 0;
}