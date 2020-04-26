// adhoc prac problem
#include <iostream>
using namespace std;

bool checkStrength(int s, int k){
    if(s < k){
        return false;
    }
    return true;
}

int main(){
    int m,n,k,s, cnt=0;
    cin >> m >> n >> k >> s;
    char a[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == '.'){
                s = s-2;
            }
            else if(a[i][j] == '*'){
                s = s+5;
            }
            else if(a[i][j] == '#'){
                if(!checkStrength(s, k)){
                    cnt = 1;
                    break;
                }
                break;
            }
            if(j < n-1){
                s--;
                if(!checkStrength(s, k)){
                    cnt =1;
                    break;
                }
            }
        }
        if(cnt == 1){
            cout << "No";
            break;
        }
    }

    if( s >= k && cnt == 0){
        cout << "Yes" << endl;
        cout << s;
    }
    else if( s < k && cnt == 0){
        cout << "No";
    }
}
