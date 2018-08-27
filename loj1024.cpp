#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define N 10299
int a[1009];
int f[N][150];
bool ara[N + 3];
vector<int>p;
set<int>s;
set<int>::iterator it;
int sz;

void prime(){
    for(int i = 2; i <= N; i += 2)ara[i] = true;
    int sq = int(sqrt(N));
    p.push_back(2);
    for(int i = 2; i <= sq; i += 2)
        if(!ara[i]){p.push_back(i);
            for(int j = i + i; j <= N; j+=i)ara[i] = true;
        }
    sz = p.size();
}


void divisor(int n){
    int m = n, cnt;
    int sq = int(sqrt(n));
    for(int i = 0; p[i] <= sq; i++){
        cnt = 0;
        if(n%p[i] == 0){
            cnt = 0;
            while(n%p[i] == 0){
                ++cnt;
                n/=p[i];
            }
        }
        if(cnt)
            s.insert(p[i]),
            f[m][p[i]] = cnt;
    }
    if(n > 1)f[m][n] = 1, s.insert(n);
}


void factor(){
    s.insert(1);
    f[1][1] = 1;
    for(int i = 2; i < 10000; i++){
        divisor(i);
    }
}

string multiply( string a, int b ) {
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}



void solve(int n){
    string s;
    for(it = s.begin(); it != s.end(); it++){
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx,f[a[i]][*it]);
        }

    }
}

int main(){
    prime();
    factor();
    for(int i = 1; i <= 10; i++){
        cout << "divisors for " << i << endl;
        for(it = s.begin(); it != s.end() && *it <= i; it++){
            cout << *it << " has " << f[i][*it] << " times in " << i << endl;
        }
        puts("");
    }
    int t, n, x;
    scanf("%d", &t);
    for(int cs = 1; cs <= t; cs++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", a + i);
        printf("Case %d: %s\n",cs,solve(n));
    }
    return 0;
}
