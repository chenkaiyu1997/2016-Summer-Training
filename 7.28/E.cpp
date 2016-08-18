#include<bits/stdc++.h> 
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x) & (-(x)))
using namespace std;
ll l,r;
int n;

// calculate the number of numbers in [l,r] that mod a == b
ll calc(ll a,ll b) {
	if(a==0)return 0;
	ll ans=(r-l)/a;
	ll tmpl=l%a,tmpr=r%a;
	if(tmpr<tmpl){
		if(b<=tmpr || b>=tmpl)ans++;
	}
	else if(b>=tmpl && b<=tmpr)ans++;
	//cout<<"calc"<<a<<' '<<b<<' '<<'='<<ans<<endl;
	return ans;
}


ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=y;
	y=x - (a/b) * y;
	x=t;
	return r;
}

ll multi(ll a,ll b,ll m){
	ll t=0;
	while(b){
		if(b&1) t=(t+a)%m;
		a=a*2%m;
		b>>=1;
	}
	return t;
}


ll p[16],rr[16];
int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		cin>>n>>l>>r;
		for(int i=1;i<=n;i++) {
			cin>>p[i-1]>>rr[i-1];
		}
		ll ans = 0;
		int lim=1<<n;
		for(int i=0;i<lim;i++){
			int cnt=0;
			ll tmpp=1;
			for(int j=0;j<n;j++)
				if((i>>j) & 1) {
					tmpp*=p[j];
					cnt++;
				}
			tmpp*=7;
			ll fuhao=1;
			if(cnt&1)fuhao=-1;

			ll tans=0;			
			for(int j=0;j<n;j++)
				if((i>>j)&1) {
					ll pj=tmpp/p[j];
					ll x,y;
					exgcd(pj,p[j],x,y);
					x=x+p[j];
				//	printf("%lld * %lld mod %lld ==1 \n",pj,x,p[j]);
					
					x=multi(multi(x,pj,tmpp),rr[j],tmpp);
					tans=(tans + x) % tmpp;
				}
			ans+=fuhao * calc(tmpp,tans);
		}
		printf("Case #%d: ",tt);
		cout<<ans<<endl;
	}
	return 0;
}





