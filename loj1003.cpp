#include<bits/stdc++.h>
using namespace std;
map<string,vector<string> >pre;
map<string,int>freq;
map<string,int>::iterator it;
map<string,string>vis;

void toto(queue<string>q){
    string s = q.front();
    for(int i = 0; i < )
}

int main(){
    int tc, cs, m, i;
    string u, v;
    scanf("%d", &tc);
    for(cs = 1; cs <= tc; cs++){
        scanf("%d", &m);
        pre.clear();
        freq.clear();
        for(i = 1; i <= m; i++){
            scanf("%d %d", &u, &v);
            pre[u].push_back(v);
            freq[v]++;
        }
        queue<string>q;
        while(q.empty() == false)q.pop();
        for(it = freq.begin(); it != freq.end(); it++){
            if(it->second == 0)q.push(it->first);
        }
        topo(q);
    }
    return 0;
}
