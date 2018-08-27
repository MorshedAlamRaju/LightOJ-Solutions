#include<bits/stdc++.h>
using namespace std;
vector<long long>v,cc;

void divisor(long long n){
    long long i, j;
    for(i=1;i*i<=n;++i){
        if(n%i==0){v.push_back(i);
        if(i*i!=n)v.push_back(n/i);}
    }
    sort(v.begin(),v.end());
}

int main(){
    int i, j, k;
    long long c, g, q, r,x;
    scanf("%d",&k);
    for(i = 1; i <= k; ++i){
        scanf("%lld %lld",&c, &r);
        if(c==r){
            printf("Case #%d: 0\n",i);
            continue;
        }
        c-=r;
        divisor(c);
        for(q=0; q<v.size();++q){
            if(v[q]>r){x=v[q];cc.push_back(x);}
        }
        printf("Case %d:",i);
        for(j=0;j<cc.size();++j)
            printf(" %lld",cc[j]);
        if(cc.size()==0)printf(" impossible");
        printf("\n");
        v.clear();
        cc.clear();
    }
    return 0;
}

