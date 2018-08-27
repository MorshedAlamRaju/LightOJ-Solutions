#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, i, x1, x2, y1, y2, m, p, q;
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        scanf("%d",&m);
        printf("Case %d:\n",i);
        for(int j = 1; j <= m; j++){
            scanf("%d %d",&p, &q);
            if((p > x1 && p < x2) && (q > y1 && q < y2))
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
