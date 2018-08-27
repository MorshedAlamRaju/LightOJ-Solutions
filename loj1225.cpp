#include<bits/stdc++.h>
using namespace std;

string rev(string s){
    string t;
    for(int i=s.length()-1; i>=0;--i)t+=s[i];
    return t;
}

int main(){
    int t, i, n, j, d, dust;
    scanf("%d",&t);
    for(i = 1; i <= t; ++i){
        scanf("%d",&n);
        string s, t;
        stringstream ss;
        ss << n;
        ss >> s;
        t = rev(s);
        if(t==s)
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }
    return 0;
}

