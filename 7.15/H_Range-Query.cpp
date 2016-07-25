#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define lb(x) ((x) & (-x))
using namespace std;
const int N=55;


struct req{
	int a,b,c;
}rmin[N],rmax[N];
int ans[N];
bool lchosen[N],rchosen[N];
int lnk[N];
bool G[N][N],vis[N];
int n,m1,m2;
bool check(int p,int nu) {
	for(int i=1;i<=m1;i++){
		if(rmin[i].a<=p && rmin[i].b>=p){
			if(nu<rmin[i].c)
				return false;
		}
		else
			if(nu==rmin[i].c)return false;
	}
	for(int i=1;i<=m2;i++){
		if(rmax[i].a<=p && rmax[i].b>=p){
			if(nu>rmax[i].c)
				return false;
		}
		else
			if(nu==rmax[i].c)return false;
	}
	return true;
}


bool xf(int v) {
	for(int i=1;i<=n;i++)
		if(!vis[i] && !rchosen[i] && G[v][i]){
			vis[i]=true;
			if(lnk[i]==0 || xf(lnk[i])){
				lnk[i]=v;
				return true;
			}
		}
	return false;
}
int pipei(int st){
	int tans=0;
	ms(lnk,0);
	for(int i=st+1;i<=n;i++) {
		ms(vis,0);
		if(xf(i))
			tans++;
	}
	return tans;
}
bool dfs(int i){
	if(i==n+1)return true;
	lchosen[i]=1;
	for(int j=1;j<=n;j++){
		if(rchosen[j] || (!G[i][j]))continue;
		rchosen[j]=true;
		if(pipei(i)==n-i){
			ans[i]=j;
			if(dfs(i+1))return true;
		}
		rchosen[j]=false;
	}
	return false;
}
	
int main()
{
	freopen("A.in","r",stdin);
	while(scanf("%d%d%d",&n,&m1,&m2)!=EOF) {
		for(int i=1;i<=m1;i++)
			scanf("%d%d%d",&rmin[i].a,&rmin[i].b,&rmin[i].c);
		for(int i=1;i<=m2;i++)
			scanf("%d%d%d",&rmax[i].a,&rmax[i].b,&rmax[i].c);

		ms(G,0);
		ms(lchosen,0);ms(rchosen,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(check(i,j))
					G[i][j]=1;
		if(!dfs(1))printf("-1");
		else {
			for(int i=1;i<=n;i++)
				printf("%d ",ans[i]);
		}
		printf("\n");
	}		
	return 0;
}
