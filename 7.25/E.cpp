#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
int a[11][11];
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	int len[11];
	int n,k,tot=0,procnt=0;
	scanf("%d%d",&n,&k);
	ms(a,-1);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++)
			scanf("%d",&a[i][j]);
	}
	for(int j=1;j<=10;j++)
		for(int i=1;i<=n;i++) {
			int har;
			if(a[i][j]==-1)
				har=50;
			else if(a[i][j]<tot)
				har=-1;
			else
				har=a[i][j];
			if(har>=tot){
				tot+=har;
				procnt++;
				if(procnt==k)goto l1;
			}
		}
l1: if(procnt<k)tot+=50*(k-procnt);
	printf("%d\n",tot);
	return 0;
}
