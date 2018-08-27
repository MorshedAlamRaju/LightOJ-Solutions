#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, m, x, t, cs,i;
    bool f;
    scanf("%lld",&t);
    for(cs = 1; cs <= t; cs++){
        scanf("%lld",&x);
        int y = (int)(sqrt(x)+1);f = true;
        for(i = 2; i <= y; i+=2)
            if((x%i==0)&&((x/i)%2==1)){printf("Case %lld: %lld %lld\n",cs,x/i,i);f=false;break;}
        if(f)printf("Case %lld: Impossible\n",cs);
    }
    return 0;
}
