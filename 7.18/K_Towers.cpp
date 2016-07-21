#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

char str[10];
int l[8],r[8],d[8],u[8];
int c[8][8];
int n;

int fi[4]={0,-1,0,1};
int fj[4]={-1,0,1,0};

bool check(int nu,int row,int col) {
	c[row][col]=0;
	for(int k=1;k<=n;k++)
		if(nu==c[row][k])return false;
	for(int k=1;k<=n;k++)
		if(nu==c[k][col])return false;
	c[row][col]=nu;

	int see=0,ke=0;
	for(int k=1;k<=col;k++)
		if(c[row][k]>ke){ke=c[row][k];see++;}
	if(l[row] && (see>l[row] || n-ke<l[row]-see || (col==n && see!=l[row])))	{
		c[row][col]=0;
		return false;
	}

	see=0;ke=0;
	for(int k=1;k<=row;k++)
		if(c[k][col]>ke){ke=c[k][col];see++;}
	if(u[col] && (see>u[col] || n-ke<u[col]-see || (row==n && see!=u[col])))	{
		c[row][col]=0;
		return false;
	}
	if(col==n && r[row]){
		see=0;ke=0;
		for(int k=n;k>=1;k--)
			if(c[row][k]>ke){ke=c[row][k];see++;}
		if(see!=r[row]){
			c[row][col]=0;
			return false;
		}
	}
	if(row==n && d[col]){
		see=0;ke=0;
		for(int k=n;k>=1;k--)
			if(c[k][col]>ke){ke=c[k][col];see++;}
		if(see!=d[col]){
			c[row][col]=0;
			return false;
		}
	}
	return true;
}


bool dfs(int row,int col) {
	if(row==n+1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d",c[i][j]);
			printf("\n");
		}
		printf("\n");
		return true;
	}
	int trow,tcol;
	if(col==n){trow=row+1;tcol=1;}
	else {trow=row;tcol=col+1;}
	if(c[row][col]){
		int nu=c[row][col];
		if(check(nu,row,col)){
			c[row][col]=nu;
			if(dfs(trow,tcol))return true;
		}
		c[row][col]=nu;		
		return false;
	}
	for(int i=1;i<=n;i++) 
		if(check(i,row,col)){
			c[row][col]=i;
			if(dfs(trow,tcol))return true;
			c[row][col]=0;
		}
	return false;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	scanf("%d\n",&tc);
	while(tc--){
		scanf("%d",&n);
		ms(c,0);ms(l,0),ms(u,0),ms(d,0),ms(r,0);
		for(int i=0;i<n+2;i++) {
			scanf("%s",str);
			if(i==0) {
				for(int j=1;j<=n;j++)
					u[j]=((str[j]=='-')?0:(str[j]-'0'));
			}
			else if(i==n+1) {
				for(int j=1;j<=n;j++)
					d[j]=((str[j]=='-')?0:(str[j]-'0'));
			}
			else{
				if(str[0]=='-')l[i]=0;
				else 
					l[i]=str[0]-'0';
				if(str[n+1]=='-')r[i]=0;
				else
					r[i]=str[n+1]-'0';
				for(int j=1;j<=n;j++)
					c[i][j]=((str[j]=='-')?0:(str[j]-'0'));
			}
		}	

		if(!dfs(1,1))printf("no\n\n");


	}
	return 0;
}

