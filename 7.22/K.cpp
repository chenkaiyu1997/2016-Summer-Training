#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=305;
const int inf=10000;
int dp[N][N][2];
int a[N];

int dfs(int l,int r,int u) {
	if(dp[l][r][u]!=-1) {
		return dp[l][r][u];
	}
	if(l==r) {
		if(u==0)
			return dp[l][r][u]=1;
		if(a[l-1]==a[l])return dp[l][r][u]=0;
		return dp[l][r][u]=inf;
	}
	if(u==0) 
		return dp[l][r][u]=min(dfs(l+1,r,0),dfs(l+1,r,1))+1;
	int tmp=inf;
	if(a[l-1]==a[r])
		tmp=min(dfs(l,r-1,0),dfs(l,r-1,1));
	for(int i=l;i<r;i++)
		tmp=min(tmp,dfs(l,i,1)+min(dfs(i+1,r,1),dfs(i+1,r,0)));
	return dp[l][r][u]=tmp;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int nn,m;
	scanf("%d%d",&nn,&m);
	int n=0,v;
	a[0]=0;
	for(int i=1;i<=nn;i++){
		scanf("%d",&v);
		if(v!=a[n])a[++n]=v;
	}
	ms(dp,-1);
	printf("%d\n",dfs(1,n,0)-1);
	return 0;
}
