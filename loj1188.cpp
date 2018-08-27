#include<bits/stdc++.h>
using namespace std;

#define N 100009
#define pvi pair<set<int>,int>
set<int>::iterator it;
set<int>z;
int a[N];
pvi tree[N*3];

pvi Combine(pvi a, pvi b){
    for(it = b.first.begin(); it != b.first.end(); it++)
        a.first.insert(*it);
        int mx = a.first.size();
    return make_pair(a.first,mx);
}

void build(int node, int s, int e){
    if(s == e){
        set<int>v;
        v.insert(a[s]);
        tree[node] = make_pair(v,v.size());
        return;
    }
    int mid = (s + e)/2;
    int left = node * 2;
    int right = left + 1;
    build(left,s,mid);
    build(right,mid+1,e);
    tree[node] = Combine(tree[left],tree[right]);
}

pvi query(int node, int s, int e, int l, int r){
    if(r < s || l > e)return make_pair(z,INT_MIN);
    if(l<=s&&r>=e)return tree[node];
    int mid = (s + e)/2;
    return Combine(query(node*2,s,mid,l,r),query(node*2+1,mid+1,e,l,r));
}

int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int i, n, q, l, r, tc, cs;
    scanf("%d", &tc);
    for(cs = 1; cs <= tc; cs++){
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; i++)
            scanf("%d", a + i);
        build(1,1,n);
        printf("Case %d:\n",cs);
        for(int i = 1; i <= q; i++){
            scanf("%d %d", &l, &r);
            pvi ans = query(1,1,n,l,r);
            cout << ans.second << endl;
        }
    }
    return 0;
}

