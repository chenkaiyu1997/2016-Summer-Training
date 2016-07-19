#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
using namespace std;
char str[105];

int getnumber(int u,int &p) {
	int num=0,fuhao=1;
	if(str[p]=='-'){fuhao=-1;p++;}
	while((str[p]<='9' && str[p]>='0') || str[p]=='?'){
		if(str[p]=='?'){
			if(num==0 && u==0 && ((str[p+1]>='0' && str[p+1]<='9') || str[p+1]=='?'))return -19970410;
			num=num*10+u;
		}
		else
			num=num*10+str[p]-'0';
		p++;
	}
	if(num==0 && fuhao==-1)return -19970410;
	return num*fuhao;
}


bool work(int u) {
	int len=strlen(str);
	for(int j=0;j<len;j++)
		if(str[j]=='0'+u)
			return false;
	int p=0;
	int x1=getnumber(u,p);
	if(x1==-19970410)return false;
	char oper=str[p++];
	int x2=getnumber(u,p);
	if(x2==-19970410)return false;
	p++;
	int y=getnumber(u,p);
	if(y==-19970410) return false;
	if(oper=='+')
		if(x1+x2==y)
			return true;
	if(oper=='*')
		if((ll)x1*(ll)x2==(ll)y)
			return true;
	if(oper=='-')
		if(x1-x2==y)
			return true;
	return false;
}
	
int main()
{

	int tc;
	scanf("%d\n",&tc);
	while(tc--){
		scanf("%s",str);
		bool flag=false;
		for(int i=0;i<=9;i++)
			if(work(i)) {
				printf("%d",i);
				flag=true;
				break;
			}
		if(!flag)printf("-1");
		if(tc!=0)
			printf("\n");
	}

	return 0;
}

