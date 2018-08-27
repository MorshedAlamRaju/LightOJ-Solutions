#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define N 5000009

ll ans[N+3];
bool ara[N+3];
vector<int>p;

void prime(){
    ara[0]=ara[1]=true;
    p.push_back(2);
    for(int i = 4; i <= N; i+=2)ara[i]=true;
    for(int i = 3; i <= N; i+=2){
        if(ara[i]==false){
            p.push_back(i);
            ans[i] = i - 1;
            for(int j = i+i; j <= N; j+=i)ara[j]=true;
        }
    }
}

ll divisor(int n){
    if(!ara[n])return ans[n];
    double res = n;
    int i = 0, sz = sqrt(n);
    while(n > 1 && p[i] <= sz){
        if(n % p[i] == 0){
            res = res * (1 - ((double)1/(double)p[i]));
            while(n % p[i] == 0)n/=p[i];
        }
        i++;
    }
    if(n > 1)res = res * (1 - ((double)1/(double)n));
    return (ll)res * (ll)res;
}


void divisors(){
    ans[1] = 1;
    for(int i = 2; i <= 5000000; i++)
        ans[i] = ans[i-1] + divisor(i);
}


int main(){
    prime();
    divisors();
    int t, n, m, cs = 1;
    scanf("%d",&t);
    while(cs <= t){
        scanf("%d %d",&n, &m);
        printf("Case %d: %lld\n",cs++, ans[m] - ans[n-1]);
    }
    return 0;
}

