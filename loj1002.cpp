/*
#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>, pair<int,int> > m;
bool vis[105][105];

int main(){
    int x, y, z;
    for(int i = 1; i <= 10; i++){
        cin >> x >> y >> z;
        if(vis[x][y] || vis[y][x]){
            m[{x,y}].first = m[{y,x}].first = min(m[{y,x}].first,min(m[{x,y}].first,z));
            m[{x,y}].second = m[{y,x}].second = max(m[{y,x}].second,max(m[{x,y}].second,z));
        } else {
            vis[x][y] = vis[y][x] = true;
            m[{x,y}].first = m[{x,y}].second = m[{y,x}].first = m[{y,x}].second = z;
        }
    }
    for(auto a : m){
        cout << a.first.first << " " << a.first.second << " " << a.second.first << " " << a.second.second << endl;
    }
}
*/

#include<bits/stdc++.h>
using namespace std;

int tc, n, z, u, v, sum, dest, m;
int parent[505], cost[505][505], pi[505];
vector<int>g[505];
bool vis[505];

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

void init(int n){
    mst.clear();
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        g[i].clear();
        fill(cost[i], cost[i] + n, 50005);
    }
}


void MST(){
    sort(mst.begin(),mst.end());
    for(int i = 0; i < mst.size(); i++){
        edge e = mst[i];
        if(isUnited(e.u,e.v) ==  false ){
            Union(e.u,e.v);
            g[e.u].push_back(e.v);
            g[e.v].push_back(e.u);
        }
    }
}


void path(int t){
    if(pi[t] == t)return;
    sum = max(sum, cost[t][pi[t]] | cost[pi[t]][t]);
    path(pi[t]);
}

void BFS(int s, int t){
    queue<int>q;
    fill(vis, vis + 501, false);
    for(int i = 0; i <= n; i++)pi[i] = i;
    q.push(s);
    vis[s] = true;
    sum = 0;
    pi[s] = s;
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(int i = 0; i < g[s].size(); i++){
            int v = g[s][i];
            if(vis[v] == false){
                pi[v] = s;
                vis[v] = true;
                q.push(v);
            }
        }
        if(vis[t])break;
    }
    if(vis[t])path(t);
}

int main(){
//    freopen("in.txt", "r", stdin);
    scanf("%d", &tc);
    for(int cs = 1;cs <= tc;cs++){
        scanf("%d %d", &n, &m);
        init(n);
        for(int x = 1; x <= m; x++){
            scanf("%d %d %d", &u, &v, &z);
            mst.push_back(edge(u,v,z));
            cost[v][u] = cost[u][v] = min(cost[u][v],min(cost[v][u],z));
        }
        MST();
        scanf("%d",&dest);
        printf("Case %d:\n",cs);
        for(int i = 0; i < n; i++){
            BFS(i,dest);
            if(vis[dest])printf("%d\n",sum);
            else puts("Impossible");
        }
    }
    return 0;
}
