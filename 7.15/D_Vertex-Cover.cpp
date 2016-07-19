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
const int N=505;
int n,m;
vector<int> e[N];
bool mustactive[N],active[35];
int ans;

void dfs(int p,int mcnt) {
	//printf("%d %d\n",p,mcnt);
	if(p==31 || p==n+1) {
		ans=min(ans,mcnt);
		return;
	}
	if(mcnt>ans)return;
	if(mustactive[p]) dfs(p+1,mcnt);
	else {
		
		mustactive[p]=true;
		dfs(p+1,mcnt+1);
		mustactive[p]=false;

		vector<int> tvec;
		tvec.clear();
		int len=e[p].size();
		for(int i=0;i<len;i++)
			if(mustactive[e[p][i]]==false){
				tvec.push_back(e[p][i]);
				mustactive[e[p][i]]=true;
			}
		len=tvec.size();
		dfs(p+1,mcnt+len);
		for(int i=0;i<len;i++) 
			mustactive[tvec[i]]=false;
	}			
}
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	while(n=0,scanf("%d%d",&n,&m),n!=0) {
		for(int i=1;i<=n;i++)
			e[i].clear();
		int u,v;
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ms(mustactive,0);
		ans=n;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
