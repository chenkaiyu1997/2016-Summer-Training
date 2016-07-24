#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=1005;
int per[15],pernum=0;
int main()
{
	while(scanf("%d",&n)!=EOF) {
		pernum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
			b[i]++;
			if(b[i]==10001)per[++pernum]=i;
		}
		for(int i=1;i<=pernum;i++) {
			ms(c,0);
			int lp=(per[i]==0)?(n-1):(per[i]-1);
			int rp=(per[i]+1)%n;
			for(int p=rp;p!=lp;p=(p+1)%n){
				if(b[p]==10001)continue;
				int tmp=query(b[p])+1;
				update(b[p],);

		ms(vis,0);
		printf("%d\n",move());
	}
	return 0;
}
