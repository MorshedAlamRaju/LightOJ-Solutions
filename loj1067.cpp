#include<bits/stdc++.h>
using namespace std;

int mod(int n, int k){
    long long ways = 1;
    int j = 2;
    for(int i = n;i>n-k;i--){
        ways = ways * i;
        if(ways/j && j <= k)ways/=j,j++;
        ways%= 1000003;
    }
    return ways;
}


int main(){
    int tc, n, k;
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++){
        scanf("%d%d",&n,&k);
        printf("Case %d: %d\n",cs,mod(n,k));
    }
    return 0;
}

