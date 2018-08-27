#include<stdio.h>
inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;"
        :"=r"(count)
        :"r"(x)
        :
    );
    return count;
}

char bits[35];

int main(){
    int t, n, i = 1, j;
    scanf("%d",&t);
    while(i<=t){
        scanf("%d",&n);
        j = 0;

        printf("Case %d: %d\n",i++,n);
    }
    return 0;
}
