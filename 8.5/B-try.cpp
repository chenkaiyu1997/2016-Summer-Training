#include<bits/stdc++.h>
#define lb(x) ((x) & (-(x)))
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;


int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		scanf("%d",&n);
		scanf("%d",&sx);
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&x[i],&a[i],&b[i]);
		if(sx<=x[1]){printf("%d\n",(x[n]-sx)*2);continue;}
		if(sx>=x[n]){printf("%d\n",(sx-x[1])*2);continue;}
		whole=x[n]-x[1];
		int ans=work();

		int maxr=x[n]+1;
		for(int i=1;i<=n;i++)
			x[i]=maxr-x[i];
		sx=maxr-sx;
		for(int i=1;i<=n/2;i++) {
			swap(x[i],x[n+1-i]);
			swap(a[i],a[n+1-i]);
			swap(b[i],b[n+1-i]);
		}
		//printf("%d\n",ans);
		printf("%d\n",min(ans,work()));
	}
	return 0;
}
