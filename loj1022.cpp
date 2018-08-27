#include<bits/stdc++.h>
using namespace std;
const double pi = 2*acos(0.0);
int main(){
    int t, i, n, j, d, dust;
    double a, r, b, area;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        scanf("%lf",&r);
        a = r+r;
        a*=a;
        b = pi*(r*r);
        area = a-b;
        printf("Case %d: %.2lf\n",i,area);
    }
    return 0;
}


