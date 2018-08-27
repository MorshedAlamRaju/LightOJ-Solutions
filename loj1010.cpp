#include<bits/stdc++.h>
using namespace std;

#define valid(nx,ny) nx>=0 && nx<m && ny>=0 && ny<n

int fx[]={+2,+2,-2,-2,-1,+1,-1,+1};
int fy[]={+1,-1,+1,-1,-2,-2,+2,+2};

int arr[201][201];

int main(){
    int t, i, j, m, n,l, cnt, k;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        scanf("%d %d",&m, &n);
        int arr[m][n];
        memset(arr,-1,sizeof arr);
        for(j = 0, cnt = 0; j < m; ++j){
            for(k = 0; k < n; ++k){
                if(arr[j][k]==-1){
                    arr[j][k] = 1;
                    ++cnt;
                    for(l = 0; l < 8; ++l){
                        j = j + fx[l];
                        k = k + fy[l];
                        if(valid(j,k))arr[j][k] = 1;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}
