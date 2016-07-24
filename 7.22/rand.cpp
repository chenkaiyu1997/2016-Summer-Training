#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("A.in","w",stdout);
	int n=20,m=3;
	srand(time(NULL));
	printf("%d %d\n",n,m);
	for(int i=1;i<=n-m;i++)
		printf("%d ",rand()%m+1);
	for(int i=1;i<=m;i++)
		printf("%d ",i);

	return 0;
}

