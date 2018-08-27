#include<bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2;
const double eps = 1e-9;


int main(){
    int t,n, i;
    double r, area, a;
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%lf %d",&r,&n);
        area = pi * r * r;
        area /= (double)n;
        area /= pi;
        area = sqrt(area);
        printf("Case %d: %.8lf\n",i,area+eps);
    }
    return 0;
}
