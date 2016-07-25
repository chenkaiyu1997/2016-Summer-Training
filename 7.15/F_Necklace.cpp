#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define lb(x) ((x) & (-x))
using namespace std;
const int N=100005;
int per[15],pernum=0;
int cl[N],c[N],b[N];

int query(int num){
	int ans=0;
	for(;num;num-=lb(num))
		ans=max(c[num],ans);
	return ans;
}

void update(int pos,int num) {
	for(;pos<=10001;pos+=lb(pos))
		c[pos]=max(c[pos],num);
}

int main()
{
	freopen("A.in","r",stdin);
	int n;
	while(scanf("%d",&n)!=EOF) {
		pernum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
			if(b[i]==10000)per[++pernum]=i;
		}
		int rans=0;
		for(int i=1;i<=pernum;i++) {
			ms(c,0);
			int lp=(per[i]==0)?(n-1):(per[i]-1);
			int rp=(per[i]+1)%n;
			int ans=0;
			for(int p=rp;p!=lp;p=(p+1)%n){
				if(b[p]==10000)continue;
				int tmp=query(10001-b[p]);
				cl[p]=tmp;
				update(10001-b[p],tmp+b[p]);
			}
			ms(c,0);			
			for(int p=lp;p!=rp;p=((p==0)?(n-1):(p-1))){
				if(b[p]==10000)continue;
				int tmp=query(10001-b[p]);
				ans=max(ans,b[p]+cl[p]+tmp);
				update(10001-b[p],tmp+b[p]);
			}
			rans=max(ans,rans);
		}
		printf("%d\n",rans+10000);
	}		
	return 0;
}
