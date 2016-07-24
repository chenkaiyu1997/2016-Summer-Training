#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
int lim;
bool vis[200005];
int prime[200005],pn=0;

ll gcd(ll A,ll B) {
	if(B==0)return A;
	return gcd(B,A%B);
}

void findprime() {
	ms(vis,0);
	pn=0;
	for(int i=2;i<=lim;i++) {
		if(!vis[i])
			prime[pn++]=i;
		for(int j=0;j<pn && i*prime[j]<=lim;j++) {
			vis[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
}

ll findphi(ll x) {
	ll ans=x;
	for(int i=0;i<pn;i++) {
		if(x % prime[i] == 0 )
			ans=ans/prime[i]*(prime[i]-1);
		while(x % prime[i]==0)
			x/=prime[i];
	}
	if(x!=1)ans=ans/x*(x-1);
	return ans;
}
ll multi(ll a,ll b,ll mod) {
	ll t=0;
	while(b){
		if(b&1) t=(t+a) % mod;
		a=(a<<1)%mod;
		b>>=1;
	}
	return t;
}
ll mi(ll a,ll b,ll mod) {
	ll t=1;
	while(b) {
		if(b&1) t=multi(t,a,mod);
		a=multi(a,a,mod);
		b>>=1;
	}
	return t;
}

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cc=0;
	int l;
	while(scanf("%d",&l),l!=0) {
		cc++;
		printf("Case %d: ",cc);
		if(gcd(l,5)==5 || gcd(l,16)==16){
			printf("0\n");
			continue;
		}
		ll x=(ll)l*9/(ll)gcd(l,8);
		lim=floor(sqrt((double)x));
		findprime();
		ll px=findphi(x);
		
		lim=floor(sqrt((double)px));
		bool ifind=false;
		for(int i=1;i<=lim;i++) {
			if(px % i)continue;
			if(mi(10,i,x)==1){
				printf("%d\n",i);
				ifind=true;
				break;
			}
		}
		for(int i=lim;i>=1;i--) {
			if(px % i)continue;
			if(mi(10,px/(ll)i,x)==1){
				cout<<px/(ll)(i)<<endl;
				ifind=true;
				break;
			}
		}

		if(!ifind)
			cout<<"error"<<endl;
	}
	return 0;
}
