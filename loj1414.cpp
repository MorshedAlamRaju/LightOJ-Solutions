#include<bits/stdc++.h>
using namespace std;

int main(){
    int y, cnt = 0;
    for(y = 2000; y <= 2100; y+=4)
        if((y%4==0&&y%100!=0)||(y%400==0))++cnt;
    cout << cnt << endl;
    return 0;
}
