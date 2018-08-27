#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tc, cs, i, n, ans;
    scanf("%d",&tc);
    for(cs = 1; cs <= tc; cs++){
        scanf("%d",&n);
        int arr[n+1];ans=0;
        for(i = 0; i < n; i++)scanf("%d",&arr[i]);
        for(i = 1; i < n; i++)if(arr[i]>arr[i-1])++ans;
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}
