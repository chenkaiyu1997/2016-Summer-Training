#include<bits/stdc++.h> 
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x) & (-(x)))
using namespace std;
const int N=100005;
const int inf=19961211;
int r[N],rnk[N],lcp[N];
int tsa[N],b[N],wx[N],sa[N],xx[N];
int n,m;
char s[N];

bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b] && r[a+l]==r[b+l];
}

void calclcp(){
	int i,j,k=0;
	for(i=0;i<n;lcp[rnk[i++]]=k)
		for(k?k--:k,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}


void da(){
	int i,j,p,*x=wx,*y=tsa,*t;
	for(i=0;i<m;i++)b[i]=0;
	for(i=0;i<n;i++)b[x[i]=r[i]]++;
	for(i=1;i<m;i++)b[i]+=b[i-1];
	for(i=n-1;i>=0;i--) sa[--b[x[i]]]=i;
	for(j=1,p=1;p<n;j*=2,m=p){
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<m;i++)b[i]=0;
		for(i=0;i<n;i++)b[x[i]]++;
		for(i=1;i<m;i++)b[i]+=b[i-1];
		for(i=n-1;i>=0;i--) sa[--b[x[y[i]]]]=y[i];
		t=x;x=y;y=t;x[sa[0]]=0;
		for(i=1,p=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
	}
	for(i=0;i<n;i++)
		rnk[i]=x[i];
}

int main(){ 
	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	int tto;
	scanf("%d",&tto);
	char ch[2];
	for(int tt=1;tt<=tto;tt++){
		scanf("%s",ch);
		scanf("%s",s);
		int len=strlen(s);
		int pre=2*inf;
		for(int i=len-1;i>=0;i--){
			if(s[i]==ch[0])
				pre=i;
			xx[i]=pre-i;
		}
		n=len+1;m=27;
		for(int i=0;i<len;i++)r[i]=s[i]-'a'+1;
		r[len]=0;
		da();
		calclcp();
	/*	for(int i=0;i<n;i++)
			printf("%d ",sa[i]);
		cout<<endl;
		for(int i=1;i<=n;i++)
			printf("lcp[%d]=%d ",i,lcp[i]);*/

		ll ans=0;
		if(xx[sa[1]]<inf)
			ans=len-sa[1]-xx[sa[1]];
		for(int i=2;i<=len;i++){
			if(xx[sa[i]]>inf)continue;
			if(xx[sa[i]]<lcp[i])
				ans+=len-sa[i]-lcp[i];
			else
				ans+=len-sa[i]-xx[sa[i]];
		}
		printf("Case #%d: ",tt);
		cout<<ans<<endl;
	}
	return 0;
}
