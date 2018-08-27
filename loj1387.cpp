#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, i, j, k;
    long long money;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        money = 0;
        printf("Case %d:\n",i);
        scanf("%d",&n);
        for(j = 1; j <= n; ++j){
            string s;
            cin >> s;
            if(s=="donate"){
                scanf("%d",&k);
                money+=k;
            }
            else printf("%lld\n",money);
        }
    }
    return 0;
}
