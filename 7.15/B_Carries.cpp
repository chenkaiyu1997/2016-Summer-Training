#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fi first
#define se second
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=200005;
int a[N],ta[N],n;
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	while(n=0,scanf("%d",&n),n!=0) {
		ms(a,0);ms(ta,0);
		for(int i=1;i<=n;i++) 
			scanf("%d",&a[i]);
		ll ans=0;
		for(ll base=10;base<=10000000000LL;base*=10) {
			for(int i=1;i<=n;i++)
				ta[i]=a[i]%base;
			sort(ta+1,ta+1+n);
			int p=n;
			for(int i=1;i<=n;i++) {
				while(p>i && ta[i]+ta[p]>=base) p--;
				if(p<i)p=i;
				ans+=n-p;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
