#include<bits/stdc++.h>
using namespace std;
int a[100009];

int main(){
    int t, n, i, cnt, ans, j, d, mn, mx;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++){
        scanf("%d %d",&n, &d);
        for(i = 0; i < n; i++)scanf("%d",&a[i]);
        i = 0;ans = 0;
        while(i < n){
            j = i;mn = 999999999;mx=-1;
            while(j<i+d&&j<n-1){
                if(a[j]>mx) mx = a[j];
                if(a[j]<mn) mn = a[j];
                ++j;
            }
            ++i;
            if(ans<(mx-mn))ans = (mx-mn);
        }
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
