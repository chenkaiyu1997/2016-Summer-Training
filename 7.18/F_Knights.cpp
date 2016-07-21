#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

const ll mod=(1e9)+9;
int n,m;
int fi[8]={-2,-1,1,2,2,1,-1,-2};
int fj[8]={1,2,2,1,-1,-2,-2,-1};
int lim;
typedef ll arr[1<<8][1<<8];
arr A,B,s,tmparr;
int p[3][4];
arr storea[5];
arr stores[5];
bool isstore[4];

bool check(int state) {
	ms(p,0);
	int tmp=state;
	for(int i=1;i>=0;i--)
		for(int j=m-1;j>=0;j--,tmp>>=1)
			p[i][j]=tmp&1;
	for(int i=0;i<2;i++)
		for(int j=0;j<m;j++)
			if(p[i][j])
				for(int d=0;d<8;d++) {
					int ti=i+fi[d],tj=j+fj[d];
					if(ti>=0 && tj>=0 && ti<=2 && tj<m){
						if(ti<2 && p[ti][tj]) return false;
						if(ti==2) p[ti][tj]=1;
					}
				}
	int line3=0;
	for(int j=0;j<m;j++)
		line3=(line3<<1)+p[2][j];
	int limm=(1<<m)-1;
	line3=(~line3)&limm;	
	for(int i=0;i<=limm;i++)
		if((i|line3)==line3)
			A[state][i+((state&limm)<<m)]=1;
	return true;
}
void Multi(arr A,arr B,arr C) {
	ms(tmparr,0);
	for(int i=0;i<=lim;i++)
		for(int j=0;j<=lim;j++)
			for(int k=0;k<=lim;k++)
				tmparr[i][j]=(tmparr[i][j]+A[i][k]*B[k][j])%mod;
	for(int i=0;i<=lim;i++)
		for(int j=0;j<=lim;j++)
			C[i][j]=tmparr[i][j];
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	ms(isstore,0);
	scanf("%d\n",&tc);
	while(tc--){
		scanf("%d%d",&m,&n);
		if(n==1){
			printf("%d\n",1<<m);
			continue;
		}
		ms(A,0);ms(s,0);ms(B,0);
		n-=2;
		lim=(1<<2*m)-1;
		if(!isstore[m]) {
			for(int i=0;i<=lim;i++) {
				if(check(i))s[0][i]=1;
				else s[0][i]=0;
			}
			for(int i=0;i<=lim;i++)
				for(int j=0;j<=lim;j++)
				{
					stores[m][i][j]=s[i][j];
					storea[m][i][j]=A[i][j];
				}
			isstore[m]=true;
		}
		else{
			for(int i=0;i<=lim;i++)
				for(int j=0;j<=lim;j++)
				{
					s[i][j]=stores[m][i][j];
					A[i][j]=storea[m][i][j];
				}
		}
		for(int i=0;i<=lim;i++)
			B[i][i]=1;

		while(n) {
			if(n&1)Multi(B,A,B);
			Multi(A,A,A);
			n>>=1;
		}
		Multi(s,B,s);
		ll ans=0;
		for(int i=0;i<=lim;i++)
			ans=(ans+s[0][i])%mod;
		cout<<ans<<endl;
	}
	return 0;
}

