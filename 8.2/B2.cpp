#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x)&(-(x)))
using namespace std;
const ll mod=(1e15)+7;
char s1[10005],s2[10005];
int r1[10005],r2[10005];
vector<int> a1,a2;
ll sh1,sh2,h;
int m;

bool rolling(register int len,ll &roll,ll &seg2) {
	register int l=0,r=len;
	register ll tmpsh1=sh1;
	seg2=0;
	roll=1;
	for(register int ci=1;ci<=len+1;ci++) {
		if(tmpsh1==sh2)return true;
		r=r==len?0:r+1;
		seg2=(seg2*m + r1[r]);
		if(seg2>mod)seg2-=mod;
		roll=roll*m;
		if(roll>mod)roll-=mod;
		tmpsh1=(tmpsh1*m +r1[r] + mod - h*r1[l]);
		while(tmpsh1>mod)tmpsh1-=mod;
		l++;
	}
	return false;
}


int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
    while (scanf("%s", s1) != EOF) {
		scanf("%s",s2);
		int len=strlen(s1);
		m=0;
		for(int i=0;i<len;i++) {
			r1[i]=s1[i]-'a';
			r2[i]=s2[i]-'a';
			m=max(m,r1[i]);
			m=max(m,r2[i]);
		}
		m++;
		a1.clear();a2.clear();
		for(int i=0;i<m;i++){
			a1.push_back(0);
			a2.push_back(0);
		}
		h=1;sh1=0;sh2=0;
		ll seg1,seg2=-1;
		ll seg12,seg22=-1;
		ll tmpseg=-1,tmpseg2=-1;
		ll rolled;
		for(int pos=0;pos<len;pos++){
			h=h*m;
			if(h>mod)h-=mod;
			if(seg2!=-1) {
				seg1=(sh2+mod-seg2);
				while(seg1>mod)seg1-=mod;
				
				seg12=(sh2+mod-seg22);
				while(seg12>mod)seg12-=mod;
				
				seg2= (seg2 + r1[pos] * rolled);
				while(seg2>mod)seg2-=mod;
				
				seg22 = (seg22*m + r1[pos]);
				while(seg22>mod)seg22-=mod;
				
				rolled=(rolled*m);
				if(rolled>mod) rolled-=mod;
				tmpseg=(seg1*m + seg2);
				while(tmpseg>mod)tmpseg-=mod;
				tmpseg2 = (seg12*m + seg22);
				while(tmpseg2>mod)tmpseg2-=mod;
			}
			sh1=(sh1*m+r1[pos]);if(sh1>mod)sh1-=mod;
			sh2=(sh2*m+r2[pos]);if(sh2>mod)sh2-=mod;
			a1[r1[pos]]++;a2[r2[pos]]++;
			if(a1!=a2){
				printf("0");
				continue;
			}
			if(tmpseg==sh2 || tmpseg2==sh2){
				//printf("0");
				printf("1");
				continue;
			}
			else{
				if(rolling(pos,rolled,seg2)){
					seg22=seg2;
					printf("1");
				}
				else
					printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}
