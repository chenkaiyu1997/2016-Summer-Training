#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=5000006;
const int inf=2000000000;
char w[N],p[N];
int nxt[N];
int l[N],r[N];

int main()
{

	while(w[0]='\0',scanf("%s",w),w[0]!='\0') {
		scanf("%s",p);
		int lenw=strlen(w);
		int lenp=strlen(p);
		for(int tp=lenp;tp>=1;tp--)p[tp]=p[tp-1];
		int i,j=-1;nxt[0]=-1;
		for(i=0;i<lenw;) {
			if(j==-1 || w[i]==w[j]) {
				i++;j++;
				nxt[i]=j;
			}
			else
				j=nxt[j];
		}

		for(i=0;i<=lenp+1;i++){
			l[i]=i-1;
			r[i]=i+1;
		}
		for(i=1,j=0;i<=lenp;) {
			if(j==-1 || p[i]==w[j]) {
				i=r[i];j++;
				if(j==lenw) {
					int k=i,cnt=0;
					while(cnt<lenw){
						k=l[k];
						cnt++;
					}
					k=l[k];
					r[k]=i;l[i]=k;
					j=0;
					cnt=0;i=k;
					while(cnt<lenw && i>=1){
						i=l[i];
						cnt++;
					}
					if(i<1)i=r[0];
				}
			}
			else
				j=nxt[j];
		}
		for(int i=r[0];i<=lenp;i=r[i])
			printf("%c",p[i]);
		printf("\n");
	}
	return 0;
}
