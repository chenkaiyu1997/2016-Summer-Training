#include<bits/stdc++.h> 
using namespace std;


int a[1005];
int n,s;
int dp[17][1005][1005];
const int mod=(1e9)+7;
int main() {
    register int tc;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d%d",&n,&s);
        for(register int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[0][0][0]=1;
        for(register int ju=1;ju<=n;ju++){
            for(register int i=0;i<16;i++)
                for(register int m=0;m<=s;m++) {
					register int tmp=dp[i][ju-1][m];
					if((i&2)>0){
						tmp+=dp[i^2][ju-1][m];
						if(tmp>=mod)tmp-=mod;
					}
					if((i&1)>0){
						tmp+=dp[i^1][ju-1][m];
						if(tmp>=mod)tmp-=mod;
					}

					//qu
					if(m>=a[ju]){
						tmp+=dp[i][ju-1][m-a[ju]];
						if(tmp>=mod)tmp-=mod;

						if((i&8)>0){
							tmp+=dp[i^8][ju-1][m-a[ju]];
							if(tmp>=mod)tmp-=mod;
						}

						if((i&4)>0){
							tmp+=dp[i^4][ju-1][m-a[ju]];
							if(tmp>=mod)tmp-=mod;
						}    
					}    
					dp[i][ju][m]=tmp;         
				}
        }
        register int ans=0;
        for(register int m=0;m<=s;m++) 
            ans=(ans+dp[15][n][m])%mod;
        printf("%d\n",ans);
    }
    return 0;
}
