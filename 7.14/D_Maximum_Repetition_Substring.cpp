#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=100005;
char str[N];
int r[N];
int n,m;
int wx[N],tsa[N],sa[N],b[N],height[N],rnk[N];
int st[N][25];
bool cmp(int *r,int i,int j,int k) {
	return r[i]==r[j] && r[i+k]==r[j+k];
}
void calcheight() {
	int i,j,k=0;
	for(i=0;i<n;i++)rnk[sa[i]]=i;
	for(i=0;i<n;height[rnk[i++]]=k)
		for(k?k--:k,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}

void da() {
	int i,j,p,*x=wx,*t,*y=tsa;
	for(i=0;i<m;i++)b[i]=0;
	for(i=0;i<n;i++)b[x[i]=r[i]]++;
	for(i=1;i<m;i++)b[i]+=b[i-1];
	for(i=n-1;i>=0;i--)sa[--b[x[i]]]=i;
	for(p=1,j=1;p<n;j*=2,m=p) {
		for(p=0,i=n-j;i<n;i++)y[p++]=i;
		for(i=0;i<n;i++)if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<m;i++)b[i]=0;
		for(i=0;i<n;i++)b[x[i]]++;
		for(i=1;i<m;i++)b[i]+=b[i-1];
		for(i=n-1;i>=0;i--) sa[--b[x[y[i]]]]=y[i];
		t=x;x=y;y=t;x[sa[0]]=0;
		for(i=1,p=1;i<n;i++) 
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
	/*for(i=0;i<n;i++){
		rnk[i]=x[i];
		cout<<x[i]<<" ";
	}
	cout<<endl;*/
}
void initst() {
	for(int i=1;i<n;i++)
		st[i][0]=height[i];
	for(int j=1;(1<<j)<n;j++)
		for(int i=1;i+(1<<(j-1))<n;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int lcp(int i,int j) {
	//printf("Ans of lcp%d %d",i,j);	
	if(i>=n || j>=n || i<0 || j<0)return 0;
	i=rnk[i];j=rnk[j];
	if(i>j)swap(i,j);
	i++;
	if(i==j){
//		printf("is %d\n",st[i][0]);
		return st[i][0];
	}
	int tmp=(int)(log(j-i)/log(2.0));
//	printf("is %d\n",min(st[i][tmp],st[j-(1<<tmp)+1][tmp]));
	return min(st[i][tmp],st[j-(1<<tmp)+1][tmp]);
}

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int cc=0;
	while(scanf("%s",str),str[0]!='#') {
		cc++;
		n=strlen(str);m=27;
		for(int i=0;i<n;i++)
			r[i]=str[i]-'a'+1;
		r[n++]=0;
		da();
		calcheight();
		initst();
		n--;

		vector<int> ans;
		int ansci=0;
		for(int l=1;l<n;l++) 
			for(int i=0;i+l<n;i+=l) {
				int tmp=lcp(i,i+l);
				int step=tmp/l+1;
				int k=i-(l-tmp%l);
				if(k>=0 && tmp%l!=0)
					step=max(step,lcp(k,k+l)/l+1);
				if(step>ansci){
					ans.clear();
					ansci=step;
					ans.push_back(l);
				}
				else if(step==ansci)
					ans.push_back(l);
			}
		int ansi=-1,ansl=0;
		for(int i=0;i<n;i++) {
			int len=ans.size();
			for(int j=0;j<len;j++) {
				int l=ans[j];
				if(lcp(sa[i],sa[i]+l)/l>=ansci-1){
					ansi=sa[i];
					ansl=l;
					break;
				}
			}
			if(ansi!=-1)break;
		}
		printf("Case %d: ",cc);
		for(int i=ansi;i<ansi+ansci*ansl;i++)
			printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}
