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
const int N=200005;
int n,m,a,b;
int listl[N],listr[N],dis[N];
vector<int>e[N];
queue<int> q;


int bfs() {
	for(int i=0;i<=n+1;i++){
		listr[i]=i+1;
		listl[i]=i-1;
	}
	ms(dis,0);
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
				dis[i]=dis[now]+1;
				q.push(i);
				listr[listl[i]]=listr[i];
				listl[listr[i]]=listl[i];
			}
		}
	}
	return dis[n];
}

int bfs2() {
	ms(dis,0);
	while(!q.empty()) q.pop();
	q.push(1);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		int len=e[now].size();
		for(int i=0;i<len;i++){
			if(dis[e[now][i]]!=0 && e[now][i]!=1)continue;
			dis[e[now][i]]=dis[now]+1;
			q.push(e[now][i]);
		}
	}
	return dis[n];
}

			
			
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	while(~scanf("%d%d%d%d",&n,&m,&a,&b)) {
		for(int i=1;i<=n;i++)
			e[i].clear();
		int u,v;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
			sort(e[i].begin(),e[i].end());
		if(e[n].size()>0 && e[n][0]==1) {
			if(a<=b)
				printf("%d\n",a);
			else {
				int tmp=bfs();
				if(tmp!=0)
					printf("%d\n",min(a,b*tmp));
				else
					printf("%d\n",a);
			}
		}
		else {
			if(a>=b) {
				printf("%d\n",b);
				continue;
			}
			else{
				int tmp=bfs2();
				if(tmp!=0)
					printf("%d\n",min(b,a*tmp));
				else
					printf("%d\n",b);
			}
		}
	}

	return 0;
}
