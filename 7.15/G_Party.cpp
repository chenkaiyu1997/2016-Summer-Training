#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
using namespace std;
const int N=2005;
const int inf=1e9;

struct edge{
	int v,w,nxt;
}e[200000];
int b[N],en;
vector<int> e2[N];
int n,m;
int dis[N],w[N],p[N],col[N];
void addedge(int u,int v,int w) {
	e[en].v=v;
	e[en].w=w;
	e[en].nxt=b[u];
	b[u]=en++;

	e[en].v=u;
	e[en].w=0;
	e[en].nxt=b[v];
	b[v]=en++;
}
	
queue<int> q;
bool bfs(int s,int t){
	while(!q.empty())q.pop();
	ms(dis,-1);
	dis[s]=0;
	q.push(s);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for(int i=b[now];i!=-1;i=e[i].nxt)
			if(dis[e[i].v]==-1 && e[i].w>0){
				dis[e[i].v]=dis[now]+1;
				q.push(e[i].v);
			}
	}
	if(dis[t]==-1)return false;
	return true;
}

int dfs(int s,int lim,int t) {
	if(s==t)return lim;
	int flow=0,tmp=0;
	for(int i=b[s];i!=-1;i=e[i].nxt) 
		if(dis[e[i].v]==dis[s]+1 && e[i].w>0) {
			tmp=dfs(e[i].v,min(lim-flow,e[i].w),t);
			if(tmp>0) {
				e[i].w-=tmp;
				e[i^1].w+=tmp;
				flow+=tmp;
				if(flow==lim)break;
			}
			else dis[e[i].v]=-1;
		}
	return flow;
}

void bfs1(int s){
	while(!q.empty())q.pop();
	col[s]=0;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(vector<int>::iterator it=e2[now].begin();it!=e2[now].end();it++)
			if(col[*it]==-1){
				col[*it]=col[now]^1;
				q.push(*it);
			}
	}
}



int main()
{
	freopen("A.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF) {
		for(int i=0;i<n;i++)
			e2[i].clear();
		en=0;ms(b,-1);
		for(int i=0;i<n;i++){
			scanf("%d",&w[i]);
			addedge(i*2,i*2+1,w[i]);
		}
		int u,v;
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
			p[i]--;
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			u--;v--;
			e2[u].pb(v);
			e2[v].pb(u);
			addedge(u*2+1,v*2,inf);
			addedge(v*2+1,u*2,inf);
		}
		ms(col,-1);
		for(int i=0;i<n;i++)
			if(col[i]==-1)
				bfs1(i);


		for(int i=0;i<n;i++) {
			if(p[i]==2)continue;
			if(p[i]^col[i])addedge(n*2,i*2,inf);
			else addedge(i*2+1,n*2+1,inf);	
		}
		

		int flow=0;
		while(bfs(n*2,n*2+1))
			flow+=dfs(n*2,inf,n*2+1);
		printf("%d\n",flow);
	}
	return 0;
}
