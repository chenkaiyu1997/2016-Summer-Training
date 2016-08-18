#include<bits/stdc++.h> 
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x) & (-(x)))
using namespace std;
const int N=6200;
const int M=40000;
const int inf=(1e9)+7;
struct edge{
	int v,w;
	int nxt;
}e[M];
int en;
int b[N];
int S,T;
int n;
int w[105][105];
void addedge(int u,int v,int w){
	e[en].v=v;
	e[en].w=w;
	e[en].nxt=b[u];
	b[u]=en++;

	e[en].v=u;
	e[en].w=0;
	e[en].nxt=b[v];
	b[v]=en++;
}

char s[120];
int pa[10],pb[10];
int dis[N];


queue<int> q;
bool bfs(){
	while(!q.empty())q.pop();
	ms(dis,-1);
	dis[S]=0;
	q.push(S);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=b[now];i!=-1;i=e[i].nxt)
			if(dis[e[i].v]==-1 && e[i].w>0){
				dis[e[i].v]=dis[now]+1;
				q.push(e[i].v);
			}
	}
	return dis[T]!=-1;
}

int dfs(int now,int lim){
	int flow=0,tmp=0;
	if(now==T)return lim;
	for(int i=b[now];i!=-1;i=e[i].nxt)
		if(dis[e[i].v]==dis[now]+1 && e[i].w>0){
			tmp=dfs(e[i].v,min(lim-flow,e[i].w));
			if(tmp>0){
				e[i].w-=tmp;
				e[i^1].w+=tmp;
				flow+=tmp;
				if(flow==lim)return lim;
			}
			else
				dis[e[i].v]=-1;
		}
	return flow;
}

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		en=0;
		ms(b,-1);
		scanf("%d",&n);
		scanf("%s",s+1);
		int sum=0;
		for(int i=0;i<10;i++)
			scanf("%d %d",&pa[i],&pb[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&w[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i>j){
					w[j][i]+=w[i][j];
					w[i][j]=0;
					sum+=w[j][i];
				}
		int part1=n*(n-1)/2;
		int part2=part1+n;
		int part3=part2+10;
		S=0;T=part3+1;
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				cnt++;
				addedge(S,cnt,w[i][j]);
				addedge(cnt,part1+i,inf);
				addedge(cnt,part1+j,inf);
			}
		for(int i=1;i<=n;i++){
			addedge(part1+i,T,pa[s[i]-'0']);
			addedge(part1+i,part2+s[i]-'0'+1,inf);
		}
		for(int i=0;i<10;i++)
			addedge(part2+i+1,T,pb[i]-pa[i]);
		int flow=0;
		while(bfs())
			flow+=dfs(S,inf);
		printf("Case #%d: %d\n",tt,sum-flow);
	}
	return 0;
}





