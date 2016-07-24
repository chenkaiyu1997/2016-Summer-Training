#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;


const int N=100005;
struct node{
	int v,id;
}f[N],w[N];
int ans[N];
map<int,int> mp;

bool cmp(const node& A,const node& B) {
	return A.v>B.v;
}

int main() {
	int a,b,c;
	scanf("%d%d%d%d",&f[1].v,&a,&b,&c);
	f[1].id=1;
	int rr,cc;
	scanf("%d%d",&rr,&cc);
	mp.clear();
	int u;
	for(int i=1;i<=rr;i++)
		for(int j=1;j<=cc;j++) {
			scanf("%d",&u);
			if(mp.count(u)==0)
				mp[u]=1;
			else
				mp[u]++;
		}
	int n=0;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		w[++n].v=it->second;
		w[n].id=it->first;
	}

	for(int i=2;i<=n;i++){
		f[i].id=i;
		f[i].v=(f[i-1].v*a+b)%c+1;
	}

	sort(f+1,f+n+1,cmp);
	sort(w+1,w+n+1,cmp);

	ms(ans,0);
	for(int i=1;i<=n;i++)
		ans[f[i].id]=w[i].id;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
