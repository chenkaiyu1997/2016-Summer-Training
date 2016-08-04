#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define lb(x) ((x)&(-(x)))
using namespace std;
const int mod=(1e7)+7;
char s1[10005],s2[10005];
int r1[10005],r2[10005];
vector<int> a1,a2;
int sh1,sh2,h;

bool rointing(int len) {
	int l=0,r=len;
	int tmpsh1=sh1;
	for(int ci=1;ci<=len+1;ci++) {
		if(tmpsh1==sh2)return true;
		r=r==len?0:r+1;
		tmpsh1=(tmpsh1*26 +r1[r] + mod - h*r1[l]) % mod;
		l++;
	}
	return false;
}


int main() {
	freopen("A.in","r",stdin);
	freopen("Astd.out","w",stdout);
	
    while (scanf("%s", s1) != EOF) {
		scanf("%s",s2);
		int len=strlen(s1);
		for(int i=0;i<len;i++) {
			r1[i]=s1[i]-'a';
			r2[i]=s2[i]-'a';
		}
		a1.clear();a2.clear();
		for(int i=0;i<26;i++){
			a1.push_back(0);
			a2.push_back(0);
		}
		h=1;sh1=0;sh2=0;
		for(int pos=0;pos<len;pos++){
			h=h*26%mod;

			sh1=(sh1*26+r1[pos])%mod;
			sh2=(sh2*26+r2[pos])%mod;
			a1[r1[pos]]++;a2[r2[pos]]++;
			if(a1!=a2){
				printf("0");
				continue;
			}
			if(rointing(pos))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
	return 0;
}
