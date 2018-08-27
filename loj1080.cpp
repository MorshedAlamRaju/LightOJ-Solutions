#include<bits/stdc++.h>
using namespace std;
#define mx 100009
int arr[mx];
int tree[mx*3];

void init(int node, int b, int e){
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j){
    if(b>j||e<i)return 0;
    if(b>=i&&e<=j)return tree[node];
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e )/ 2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int value){
    if(e<i||b>i)return;
    if(b==e){
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);
    tree[node] = tree[left] + tree[right];
}

int main(){
    int n, t;
    scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++){
        string s;
        for(int i = 0; s[i]; i++)cin >> arr[i+1];
        init(1,1,n);
        cout << query(1,1,n,2,4) << endl;
        update(1,1,n,2,10);
        cout << query(1,1,n,2,4) << endl;
    }
    return 0;
}

