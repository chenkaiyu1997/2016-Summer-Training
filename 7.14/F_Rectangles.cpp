#include<bits/stdc++.h>
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=25;
int x1[N],yy1[N],x2[N],y2[N];
int x[N*2],y[N*2];
int data[44][44];
int area[44][44];
int xl[44],yl[44];
int n,m;
map<int,int> xm,ym;

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cc=0;
	while(scanf("%d%d",&n,&m),n!=0) {
		xm.clear();ym.clear();
		cc++;
		printf("Case %d:\n",cc);
		for(int i=0;i<n;i++){
			scanf("%d%d%d%d",&x1[i],&yy1[i],&x2[i],&y2[i]);
			if(x1[i]>x2[i])swap(x1[i],x2[i]);
			if(yy1[i]>y2[i])swap(yy1[i],y2[i]);
			x[i*2]=x1[i];x[i*2+1]=x2[i];
			y[i*2]=yy1[i];y[i*2+1]=y2[i];
		}
		sort(x,x+2*n);
		sort(y,y+2*n);
		int xn=0;
		xm[x[0]]=0;
		xl[0]=x[0];
		for(int i=1;i<2*n;i++) {
			if(x[i]==x[i-1])
				xm[x[i]]=xn;
			else{
				xm[x[i]]=++xn;
				xl[xn]=x[i];
			}
		}
		int yn=0;
		ym[y[0]]=0;
		yl[0]=y[0];
		for(int i=1;i<2*n;i++) {
			if(y[i]==y[i-1])
				ym[y[i]]=yn;
			else{
				ym[y[i]]=++yn;
				yl[yn]=y[i];
			}
		}

		for(int i=0;i<xn;i++)
			for(int j=0;j<yn;j++) {
				int tmp=0;
				for(int k=0;k<n;k++)
					if(i>=xm[x1[k]] && i<xm[x2[k]] && j>=ym[yy1[k]] && j<ym[y2[k]])
						tmp+=1<<k;
				data[i][j]=tmp;
				area[i][j]=(xl[i+1]-xl[i]) * (yl[j+1]-yl[j]);
			}
		
		int nu,u;
		for(int i=1;i<=m;i++) {
			scanf("%d",&nu);
			int tmp=0;
			for(int j=0;j<nu;j++) {
				scanf("%d",&u);
				u--;
				tmp+=1<<u;
			}
			int ans=0;
			for(int xx=0;xx<xn;xx++) 
				for(int yy=0;yy<yn;yy++) 
					if(data[xx][yy] & tmp)
						ans+=area[xx][yy];
			printf("Query %d: %d\n",i,ans);
		}
		cout<<endl;
	}
	return 0;
}
