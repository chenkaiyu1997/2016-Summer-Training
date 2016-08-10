#include<bits/stdc++.h>
#define lb(x) ((x) & (-(x)))
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
const int N=100005;
const int inf=1e9;


int n,m,sx,whole;
int x[N],a[N],b[N],tr[N],f[N];



int work(){
	x[0]=0;x[n+1]=x[n]+1;
	int r=n;
	ms(f,0);
	for(int i=n;i>=1;i--) {
		f[a[i]]++;
		while(r>0 && f[b[r]]>0){
			f[b[r]]--;
			r--;
		}
		tr[i]=r;
	}
//	for(int i=1;i<=n;i++) {
//		printf("%d ",tr[i]);
//	}
//printf("\n");
	int ans=inf;
	for(int i=1;i<=n;i++) {
		if(x[i]>sx){
			ans=min(ans,2*whole+2*max(x[tr[i]]-sx,0));
			break;
		}
		ans=min(ans,2*(sx-x[i])+2*whole+2*max(x[tr[i]]-sx,0));
//		printf("%d %d\n",i,ans);
	}
	return ans;
}

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
