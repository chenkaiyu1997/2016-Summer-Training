#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;


const int N=100005;
int a[N];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)swap(n,m);
	int nm=n*m,nn=n*n;
	for(int i=1;i<=nm;i++)
		scanf("%d",&a[i]);
	int x=nm-nn;
	long long ans=0;
	ans+=a[nm]+a[nm];
	int u=nm-1,v=nm-2;
	for(int i=2;i<=n;i++) {
		ans+=a[u]+a[v];
		u-=2*i-1;
		v-=2*i;
	}
	for(int i=x;i>0;i-=n)
		ans+=a[i];
	cout<<ans*2<<endl;
	return 0;
}
