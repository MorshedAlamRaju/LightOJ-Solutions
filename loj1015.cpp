#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, n, j, d, dust;
    cin >> t;
    for(i = 1; i <= t; ++i){
        cin >> n;
        for(j = 1, dust = 0; j <= n; ++j){
            cin >> d;
            if(d>0)dust+=d;
        }
        cout << "Case " << i << ": " << dust << endl;
    }
    return 0;
}
