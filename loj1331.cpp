#include<bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2;
const double eps = 1e-9;

double angle(double a, double b, double c){
    double temp;
    temp = (a*a+b*b-c*c) / (2 * a * b);
    return acos(temp);
}

double tored(double t, double r){
    double red;
    red = (t * r * r) / 2.0;
    return red;
}

int main(){
    int t, i, j;
    double s, area, p, q, r, a, b, c, A, B, C;
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%lf %lf %lf",&p, &q, &r);
        a = p + q;
        b = q + r;
        c = r + p;

        s = (a + b + c) / 2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));

        A = angle(b,c,a);
        B = angle(a,c,b);
        C = angle(a,b,c);

        area = area - (tored(A,r) + tored(B,p) + tored(C,q));
        printf("Case %d: %.10lf\n",i,area + eps);
    }
    return 0;
}
