#include<bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2;
const double eps = 1e-9;

double distance(double x1, double y1, double x2, double y2){
    double d = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    return d;
}

double angle(double a, double b, double c){
    double temp;
    temp = (a*a+b*b-c*c) / (2 * a * b);
    return acos(temp);
}


int main(){
    int t, i, x1, y1, x2, y2, x3, y3, q;
    double B, a, b, c, s, area, c_area, arc_area, red;
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d %d %d %d %d %d",&x1,&y1, &x2, &y2, &x3, &y3);
        a = distance(x1,y1,x2,y2);
        b = distance(x2,y2,x3,y3);
        c = distance(x3,y3,x1,y1);
        s = (a + b + c) / 2.0;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        B = angle(a,c,b);
        red = B * a; //length of arc
        c_area = pi * a * a;
        arc_area = (B * a * a) / 2.0;
        if(arc_area*2<c_area)
            printf("Case %d: %.8lf\n",i,red+eps);
        else {
            red = (2 * pi * a) - red;
            printf("Case %d: %.8lf\n",i,red+eps);
        }
    }
    return 0;
}
