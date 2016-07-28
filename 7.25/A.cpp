#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
const int N=1000005;
bool visi[N],visj[N];
ll vi[N],vj[N];

int main(){
	freopen("adjustment.in","r",stdin);
	freopen("adjustment.out","w",stdout);
	ms(visi,0);
	ms(visj,0);
	ll itot=0,jtot=0;
	ll inum=0,jnum=0;
	int n,q,nu;
	char ch[2];
	scanf("%d%d",&n,&q);

	for(int i=1;i<=n;i++)
		vi[i]=vj[i]=(ll)(n)*(ll)(2*i+n+1)/(ll)2;

	for(int qq=1;qq<=q;qq++) {
		scanf("%s",ch);
		scanf("%d",&nu);
		if(ch[0]=='R'){
			if(visi[nu])
				cout<<0<<endl;
			else{
				cout<<vi[nu]-jtot-jnum*nu<<endl;
				visi[nu]=true;
				inum++;
				itot+=nu;
			}
		}
		else{
			if(visj[nu])
				cout<<0<<endl;
			else{
				cout<<vj[nu]-itot-inum*nu<<endl;
				visj[nu]=true;
				jnum++;
				jtot+=nu;
			}
		}
	}
	return 0;
}
