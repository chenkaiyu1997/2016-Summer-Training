#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<queue>
#define fi first
#define se second
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
char mp[1115][1115];
char tmpmp[75][75];
ll b[115][75];
ll h[1115][1115];
ll lim;
int n,m,q,p,t;

void init() {
	for(int i=0;i<n;i++) {
		ll tmp=0;
		for(int j=0;j<q-1;j++)
			tmp=(tmp<<1)+((mp[i][j]=='*')?1:0);
		for(int j=q-1;j<m;j++){
			tmp=(tmp<<1)+((mp[i][j]=='*')?1:0);			
			h[i][j-q+1]=tmp&lim;
		}
	}
}
bool check(int ti) {
	for(int i=0;i<=n-p;i++) 
		for(int j=0;j<=m-q;j++) {
			bool flag=true;
			for(int k=0;k<p;k++)
				if(b[ti][k] != h[i+k][j]){
					flag=false;
					break;
				}
			if(flag)return true;
		}
	return false;
}

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cc=0;
	while(scanf("%d%d%d%d%d\n",&n,&m,&t,&p,&q),n!=0) {
		cc++;
		lim=(1<<q)-1;
		for(int i=0;i<n;i++)
			scanf("%s",mp[i]);
		int ans=0;
		init();
		for(int i=0;i<t;i++){
			for(int j=0;j<p;j++)
				scanf("%s",tmpmp[j]);
			for(int j=0;j<p;j++) {
				b[i][j]=0;
				for(int k=0;k<q;k++)
					b[i][j]=(b[i][j]<<1) + ((tmpmp[j][k]=='*')?1:0);
			}
		}
		if(p>n || q>m){
			printf("Case %d: 0\n",cc);
			continue;
		}
		for(int i=0;i<t;i++)
			if(check(i))ans++;
		printf("Case %d: %d\n",cc,ans);
	}
	return 0;
}
