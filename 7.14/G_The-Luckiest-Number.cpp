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
bool vis[100005];
int prime[100005],pn=0;

ll gcd(ll A,ll B) {
	if(B==0)return A;
	return gcd(B,A%B);
}


void findprime() {
	ms(vis,0);
	pn=0;
	for(int i=2;i<=lim;i++) {
		if(vis[i])continue;
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
	return x;
}


int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cc=0;
	int l;
	while(scanf("%d",&l),l!=0) {
		cc++;
		printf("Case %d: ",cc);
		if(gcd(l,5)==5 || gcd(l,16)==16) printf("0\n");
		ll x=(ll)l*9/gcd(l,8);
		lim=floor(sqrt((double)x));
		findprime();
		ll px=findphi(x);
		lim=floor(sqrt((double)px));
		for(int i=0;i<pn && prime[i]<=lim;i++) {
			if(pow(10,prime[i\
						]))
	}
	return 0;
}
