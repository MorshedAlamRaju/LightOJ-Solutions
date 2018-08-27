#include<bits/stdc++.h>
using namespace std;

int tc, n, m, r, sum, cs = 1, mx;
string s, t;
map<string,int> cities;
int parent[105], sz[105];

struct edge{
    int u, v, w;
    bool operator<(const edge& p) const{
        return w < p.w;
    }
};

vector<edge>pq;

int Find_Parent(int u){
        return (parent[u] == u)? u : parent[u] = Find_Parent(parent[u]);
}

void Union(int u, int v){
        u = Find_Parent(u);
        v = Find_Parent(v);
        if(u < v)swap(u,v);
        parent[v] = u;
        sz[u] += sz[v];
        mx = max(mx, sz[u]);
}

bool isUnited(int u, int v){
    u = Find_Parent(u);
    v = Find_Parent(v);
    return u == v;
}


void init(){
        cities.clear();
        pq.clear();
        m = sum = 0;
        for(int i = 1; i <= 101; i++){
            parent[i] = i;
            sz[i] = 1;
        }
}

void MST(){
        sort(pq.begin(),pq.end());
        for(int i = 0; i < pq.size(); i++){
            edge e = pq[i];
            int x = e.u;
            int y = e.v;
            int w = e.w;
            if(isUnited(x,y) ==  false ){
                Union(x,y);
                sum+=w;
                m--;
//                cout << x << " " << y << " " << w << "\n";
                if(m <= 1)break;
            }
        }
}

void Input(){
        scanf("%d", &n);
        getchar();
        for(int i = 1; i <= n; i++){
            cin >> s >> t >> r;
            if(!cities[s])cities[s] = ++m;
            if(!cities[t])cities[t] = ++m;
            edge e;
            e.u = cities[s];
            e.v = cities[t];
            e.w = r;
            pq.push_back(e);
        }
}

void Output(){
        if(m <= 1) printf("Case %d: %d\n",cs++,sum);
        else printf("Case %d: Impossible\n",cs++);
}

int main(){
//    freopen("in.txt", "r", stdin);
    scanf("%d", &tc);
    for(;cs <= tc;){
        init();
        Input();
        MST();
        Output();
    }
    return 0;
}
