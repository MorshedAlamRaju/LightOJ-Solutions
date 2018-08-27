#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, p, q, j;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        scanf("%d %d",&p, &q);
        j = 19;
        if(p==0){
            printf("Case %d: 0\n",i);
        }
        else if(p<=q){
            j = j + q*4;
            printf("Case %d: %d\n",i,j);
        }
        else{
            q = (p + (p-q))*4;
            j = j + q;
            printf("Case %d: %d\n",i,j);
        }
    }
    return 0;
}
