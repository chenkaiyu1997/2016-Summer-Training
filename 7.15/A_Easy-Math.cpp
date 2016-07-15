#include <bits/stdc++.h>
using namespace std;


bool check(int x) {
	int lim=ceil(sqrt(x));
	int lim2=floor(sqrt(x));
	if(x==lim*lim || x==lim2*lim2)return true;
	return false;
}
int a[100005];
int main()
{
	int n;
	while(n=0,scanf("%d",&n),n!=0) {
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		bool flag=true;
		for(int i=1;i<=n;i++) 
			if(!check(a[i])){
				flag=false;
				printf("No\n");
				break;
			}
		if(flag)
			printf("Yes\n");
	}
	return 0;
}
