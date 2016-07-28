#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
const int N=100005;
int n,m;
int deg[N],fa[N],ind[N];
bool vis[N];
int route[N];
int routeto[N];
int cnt=0;
map<int,int> my;
struct edge{
	int v,nxt;
}e[N+20];


int en,b[N];
int findfa(int p) {
	if(fa[p]==p)
		return p;
	fa[p]=findfa(fa[p]);
	return fa[p];
}

void addedge(int u,int v){
	e[++en].v=v;
	e[en].nxt=b[u];
	b[u]=en;
}

bool dfs(int p,int step) {
	route[step]=p;
	vis[p]=true;
	if(step==cnt+1) {
		if(p!=1)printf("error!");
		return true;
	}
	for(int i=b[p];i;i=e[i].nxt) {
		if(e[i].v==0)continue;
		if(vis[fa[e[i].v]] && (!(step==cnt && fa[e[i].v]==1)) ) continue;
		routeto[step]=e[i].v;
		if(dfs(fa[e[i].v],step+1))return true;
	}
	vis[p]=false;
	return false;
}



queue<int> q;
bool liantong() {
	q.push(1);
	ms(vis,0);
	vis[1]=1;
	int cnt=1;
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for(int i=b[now];i;i=e[i].nxt){
			if(!vis[e[i].v]){
				vis[e[i].v]=true;
				cnt++;
				q.push(e[i].v);
			}
		}
	}
	if(cnt==n)return true;
	return false;
}

int main(){
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	scanf("%d%d",&n,&m);
	en=0;ms(b,0);
	ms(deg,0);ms(ind,0);
	int u,v;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		addedge(u,v);
		deg[u]++;ind[v]++;
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	if(!liantong()){
		printf("There is no route, Karl!\n");
		return 0;
	}
		
	for(int i=2;i<=n;i++) {
		if(deg[i]==1 && ind[i]==1)
			fa[i]=e[b[i]].v;
		else
			cnt++;
	}
	cnt++;
	for(int i=1;i<=n;i++) {
		fa[i]=findfa(i);
	}

	for(int v=1;v<=n;v++) {
		if(fa[v]!=v)continue;
		bool flag=false;
		for(int i=b[v];i;i=e[i].nxt)
			if(e[i].v!=fa[e[i].v]){
				flag=true;
				break;
			}
		if(!flag)continue;
		int cnt=0;
		for(int i=b[v];i;i=e[i].nxt){
			if(e[i].v==fa[e[i].v])
				e[i].v=0;
			else{
				cnt++;
				if(cnt==2){
					printf("There is no route, Karl!\n");
					return 0;
				}
			}
		}
	}

	ms(vis,0);
	if(dfs(1,1)){
		for(int i=1;i<=cnt;i++){
			printf("%d ",route[i]);
			int j=routeto[i];
			while(fa[j]!=j) {
				printf("%d ",j);
				j=e[b[j]].v;
			}
		}
		printf("1");
	}
	else
		printf("There is no route, Karl!\n");

	return 0;
}
