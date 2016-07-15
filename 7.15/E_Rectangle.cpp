#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
const int N=5000006;
const int inf=2000000000;
const int M=100;
int ans[M];
int tmp[M];
int tmp2[M];
void add(ll num) {
	ms(tmp,0);
	while(num) {
		tmp[++tmp[0]]=num%10;
		num/=10;
	}
	ms(tmp2,0);
	int lim=max(ans[0],tmp[0]);
	for(int i=1;i<=lim;i++) {
		tmp2[i]+=tmp[i]+ans[i];
		tmp2[i+1]=tmp2[i]/10;
		tmp2[i]=tmp2[i]%10;
	}
	if(tmp2[lim+1]!=0)tmp2[0]=lim+1;
	else tmp2[0]=lim;
	for(int i=0;i<=tmp2[0];i++)
		ans[i]=tmp2[i];
}

int main()
{
	ll n,m,k;
	while(cin>>n>>m>>k){
		k/=2;
		ms(ans,0);
		if(n>m)swap(n,m);
		for(ll i=1;i<=n;i++)
			if(k-i>=1) {
				ll lim=min(m,k-i);
				add((n-i+1) * (m-lim+1+m) * lim / 2);
			}
		if(ans[0]==0)printf("0");
		for(int tans=ans[0];tans>=1;tans--)
			printf("%d",ans[tans]);
		cout<<endl;
	}
	return 0;
}
