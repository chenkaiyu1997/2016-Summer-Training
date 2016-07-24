#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=20;
const int INF=1000;
int n,m;
int p[maxn];
int dp[maxn][maxn][2];

void dfs(int L,int R){
    if(dp[L][R][0]!=-1) return;
    if(L==R){
        dp[L][R][0]=1;dp[L][R][1]=(p[L]==p[L-1])?0:INF;return;
    }

    dfs(L+1,R);
    dp[L][R][0]=dp[L+1][R][1]+1;
    dp[L][R][0]=min(dp[L][R][0],dp[L+1][R][0]+1);
    dp[L][R][1]=INF;

    if(p[R]==p[L-1]){
        dfs(L,R-1);
        dp[L][R][1]=min(dp[L][R-1][0],dp[L][R][1]);
        dp[L][R][1]=min(dp[L][R][1],dp[L][R-1][1]);
    }
    for(int k=L;k<R;k++){
        if(p[k]==p[L-1]){
            dfs(L,k);dfs(k+1,R);
            dp[L][R][1]=min(dp[L][R][1],dp[L][k][1]+dp[k+1][R][0]);
        }
    }

    return;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("Astd.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    p[0]=-1;
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(p[i]!=p[cnt]) p[++cnt]=p[i];
    }
    n=cnt;
    memset(dp,-1,sizeof(dp));
    dfs(1,n);

    printf("%d\n",dp[1][n][0]-1);
	return 0;
}
