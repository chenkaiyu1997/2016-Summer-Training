#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;

int n1,n2,m;
bool rel[205][205];
bool vis[205];
int lnk[205];


bool f(int p) {
	for(int i=1;i<=n2;i++)
		if(!vis[i] && rel[p][i]) {
			vis[i]=true;
			if(lnk[i]==0 || f(lnk[i])){
				lnk[i]=p;
				return true;
			}
		}
	return false;
}



int main(){ 
	int cc=0;
	while(scanf("%d%d%d",&n1,&n2,&m),n1!=0) {
		cc++;
		ms(rel,1);
		ms(lnk,0);
		int u,v;
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&u,&v);
			rel[u][v]=false;
		}
		int ans=0;
		for(int i=1;i<=n1;i++){
			ms(vis,0);
			if(f(i))
				ans++;
		}
		printf("Case %d: %d\n",cc,n1+n2-ans);
	}
	return 0;
}
