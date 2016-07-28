#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
const int N=100005;
const ll inf=2e18;
int m;
ll n;
int w;
int h[N];

ll rk[N],lk[N];
bool check(ll mid) {
	int l,r=1;
	ll kuai=0;
	for(l=1;l<=w;l++){
		if(r<l)r=l;
		while(r<=w && h[r]<mid-1-(r-l)){
			kuai+=mid-1-(r-l)-h[r];
			r++;
		}
		if(r>w){rk[l]=inf;continue;}
		rk[l]=kuai;
		kuai-=mid-1-h[l];
		kuai+=r-l-1;
	}
	l=w;
	kuai=0;
	for(r=w;r>=1;r--) {
		if(r<l)l=r;		
		while(l>=1 && h[l]<mid-1-(r-l)){
			kuai+=mid-1-(r-l)-h[l];
			l--;
		}
		if(l<1){lk[r]=inf;continue;}
		lk[r]=kuai;
		kuai-=mid-1-h[r];
		kuai+=r-l-1;
	}
	lk[0]=inf;rk[w+1]=inf;
	for(int i=1;i<=w;i++) {
		if(mid<=h[i])return true;
		if(lk[i-1]+rk[i+1]+mid-h[i] <= n)
			return true;
	}
	return false;
}
		
		
int main(){
	freopen("landscape.in","r",stdin);
	freopen("landscape.out","w",stdout);
	cin>>w>>n;
	ll l=0,r=0;
	for(int i=1;i<=w;i++) {
		scanf("%d",&h[i]);
		l=max(l,(ll)h[i]);
	}
	r=l+w;	
	l--;
	while(l<r) {
		ll mid=(l+r)/2;
		//printf("%lld\n",mid);
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l-1<<endl;
	return 0;
}
