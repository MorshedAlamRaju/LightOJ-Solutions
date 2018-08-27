#include<bits/stdc++.h>
using namespace std;
char s[1000];

bool mod(int n){
    long long sum = 0;
    for(int i = 0; s[i]; i++){
        if(!isdigit(s[i]))continue;
        sum = sum * 10 + (s[i] - 48);
        sum = sum % n;
    }
    return sum == 0;
}

int main(){
    int tc, x;
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++){
        scanf("%s%d",s,&x);
        printf("Case %d: %s\n",cs,mod(x)?"divisible":"not divisible");
    }
    return 0;
}
