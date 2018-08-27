#include<bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
int i, j, k, l;
char a, b, c;
vector<int>decimal,d;

int stoint(string str){
    int temp = 0,v=1;
    int len = str.size();
    for(int i = len -1; i >= 0; i--){
        if(str[i]=='1')temp+=v;
        v*=2;
    }
    return temp;
}

bool same(string s){
    string str;
    for(int i =0; s[i]; i++){
        if(s[i]=='.')d.pb(stoint(str)), str = "";
        else str+=s[i];
    }
    d.pb(stoint(str));
    for(int i = 0; i < 4; i++)
        if(decimal[i]!=d[i])return false;
    return true;
}


int main(){
    int tc;
    cin >> tc;
    for(int cs = 1; cs <= tc; cs++){
        string bin;
        decimal.clear();d.clear();
        scanf("%d%c%d%c%d%c%d",&i,&a,&j,&b,&k,&c,&l);
        decimal.pb(i);decimal.pb(j);decimal.pb(k);decimal.pb(l);
        cin >> bin;
        if(same(bin))printf("Case %d: Yes\n",cs);
        else printf("Case %d: No\n",cs);
    }
    return 0;
}
