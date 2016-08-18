#include<bits/stdc++.h> 
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x) & (-(x)))
using namespace std;
const int N = 1048600;
int eu[405],ev[405];
int l[N];
int sum[N];
bool show[N];
int n,m;
queue<int> q;
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		scanf("%d %d",&n,&m);
		int tu,tv;
		ms(l,0);
		for(int i=1;i<=m;i++){
			scanf("%d %d",&tu,&tv);
			l[1<<tu]|=1<<tv;
			l[1<<tv]|=1<<tu;

			eu[i] = 1<<tu;
			ev[i] = 1<<tv;
		}

		int lim = 1<<n;
		for(int i=0;i<lim;i++) {
			l[i]=l[lb(i)] | l[i-lb(i)];
		}
		ms(show,0);
		while(!q.empty())
			q.pop();
		for(int i=0;i<n;i++){
			show[1<<i]=true;
			q.push(1<<i);
		}

		while(!q.empty()) {
			int now=q.front();
			q.pop();
			int cr=l[now];
			while(cr){
				int tmp=lb(cr);
				cr-=tmp;
				if(!show[tmp|now]){
					show[tmp|now]=true;
					q.push(tmp|now);
				}
			}
		}
		ms(sum,0);
		int all=0;
		for(int i=0;i<lim;i++){
			int j=(lim-1)^i;
			if(i>j)continue;
			if(show[i] && show[j]){
				all++;
				sum[i]=1;
				sum[j]=1;
			}
		}

		for(int i=0;i<n;i++)
			for(int j=lim-1;j>=0;j--)
				if(((1<<i) & j) ==0 )
					sum[j]+=sum[j^(1<<i)];
		printf("Case #%d:",tt);
		for(int i=1;i<=m;i++)
			printf(" %d",all - sum[eu[i] | ev[i]]);
		printf("\n");
	}
	return 0;
}





