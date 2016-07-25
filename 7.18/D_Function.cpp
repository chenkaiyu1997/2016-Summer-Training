#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define fi first
using namespace std;

int n,m;
double a,b,c,d,r;
bool vis[205];
int st;
double brt2[205];
int pos[205];
double aorc[205];

double dfs(int nn) {
	//printf("dfs:%d\n ",nn);
	vis[nn+100]=1;
	pos[nn+100]=++st;
	double t=(double)(nn)/(double)(m);
	brt2[st]=b+r*t*t;
	int tmpnn;	
	if(nn<=0) {tmpnn=-m-2*nn;
		brt2[st]=b+r*t*t;
		aorc[st]=a;
	}
	else{
		tmpnn=m-2*nn;
		brt2[st]=d+r*t*t;
		aorc[st]=c;
	}
		
	if(vis[tmpnn+100]) {
		int src=pos[tmpnn+100];
		double lc=1/r;
		double rval=0;
		while(1){
			rval+=lc*aorc[src];			
			lc*=brt2[src]/r;
			src++;
			if(src==st+1)break;
		}
		lc*=r;
		double lval=1-lc;
		//printf("HUAN=%lf\n",rval/lval);
		return rval/lval;
	}
	else
		return (aorc[pos[nn+100]]+brt2[pos[nn+100]]*dfs(tmpnn))/r;
}



int main()
{
	freopen("A.in","r",stdin);
	int tc;
	scanf("%d",&tc);
	while(tc--){
		ms(vis,0);
		st=0;
		scanf("%d%d",&n,&m);
		cin>>a>>b>>c>>d>>r;
		printf("%.12lf\n",dfs(n));
	}
	return 0;
}
