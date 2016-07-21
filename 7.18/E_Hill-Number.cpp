#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;

ll f[75][10][2][2];
int len,a[75];
char str[105];

ll dfs(int p,int nu,int isdown,int lim) {
	if(p==len+1)return 1;
	if(f[p][nu][isdown][lim]!=-1)return f[p][nu][isdown][lim];
	ll tmpans=0;
	int r=lim?a[p]:9;
	for(int i=0;i<=r;i++) {
		if(!isdown){
			if(i>=nu) tmpans+=dfs(p+1,i,0,lim && i==r);
			else tmpans+=dfs(p+1,i,1,lim && i==r);
		}
		else if (i<=nu) tmpans+=dfs(p+1,i,1,lim && i==r);
	}
	return f[p][nu][isdown][lim]=tmpans;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tc;
	scanf("%d\n",&tc);
	while(tc--){
		scanf("%s",str);
		len=strlen(str);
		for(int i=0;i<len;i++)
			a[i+1]=str[i]-'0';

		bool isdown=false;
		bool ishill=true;
		for(int i=2;i<=len;i++){
			if(a[i]<a[i-1])
				isdown=true;
			if(isdown && a[i]>a[i-1]){
				printf("-1");
				ishill=false;
				break;
			}
		}
		if(ishill) {
			ms(f,-1);
			cout<<dfs(1,0,0,1)-1;
		}
		if(tc!=0)
			printf("\n");
	}
	return 0;
}

