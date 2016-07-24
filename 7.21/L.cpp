#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=100005;
const int M=32;
char s[N],p[M];
int n,m;
bitset<N> tmp,t[26],dp[2][3];
int main() {
	freopen("A.in","r",stdin);
    int tc;
    scanf("%d",&tc);
    while(tc--){
            int n,m;
            scanf("%d%d",&n,&m);
			ms(s,0);ms(p,0);
			scanf("%s",s+1);
			scanf("%s",p+1);
			ms(dp,0);
			int ju;
			for(int i=1;i<=n;i++)
				for(int j=0;j<26;j++){
					if(s[i]=='a'+j)
						t[j][i]=1;
					else
						t[j][i]=0;
				}
			dp[0][0].set();
			for(int j=1;j<=m;j++) {
				ju=j&1;
				dp[ju^1][0]<<=1;
				dp[ju^1][1]<<=1;
				dp[ju^1][2]<<=1;
				
				dp[ju][0]=t[p[j]-'a'] & (dp[ju^1][0] | dp[ju^1][2]);
				if(j!=m)dp[ju][1]=t[p[j+1]-'a'] & (dp[ju^1][0] | dp[ju^1][2]);
				if(j!=1)dp[ju][2]=t[p[j-1]-'a'] & dp[ju^1][1];
			}
			ju=m&1;
			for(int i=1;i<=n;i++){
				if(i<m)continue;
				if(dp[ju][0][i] || dp[ju][2][i])
					printf("1");
				else
					printf("0");
			}
			for(int i=1;i<m;i++){
				printf("0");
			}
			printf("\n");
    }
    return 0;
}
