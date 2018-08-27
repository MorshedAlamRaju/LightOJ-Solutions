#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc, cs, n, m, i, cnt;
    long long int sum;
    scanf("%d",&tc);
    for(cs = 1; cs <= tc; cs++){
        scanf("%d %d",&n, &m);
        sum = (n*(n-1))/2;
        for(i = 1, cnt = 0; i <= n; i++){
            sum-=i;cnt++;
            if(cnt==m)i+=m,cnt=0;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
