#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, j, p;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        scanf("%d",&j);
        p = 0;
        while(j){
            if(j%2==1)p++;
            j/=2;
        }
        if(p%2==0)printf("Case %d: even\n",i);
        else printf("Case %d: odd\n",i);
    }
    return 0;
}
