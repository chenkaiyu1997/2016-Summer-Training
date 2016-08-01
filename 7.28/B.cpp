#include<bits/stdc++.h> 
using namespace std;
const int N=100005;
vector<int> e[N];
int a[N];
bool acer[N];
map<int,bool> ma;
int n;
int degn[N];
int cntn=0;

bool dfs(int p,int fa) {
	bool flag=true;
	for(int i=0;i<e[p].size();i++) {
		if(e[p][i]==fa)continue;
		if(a[e[p][i]]>a[p])return false;
		if(a[e[p][i]]==a[p]){
			if(flag==false)return false;
			flag=false;
		}
	}
	if(flag){
		acer[p]=true;
		if(ma.count(n+1-a[p])!=1)return false;
		ma.erase(n+1-a[p]);
	}
	for(int i=0;i<e[p].size();i++){
		if(e[p][i]==fa)continue;
		if(!dfs(e[p][i],p))return false;
	}
	return true;
}

int newcntn=0;

void dfs1(int p,int fa) {
	newcntn++;
	for(int i=0;i<e[p].size();i++){
		if(e[p][i]==fa)continue;
		if(a[e[p][i]]!=n)continue;
		dfs1(e[p][i],p);
	}
}
		

bool work() {
	if(cntn==0)return false;
	for(int i=1;i<=n;i++)
		if(a[i]==n &&degn[i]<=1){
			newcntn=0;
			dfs1(i,0);
			break;
		}
	if(cntn!=newcntn)return false;
	memset(acer,0,sizeof(acer));
	int root=n+1;
	for(int i=1;i<=n;i++)
		if(a[i]==n && degn[i]<=1){
			root=i;
			break;
		}
	if((!dfs(root,0)))
		return false;
	for(int i=n;i>=1;i--) {
		if(acer[i])continue;
		map<int,bool>::iterator it=ma.lower_bound(n+1-a[i]);
		if(it==ma.end()) return false;
		a[i]=n+1-it->first;
		ma.erase(n+1-a[i]);
	} 
	return true;
}
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++) {
		cntn=0;
		printf("Case #%d: ",tt);
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==n)cntn++;
		}
		int u,v;
		for(int i=1;i<=n;i++)
			e[i].clear();
		memset(degn,0,sizeof(degn));
		for(int i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			if(a[u]==n)degn[v]++;
			if(a[v]==n)degn[u]++;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ma.clear();
		for(int i=1;i<=n;i++)
			ma[n+1-i]=true;

		if(!work())
			printf("Impossible\n");
		else{
			for(int i=1;i<n;i++)
				printf("%d ",a[i]);
			printf("%d\n",a[n]);
		}
	}
	return 0;
}





