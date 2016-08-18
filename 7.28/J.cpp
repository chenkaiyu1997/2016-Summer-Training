#include<bits/stdc++.h> 
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x) & (-(x)))
using namespace std;
const int N=100005;
const int M=2000005;
ll l,r;
int n,m;
int a[N],b[N],c[M],f[N],upperlim;

int query(int pos){
	int tmp=0;
	while(pos){
		tmp=max(tmp,c[pos]);
		pos-=lb(pos);
	}
	return tmp;
}

void add(int pos,int val){
	while(pos<=upperlim){
		c[pos]=max(c[pos],val);
		pos+=lb(pos);
	}
}

int main(){ 
	freopen("A.in","r",stdin);
	int tc;
	scanf("%d",&tc);
	for(int tt=1;tt<=tc;tt++){
		cin>>n;
		int cnt0=0,mi=10000005;
		m=0;

		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			if(a[i]==0)
				cnt0++;
			else{
				b[++m]=a[i]-cnt0;
				mi=min(mi,b[m]);
			}
		}
		upperlim=0;
		for(int i=1;i<=m;i++){
			b[i]-=mi-1;
			upperlim=max(b[i],upperlim);
		}

		ms(c,0);
		int ans=0;
		for(int i=1;i<=m;i++)
			f[i]=1;
		for(int i=1;i<=m;i++){
			f[i]=query(b[i]-1)+1;
			ans=max(f[i],ans);
			add(b[i],f[i]);
		}
		ans+=cnt0;
		printf("Case #%d: ",tt);
		cout<<ans<<endl;
	}
	return 0;
}





