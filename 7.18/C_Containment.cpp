#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define fi first
using namespace std;
const int N=1005;
const int inf=1e9;
struct edge{
	int v,w,nxt;
}e[22005],backe[22005];
int en=0;
int b[N],backb[N],dis[N],n;
int fi[6]={1,0,0,-1,0,0},fj[6]={0,1,0,0,-1,0},fk[6]={0,0,1,0,0,-1};
int S=1000,T=1001;

void addedge(int u,int v,int w1,int w2){
	e[en].v=v;
	e[en].w=w1;
	e[en].nxt=b[u];
	b[u]=en++;

	e[en].v=u;
	e[en].w=w2;
	e[en].nxt=b[v];
	b[v]=en++;
}
queue<int> q;
bool bfs(){
	while(!q.empty())q.pop();
	q.push(S);
	ms(dis,-1);
	dis[S]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for(int i=b[now];i!=-1;i=e[i].nxt)
			if(dis[e[i].v]==-1 && e[i].w>0){
				dis[e[i].v]=dis[now]+1;
				q.push(e[i].v);
			}
	}
	if(dis[T]==-1)return false;
	return true;
}

int dfs(int now,int lim) {
	if(now==T)return lim;
	int flow=0,tmp;
	for(int i=b[now];i!=-1;i=e[i].nxt)
		if(e[i].w>0 && dis[e[i].v]==dis[now]+1){
			tmp=dfs(e[i].v,min(lim-flow,e[i].w));
			if(tmp>0) {
				e[i].w-=tmp;
				e[i^1].w+=tmp;
				flow+=tmp;
				if(flow==lim)
					break;
			}
			else
				dis[e[i].v]=-1;
		}
	return flow;
}

int main()
{
	freopen("A.in","r",stdin);
	int tc;
	scanf("%d",&tc);
	en=0;ms(b,-1);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++) {
				int num=i*100+j*10+k;
				int cnt=0;
				for(int d=0;d<6;d++) {
					int ti=i+fi[d],tj=j+fj[d],tk=k+fk[d];
					if(ti>=0 && tj>=0 && tk>=0 && ti<10 && tj<10 && tk<10){
						int num2=ti*100+tj*10+tk;
						if(num2>num)
							addedge(num,num2,1,1);
					}
					else
						cnt++;
				}
				if(cnt!=0)
					addedge(num,T,cnt,0);
			}
	int tmpen=en;
	memcpy(backb,b,sizeof(b));
	memcpy(backe,e,sizeof(e));

	while(tc--){
		en=tmpen;
		memcpy(b,backb,sizeof(b));
		memcpy(e,backe,sizeof(e));
		
		scanf("%d",&n);
		int x,y,z;
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			int num=x*100+y*10+z;
			addedge(S,num,inf,0);
		}
		int flow=0;
		while(bfs())
			flow+=dfs(S,inf);
		printf("%d\n",flow);
	}
	return 0;
}
