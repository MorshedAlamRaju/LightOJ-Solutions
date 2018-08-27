#include<bits/stdc++.h>
using namespace std;

int tc, n, x, y, z;
int parent[105], sz[105];
map<pair<int,int>, pair<int,int> > m;
map<pair<int,int>, pair<int,int> >::iterator it;
bool vis[105][105];

struct edge{
    int u, v, w;
    bool operator<(const edge& p) const{
        return w < p.w;
    }
};
vector<edge> mst, mst2;


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
    if(u < v)swap(u,v);
    parent[v] = u;
    sz[u] += sz[v];
}

void init(){
    for(int i = 0; i <= 101; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int MST(){
    init();
    //for(int i = 0; i <= n; i++)printf("Parent of %d = %d\n",i,parent[i]);
    int sum = 0, cnt = n;
    sort(mst.begin(),mst.end());
    for(int i = 0; i < mst.size() && cnt; i++){
        edge e = mst[i];
        if(isUnited(e.u,e.v) ==  false ){
            Union(e.u,e.v);
            sum+=e.w;
            cnt--;
        }
//         else {
//            printf("Parent of %d = %d\n",e.u,Find_Parent(e.u));
//            printf("Parent of %d = %d\n",e.v,Find_Parent(e.v));
//        }
    }
//    cout << "mst = " << sum << endl;
    return sum;
}

int MST2(){
    init();
    int sum = 0, cnt = n;
    sort(mst2.begin(),mst2.end());
    for(int i = mst2.size() - 1; i >= 0 && cnt; i--){
        edge e = mst2[i];
        if(isUnited(e.u,e.v) ==  false ){
            Union(e.u,e.v);
            sum+=e.w;
            cnt--;
        }
    }
  //  cout << "mst2 = " << sum << endl;
    return sum;
}

int main(){
//    freopen("in.txt", "r", stdin);
    scanf("%d", &tc);
    for(int cs = 1;cs <= tc;cs++){
        scanf("%d", &n);
        for(int i = 0; i < 102; i++)
            fill(vis[i], vis[i] + 101, false);
        m.clear();
        while(~scanf("%d %d %d", &x, &y, &z)){
            if(x + y + z == 0)break;
            if(x > y)swap(x,y);
            if(vis[x][y]){
                m[{x,y}].first = min(m[{x,y}].first,z);
                m[{x,y}].second = max(m[{x,y}].second,z);
            } else {
                vis[x][y] = true;
                m[{x,y}].first = m[{x,y}].second = z;
            }
        }
        mst.clear();
        mst2.clear();
        for(it = m.begin(); it != m.end(); it++){
            edge x;
            x.u = it->first.first;
            x.v = it->first.second;
            x.w = it->second.first;
            mst.push_back(x);
            x.w = it->second.second;
            mst2.push_back(x);
        }
//        printf("MST Contains : ");
//        for(auto o : mst)cout << o.w << " ";
//        printf("\nMST2 Contains :");
//        for(auto o : mst2)cout << o.w << " ";
//        puts("");
        long long tot = 0;
        tot+=MST();
        tot+=MST2();
    //    cout << tot << endl;
        if(tot % 2 == 0) printf("Case %d: %d\n",cs,tot/2);
        else printf("Case %d: %d/2\n",cs,tot);
    }
    return 0;
}



/*
            if(vis[x][y] || vis[y][x]){
                m[{x,y}].first = m[{y,x}].first = min(m[{y,x}].first,min(m[{x,y}].first,z));
                m[{x,y}].second = m[{y,x}].second = max(m[{y,x}].second,max(m[{x,y}].second,z));
            } else {
                vis[x][y] = vis[y][x] = true;
                m[{x,y}].first = m[{x,y}].second = m[{y,x}].first = m[{y,x}].second = z;
            }

*/
