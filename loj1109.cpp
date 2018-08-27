#include<bits/stdc++.h>
using namespace std;

#define N 1000
#define pi pair<int,int>
pi pp[N];
vector<int>p;
bool ara[N+1];

void prime(){
    ara[0]=ara[1]=true;
    p.push_back(2);
    for(int i = 4; i <= N; i+=2)ara[i]=true;
    for(int i = 3; i <= N; i+=2){
        if(ara[i]==false){
            p.push_back(i);
            for(int j = i+i; j <= N; j+=i)ara[j]=true;
        }
    }
}

int divisor(int n){
    map<int,int>m;
    int d = 1,i = 0;
    while(n>1){
        if(i>=p.size())break;
        if(n%p[i]==0){
            m[p[i]]++;
            n/=p[i];
        }
        else i++;
    }
    map<int,int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it){
        d = d * (it->second+1);
    }
    return d;
}

void divisors(){
    for(int i = 1; i <= N; i++){
        pp[i] = make_pair(i,divisor(i));
    }
}

bool cmp(pi a, pi b){
    if(a.second != b.second)return a.second < b.second;
    return a.first > b.first;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    prime();
    divisors();
    sort(pp,pp+N,cmp);
    int n, m;
    cin >> n;
    int cs = 1;
    while(n--){
        cin >> m;
        cout << "Case " << cs++ << ": " << pp[m].first << endl;
    }
    return 0;
}
