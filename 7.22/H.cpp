#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;
const int N=82;
const ll inf=1e17;
ll dis[N][N];
ll dis2[N][N];
int main() {
	freopen("A.in","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=(i==j)?0:inf;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		dis[u][v]=min(dis[u][v],(ll)w);
		dis[v][u]=dis[u][v];
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][k]<dis[i][j]-dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	ll nowd=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			nowd=max(nowd,dis[i][j]);
	ll ansd=inf,ansa=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			memcpy(dis2,dis,sizeof(dis));			
			dis2[i][j]=0;
			dis2[j][i]=0;
			ll newd=0,newa=inf;
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++){
					dis2[u][v]=min(dis2[u][v],dis2[u][i]+dis2[j][v]);
					dis2[u][v]=min(dis2[u][v],dis2[u][j]+dis2[i][v]);
				}
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
					newd=max(newd,dis2[u][v]);
			for(int u=1;u<=n;u++)
				for(int v=1;v<=n;v++)
					if(dis[u][v]>newd)
						newa=min(newa,newd-dis2[u][v]);
			if(ansd>newd || (ansd==newd && ansa<newa)){
				ansd=newd;
				ansa=newa;
			}
		}
	if(ansd==inf)
		printf("-1.00000 -1.00000\n");
	else if(ansa>1e16)
		printf("%.5lf -1.00000\n",(double)ansd);
	else
		printf("%.5lf %.5lf\n",(double)ansd,(double)ansa);
	return 0;
}
	





