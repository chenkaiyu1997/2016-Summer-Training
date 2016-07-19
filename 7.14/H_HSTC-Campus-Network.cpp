#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fi first
#define se second
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=10005;
int n,m;
int listl[N],listr[N];
vector<int>e[N];
queue<int> q;

int bfs() {
	while(!q.empty()) q.pop();
	q.push(1);
	listr[listl[1]]=listr[1];
	listl[listr[1]]=listl[1];
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		int j=0,len=e[now].size();
		for(int i=listr[0];i<=n;i=listr[i]) {
			while(j<len && e[now][j]<i)j++;
			if(len==0 || e[now][j]!=i) {
				q.push(i);
				listr[listl[i]]=listr[i];
				listl[listr[i]]=listl[i];
			}
		}
	}
	int ans=0;
	for(int i=listr[0];i<=n;i=listr[i]) ans++;
	return n-ans-1;
}
			
			
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cc=0;
	while(scanf("%d%d",&n,&m),n!=0) {
		for(int i=1;i<=n;i++)
			e[i].clear();
		cc++;
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			sort(e[i].begin(),e[i].end());
		for(int i=0;i<=n+1;i++){
			listr[i]=i+1;
			listl[i]=i-1;
		}
		printf("Case %d: %d\n",cc,bfs());
	}

	return 0;
}
