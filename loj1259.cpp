#include<iostream>
#include<stdio.h>
#include<vector>
#define Max 10000000
bool ara[Max+3];
using namespace std;
vector<int>p;
int sz;

void sieve()
{
    int i, j;
    p.push_back(2);
    for(i=4; i<Max; i+=2)ara[i]=true;
    for(i=3; i <= Max; i+=2){
        if(!ara[i]){
            p.push_back(i);
            for(j=i+i; j<=Max; j+=i)ara[j]=true;
        }
    }
    sz = p.size();
}


int ways(int n){
    int i = 0, j = sz - 1, ans = 0;
    while(p[j] >= n)--j;
    while(i<=j){
        if(p[i] + p[j] == n)++ans;
//        i++,j--;
        if(p[i] + p[j] > n)--j;
        else if(p[i] + p[j] < n)++i;
    }
    return ans;
}

int main()
{
    sieve();
    int tc, n;
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++){
        scanf("%d", &n);
        printf("Case %d: %d\n",cs,ways(n));
    }
}

