#include<stdio.h>

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        (n>=10)?printf("10 %d\n",n - 10) : printf("%d 0\n",n);
    }
    return 0;
}
