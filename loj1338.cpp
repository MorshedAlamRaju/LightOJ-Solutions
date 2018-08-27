#include<bits/stdc++.h>
using namespace std;
map<char,int>m;

int main(){
    int tc, cs,cnt;
    string f,s;
    cin >> tc;
    getchar();
    for(cs = 1; cs <= tc; cs++){
        getline(cin,f);
        getline(cin,s);
        m.clear();cnt=0;
        for(int i = 0; f[i]; i++)f[i] = toupper(f[i]);
        for(int i = 0; s[i]; i++)s[i] = toupper(s[i]);
        for(int i = 0; f[i]; i++)if(isupper(f[i]))m[f[i]]++,cnt++;
        for(int i = 0; s[i]; i++)if(isupper(s[i])&&m[s[i]])m[s[i]]--,cnt--;
        if(!cnt)printf("Case %d: Yes\n",cs);
        else printf("Case %d: No\n",cs);
    }
    return 0;
}
