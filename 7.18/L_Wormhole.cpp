#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define fi first
using namespace std;
map<string,int> namemap;
double mp[65][65];
queue<int> q;
bool vis[65];
double dis[65];
int x[65],y[65],z[65];

double distance(double x1,double x2,double y1,double y2,double z1,double z2){
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1));
}
int n;
double spfa(int u,int v) {
	for(int i=1;i<=n;i++)dis[i]=1e50;
	vis[u]=true;
	dis[u]=0;
	q.push(u);
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[now]+mp[now][i]){
				dis[i]=dis[now]+mp[now][i];
				if(!vis[i])
					q.push(i);
			}
		vis[now]=false;
	}
	return dis[v];
}

int main()
{

	int tc;
	scanf("%d\n",&tc);
	for(int cc=1;cc<=tc;cc++){
		scanf("%d",&n);
		printf("Case %d:\n",cc);
		string name;
		for(int i=1;i<=n;i++){
			cin>>name;
			namemap[name]=i;
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		}
		ms(mp,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=distance(x[i],x[j],y[i],y[j],z[i],z[j]);
		int w=0;
		scanf("%d",&w);
		string name1,name2;
		for(int i=1;i<=w;i++)
		{
			cin>>name1>>name2;
			mp[namemap[name1]][namemap[name2]]=0;
		}	
		int q=0;
		cin>>q;
		for(int i=1;i<=q;i++) {
			cin>>name1>>name2;
			int tmp=round(spfa(namemap[name1],namemap[name2]));
			cout<<"The distance from "<<name1<<" to "<<name2<<" is "<<tmp<<" parsecs."<<endl;
		}
	}

	return 0;
}
