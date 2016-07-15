#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1005;
const int inf=2000000000;
bool vis[N][4];
int x[N],y[N];
int n,m;
int move() {
	if(n==0)return 0;
	int tx,ty,px=0,py=0,d=3;
	int ans=0;
	while(true) {
		//move
		int sto=0;
		if(d==0) {
			ty=inf;
			for(int i=1;i<=n;i++)
				if(x[i]==px && y[i]>py && y[i]<ty) {
					sto=i;
					ty=y[i];
				}
			py=ty-1;
			d=3;
		}
		else if(d==1) {
			tx=-inf;
			for(int i=1;i<=n;i++)
				if(y[i]==py && x[i]<px && x[i]>tx) {
					sto=i;
					tx=x[i];
				}
			px=tx+1;
			d=0;
		}
		else if(d==2) {
			ty=-inf;
			for(int i=1;i<=n;i++)
				if(x[i]==px && y[i]<py && y[i]>ty) {
					sto=i;
					ty=y[i];
				}
			py=ty+1;
			d=1;
		}
		else{
			tx=inf;
			for(int i=1;i<=n;i++)
				if(y[i]==py && x[i]>px && x[i]<tx) {
					sto=i;
					tx=x[i];
				}
			px=tx-1;
			d=2;
		}
		if(sto==0)return ans;
		ans++;
		if(vis[sto][d])return -1;
		vis[sto][d]=true;
	}
	return 0;
}
					

int main()
{
	while(n=-1,scanf("%d",&n),n!=-1) {
		for(int i=1;i<=n;i++) {
			scanf("%d%d",&x[i],&y[i]);
		}
		ms(vis,0);
		printf("%d\n",move());
	}
	return 0;
}
