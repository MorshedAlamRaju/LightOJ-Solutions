#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, a, b,c, j;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        scanf("%d %d %d",&a, &b, &c);
        int asqure = a*a;
        int bsqure =b*b;
        int csqure =c*c;
        if((asqure+bsqure==csqure)||(bsqure+csqure==asqure)||(csqure+asqure==bsqure))
        printf("Case %d: yes\n",i);
        else printf("Case %d: no\n",i);
    }
    return 0;
}
