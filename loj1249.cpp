#include<bits/stdc++.h>
using namespace std;
map<int,string>mapa;
vector<int>vols;

int main(){
    int stus,tc, cs, i, v, h, l, w,sz;
    string s;bool f;
    cin >> tc;
    for(cs = 1; cs <= tc; cs++){
        cin >> stus;
        mapa.clear();vols.clear();f = true;
        for(i = 1; i <= stus; i++){
            cin >> s >> h >> l >> w;
            v = h*l*w;
            if(f)sz = v, f = false,vols.push_back(v);
            if(v!=sz)vols.push_back(v);
            mapa[v] = s;
        }
        if(vols.size()==1)printf("Case %d: no thief\n",cs);
        else {
            int m = INT_MAX, n = -1;
            for(int i = 0; i < vols.size(); i++)
                m = min(m,vols[i]), n = max(vols[i],n);
             cout << "Case " << cs << ": " << mapa[n] << " took chocolate from " << mapa[m] << endl;
        }
    }
    return 0;
}
