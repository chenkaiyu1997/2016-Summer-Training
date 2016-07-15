#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=100005;

struct edge {
	int v,nxt;
}e[400005];
int en,n,m,b[N],leave;
int low[N],d[N],dirp[N];
int stk[N],bel[N],fa[N];

void addedge(int u,int v) {
	e[++en].v=v;
	e[en].nxt=b[u];
	b[u]=en;
}
void dfs(int u,int ffa){
	d[u]=d[ffa]+1;
	low[u]=d[u];
	fa[u]=(ffa==0?1:ffa);
	stk[++stk[0]]=u;
	for(int i=b[u];i!=0;i=e[i].nxt) {
		if(!d[e[i].v]) {
			dfs(e[i].v,u);
			low[u]=min(low[u],low[e[i].v]);
		}
		else if(e[i].v==ffa)
			dirp[u]++;
		else
			low[u]=min(low[u],d[e[i].v]);
	}
	if(d[u] == low[u] && dirp[u]<=1){
		while(stk[stk[0]]!=u) {
			bel[stk[stk[0]]]=u;
			stk[0]--;
		}
		stk[0]--;
	}
}
int findbel(int p) {
	if(bel[p]==p)
		return p;
	bel[p]=findbel(bel[p]);
	return bel[p];
}

int main(){ 

	int cc=0;
	while(scanf("%d%d",&n,&m),n!=0) {
		cc++;
		en=0;leave=0;
		ms(e,0);ms(b,0);
		int u,v;
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for(int i=1;i<=n;i++)
			bel[i]=i;
		ms(d,0);ms(low,0);
		ms(dirp,0);
		ms(stk,0);
		dfs(1,0);
		int bri=0;
		for(int i=1;i<=n;i++)
			if(bel[i]==i && dirp[i]==1)
				bri++;
		//printf("nowbri=%d",bri);
		int qsum=0;
		scanf("%d",&qsum);
		printf("Case %d:\n",cc);
		for(int i=1;i<=qsum;i++) {
			scanf("%d%d",&u,&v);
			u=findbel(u);v=findbel(v);
			int realbel;
			int tu=u,tv=v;
			while(u!=v){
				if(d[u]>d[v]){
					u=findbel(fa[u]);
					bri--;
				}
				else{
					v=findbel(fa[v]);
					bri--;
				}
			}
			realbel=u;
			
			u=tu;v=tv;
			while(u!=v){
				if(d[u]>d[v]){
					bel[u]=realbel;
					u=findbel(fa[u]);
				}
				else{
					bel[v]=realbel;
					v=findbel(fa[v]);
				}
			}
			printf("%d\n",bri);
		}
		printf("\n");
	}
	return 0;
}
