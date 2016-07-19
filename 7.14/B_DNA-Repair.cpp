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

struct trie {
	int ch[4];
	bool isword;
}t[1005];
int n;
int dp[1005][1005],st=0;
char str[55][25];
int nxt[1005];
int f[250];
char para[1005];

void add(char *si) {
	int p=1;
	for(;*si;si++) {
		int togo=f[*si];
		if(!t[p].ch[togo])
			t[p].ch[togo]=++st;
		p=t[p].ch[togo];
	}
	t[p].isword=true;
}
queue<int> q;
void bfs() {
	while(!q.empty())q.pop();
	q.push(1);
	nxt[1]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop();
		for(int i=0;i<4;i++) {
			if(t[now].ch[i]==0)continue;			
			int tmp=nxt[now];
			while(tmp!=0 && t[tmp].ch[i]==0)tmp=nxt[tmp];
			if(tmp==0)nxt[t[now].ch[i]]=1;
			else nxt[t[now].ch[i]]=t[tmp].ch[i];
			if(t[nxt[t[now].ch[i]]].isword) t[t[now].ch[i]].isword=true;
			q.push(t[now].ch[i]);
		}
	}
}

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	f[(int)'A']=0;f[(int)'T']=1;f[(int)'C']=2;f[(int)'G']=3;
	int cc=0;
	while(scanf("%d\n",&n),n!=0) {
		cc++;
		ms(t,0);
		st=1;
		for(int i=1;i<=n;i++){
			scanf("%s",str[i]);
			add(str[i]);
		}
		bfs();
		scanf("%s",para);
		ms(dp,27);
		int len=strlen(para);
	//	cerr<<para;
		dp[0][1]=0;
		for(int i=0;i<len;i++)
			for(int j=1;j<=st;j++)
				if(dp[i][j]<10000) {
					int tc=f[para[i]];
					for(int k=0;k<=3;k++){
						int tmp=j;
						while(tmp!=0 && t[tmp].ch[k]==0)tmp=nxt[tmp];
						//cerr<<tmp<<" ";
						if(tmp==0)
							dp[i+1][1]=min(dp[i+1][1],dp[i][j] + ((k==tc)?0:1));
						else if(!t[t[tmp].ch[k]].isword)
							dp[i+1][t[tmp].ch[k]]=min(dp[i+1][t[tmp].ch[k]] , dp[i][j] + ((k==tc)?0:1));
					}
				}
	
		int ans=10000;
		for(int j=1;j<=st;j++)
			ans=min(ans,dp[len][j]);
		if(ans==10000)ans=-1;
		//cerr<<st<<endl;
		printf("Case %d: %d\n",cc,ans);
	}

	return 0;
}
