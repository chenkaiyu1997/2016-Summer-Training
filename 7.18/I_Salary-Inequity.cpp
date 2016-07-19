#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define fi first
using namespace std;
const int N1=1000005;
const int N2=10005;
const int inf=999999999;
int n,m;
int fa[N1];
int p[N1];
int samin[N2],samax[N2];
int qt[N2],q1[N2],q2[N2];
bool inp[N1];
struct edge{
	int v,nxt;
}e1[N1];
int b[N1];
int en,st;
int hao[N1],sa[N1];
int fa2[N2];
void addedge(int u,int v){
	e1[++en].v=v;
	e1[en].nxt=b[u];
	b[u]=en;
}
queue<int> q;
vector<int> e[N2];


int findfa(int tmp){
	if(fa[tmp]==tmp)return tmp;
	fa[tmp]=findfa(fa[tmp]);
	return fa[tmp];
}
void bfs() {
	while(!q.empty())q.pop();
	q.push(1);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		if(fa[now]!=now){
			int rfa=findfa(now);
			rfa=hao[rfa];
			samin[rfa]=min(samin[rfa],sa[now]);
			samax[rfa]=max(samax[rfa],sa[now]);
		}
		else if(now!=1)
			fa2[hao[now]]=hao[findfa(p[now])];
		for(int i=b[now];i;i=e1[i].nxt) {
			q.push(e1[i].v);
		}
	}
}


void add(int u,int num) {
	while(!q.empty())q.pop();
	q.push(u);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		samin[now]+=num;
		samax[now]+=num;
		for(vector<int>::iterator it=e[now].begin();it!=e[now].end();it++)
			q.push(*it);
	}
}

int query(int u) {
	while(!q.empty())q.pop();
	q.push(u);
	int ansmin=inf,ansmax=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		ansmin=min(ansmin,samin[now]);
		ansmax=max(ansmax,samax[now]);
		for(vector<int>::iterator it=e[now].begin();it!=e[now].end();it++)
			q.push(*it);
	}
	return ansmax-ansmin;
}

int main()
{

	int tc;
	scanf("%d\n",&tc);
	while(tc--){
		ms(b,0);
		en=0;
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			scanf("%d",&p[i]);
			addedge(p[i],i);
			fa[i]=p[i];
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&sa[i]);
		ms(inp,0);
		fa[1]=1;
		st=0;
		hao[++st]=1;
		samin[1]=samax[1]=sa[1];
		int q;
		scanf("%d",&q);
		char s[10];
		for(int i=1;i<=q;i++){
			scanf("%s",s);
			if(s[0]=='R'){
				qt[i]=0;
				scanf("%d%d",&q1[i],&q2[i]);
				if(fa[q1[i]]!=q1[i]){
					hao[q1[i]]=++st;
					fa[q1[i]]=q1[i];
					samin[st]=sa[q1[i]];
					samax[st]=sa[q1[i]];
				}
			}
			else if(s[0]=='Q'){
				qt[i]=1;
				scanf("%d",&q1[i]);
				if(fa[q1[i]]!=q1[i])
				{
					hao[q1[i]]=++st;
					fa[q1[i]]=q1[i];
					samin[st]=sa[q1[i]];
					samax[st]=sa[q1[i]];
				}
			}
			else printf("inputerror!");
		}
		bfs();
		for(int i=1;i<=st;i++)
			e[i].clear();
		for(int i=1;i<=st;i++)
			e[fa2[i]].push_back(i);


		for(int i=1;i<=q;i++) 
			if(qt[i]==0) 
				add(hao[q1[i]],q2[i]);
			else {
				printf("%d",query(hao[q1[i]]));
				if(!(i==q && tc==0))printf("\n");
			}
	}

	return 0;
}
