#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=305;
const int T=200005;


int pn,rn,tn;
int tp[T],tr[T];
bool ter[N];
int untercnt=0;
int res[N],need[N][N],req[N][N];
int tmpres[N],tmpneed[N][N];
bool tmpter[N];

bool terminate(int pi) {
	for(int j=1;j<=rn;j++)
		if(need[pi][j])return false;
	return true;
}

bool canter(int pi) {
	for(int j=1;j<=rn;j++)
		if(tmpneed[pi][j]>tmpres[j])return false;
	return true;
}
queue<int> q;
bool check() {
	memcpy(tmpres,res,sizeof(res));
	memcpy(tmpneed,need,sizeof(need));
	memcpy(tmpter,ter,sizeof(ter));
	
	int cnt=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=pn;i++) 
		if(!tmpter[i])
			if(canter(i))
				q.push(i);
	while(!q.empty()) {
		while(!q.empty()){
			int now=q.front();
			q.pop();
			cnt++;
			tmpter[now]=true;
			for(int j=1;j<=rn;j++)
				tmpres[j]+=req[now][j]-need[now][j];
		}
		for(int i=1;i<=pn;i++) 
			if(!tmpter[i])
				if(canter(i))
					q.push(i);
	}
	if(cnt<untercnt)return false;
	return true;
}

void goup(int now,int tt) {
	for(int t=now;t>tt;t--){
		if(ter[tp[t]])continue;
		res[tr[t]]++;
		need[tp[t]][tr[t]]++;
	}
}
void godown(int now,int tt){
	for(int t=now+1;t<=tt;t++) {
		if(ter[tp[t]])continue;
		res[tr[t]]--;
		need[tp[t]][tr[t]]--;
	}
}

int main(){
	freopen("A.in","r",stdin);
	scanf("%d%d%d",&pn,&rn,&tn);
	untercnt=pn;
	for(int i=1;i<=rn;i++)
		scanf("%d",&res[i]);
	for(int i=1;i<=pn;i++)
		for(int j=1;j<=rn;j++) {
			scanf("%d",&req[i][j]);
			if(req[i][j]>res[j]){
				printf("0\n");
				return 0;
			}
			need[i][j]=req[i][j];
		}
	ms(ter,0);
	for(int i=1;i<=tn;i++){
		scanf("%d%d",&tp[i],&tr[i]);
		need[tp[i]][tr[i]]--;
		res[tr[i]]--;		
		if(terminate(tp[i])){
			ter[tp[i]]=true;
			untercnt--;
			for(int j=1;j<=rn;j++)
				res[j]+=req[tp[i]][j];
		}
	}
	if(check()){
		printf("-1\n");
		return 0;
	}
	int l=0,r=tn,now=tn;
	while(l<r) {
		int mid=(l+r)/2;
		if(mid<now) goup(now,mid);
		else if(mid>now) godown(now,mid);
		now=mid;
		if(check())
			l=mid+1;
		else
			r=mid;
	}
	printf("%d\n",l);
	return 0;
}





