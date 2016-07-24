#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
const int N=105;
const int inf=1e9;
struct node{
	int p,t,id;
}a[N];
int ans[N];
bool cmp(const node& A,const node& B) {
	return A.t*B.p<B.t*A.p;
}

int dp[105][1005][2];
pair<int,int> fa[105][1005];


int main() {
	freopen("A.in","r",stdin);
	int n,tot;
	scanf("%d%d",&n,&tot);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].t,&a[i].p);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	ms(dp,0);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=tot;j++){
			int p1=dp[i-1][j][0],p2=dp[i-1][j-a[i].t][0]+a[i].p;
			int t1=dp[i-1][j][1],t2=dp[i-1][j-a[i].t][1]+j*(a[i].p);
			if(j-a[i].t<0 || p1>p2 || (p1==p2 && t1<t2) ){
				dp[i][j][0]=p1;
				dp[i][j][1]=t1;
				fa[i][j]=make_pair(i-1,j);
			}
			else {
				dp[i][j][0]=p2;
				dp[i][j][1]=t2;
				fa[i][j]=make_pair(i-1,j-a[i].t);
			}
		}
	int ans=0,mint=inf,maxj;
	for(int j=0;j<=tot;j++) 
		if(ans<dp[n][j][0] || (ans==dp[n][j][0] && mint>dp[n][j][1])) {
			ans=dp[n][j][0];
			mint=dp[n][j][1];
			maxj=j;
		}
	pair<int,int>tmp=mp(n,maxj);
	vector<int> ansrec;
	ansrec.clear();
	while(tmp.fi>=1) {
		if(fa[tmp.fi][tmp.se].se<tmp.se) 
			ansrec.pb(a[tmp.fi].id);
		tmp=fa[tmp.fi][tmp.se];
	}
	int len=ansrec.size();
	printf("%d\n",len);
	for(int i=len-1;i>=0;i--)
		printf("%d ",ansrec[i]);
	return 0;
}
