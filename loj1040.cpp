#include<bits/stdc++.h>
using namespace std;

int tc, n, z, mx;
int parent[55];

struct edge{
    int u, v, w;
    edge(){}
    edge(int a, int b, int c) : u(a), v(b), w(c){}
    bool operator<(const edge& p) const{
        return w < p.w;
    }
};
vector<edge> mst;


int Find_Parent(int u){
    return (parent[u] == u)? u : parent[u] = Find_Parent(parent[u]);
}

bool isUnited(int u, int v){
    u = Find_Parent(u);
    v = Find_Parent(v);
    return u == v;
}

void Union(int u, int v){
    u = Find_Parent(u);
    v = Find_Parent(v);
    parent[v] = u;
}

int MST(){
    for(int i = 0; i <= 51; i++)
        parent[i] = i;
    int sum = 0; mx = 1;
    sort(mst.begin(),mst.end());
    for(int i = 0; i < mst.size(); i++){
        edge e = mst[i];
        if(isUnited(e.u,e.v) ==  false ){
            Union(e.u,e.v);
            sum+=e.w;
            mx++;
        }
    }
    return sum;
}

int main(){
    scanf("%d", &tc);
    for(int cs = 1;cs <= tc;cs++){
        scanf("%d", &n);
        mst.clear();
        int tot, sum = 0;
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= n; y++){
                scanf("%d", &z);
                sum = sum + z;
                if(x == y || z == 0)continue;
                mst.push_back(edge(x,y,z));
            }
        }
        tot = MST();
        if(mx == n) printf("Case %d: %d\n",cs,sum - tot);
        else printf("Case %d: -1\n",cs);
    }
    return 0;
}
