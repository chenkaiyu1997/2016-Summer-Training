#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define fi first
using namespace std;
int n,m;
bool dp[2][5005][505];
int way[25];
int main()
{

	int tc;
	scanf("%d\n",&tc);
	while(tc--){
		scanf("%d%d",&n,&m);
		int minway=1000,maxway=0;
		for(int i=0;i<m;i++){
			scanf("%d",&way[i]);
			minway=min(minway,way[i]);
			maxway=max(maxway,way[i]);
		}
		ms(dp,0);
		dp[1][0][0]=true;
		int ans=-1;
		for(int i=1;i<=100;i++) {
			int ju=i&1;
			ms(dp[ju^1],0);
			int liml=(i-1)*(i-1)*minway/2,limr=min(n,i*i*maxway/2);
			for(int pus=liml;pus<=limr;pus++){
				int lim2=min(500,maxway*(i-1));
				for(int sco=(i-1)*minway;sco<=lim2;sco++)
					if(dp[ju][pus][sco])
					for(int j=0;j<m;j++)
						if(pus+sco+way[j]<=n)
							dp[ju^1][pus+sco+way[j]][sco+way[j]]=true;
			}
			for(int sco=0;sco<=500;sco++)
				if(dp[ju][n][sco])
					ans=max(ans,sco);
		}
		printf("%d",ans);
		if(tc!=0)
			printf("\n");
	}

	return 0;
}
