#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int d[21][21],vis[21][21];
int row,col;
char arr[21][21];
void bfs(int sx,int sy){
	memset(vis,0,sizeof vis);
	memset(d,0,sizeof d);
	vis[sx][sy]=1;
	d[sx][sy] = 0;
	queue<pii>q;
	q.push(pii(sx,sy));
	while(!q.empty())
	{
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k];
			if(tx>=0 and tx<row and ty>=0 and ty<col and arr[tx][ty]!='#' and arr[tx][ty]!='m' and vis[tx][ty]==0){
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1;
				q.push(pii(tx,ty));
			}
		}
	}
}

int main(){
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
    int n, i, j, x,t, y,k;
    cin >> t;
    //scanf("%d",&t);
    for(int cs = 1; cs <= t; cs++){
        memset(arr,'#',sizeof arr);
        vector<pii>v;
        cin >> row >> col;
        //scanf("%d %d",&row, &col);
        //getchar();
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                cin >> arr[i][j];
                //scanf("%c",&arr[i][j]);
                if(arr[i][j]=='h'){
                    x = i;y=j;
                }
                else if(arr[i][j]=='a'||arr[i][j]=='b'||arr[i][j]=='c')v.push_back(pii(i,j));
            }
        }
        bfs(x,y);
        int ans = 0;
        ans = max(ans,d[v[0].first][v[0].second]);
        ans = max(ans,d[v[1].first][v[1].second]);
        ans = max(ans,d[v[2].first][v[2].second]);
        printf("Case %d: %d\n",cs,ans);
    }
    return 0;
}

