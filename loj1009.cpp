#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

set<int>v,l;

int main(){
    int t, n, i, j, k;
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        v.clear();
        l.clear();
        scanf("%d",&n);
        for(int x = 1; x <= n; x++){
            scanf("%d %d",&j, &k);
            v.insert(j);
            l.insert(k);
        }
        int vsz = v.size();
        int lsz = l.size();
        int ans = (vsz > lsz)? vsz : lsz;
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
