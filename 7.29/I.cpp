#include<bits/stdc++.h>
#include<unordered_map>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N=45;
const long long inf=(1e9)+7;


int n,m;
int per[N];
vector<int> e[N];
struct node {
	bitset<41> mask;
	int v,d;
	node() {v=d=0;}
	bool operator < (const node &B) const {
		return d>B.d;
	}
	bool operator == (const node &B) const{
		return v==B.v && mask==B.mask;
	}
};

struct HASH {
	size_t operator () (const node &B )const {
		size_t h=B.v;
		for(int i=0;i<40;i++)
			h=h*inf + B.mask[i];
		return h;
	}
};

priority_queue <node> q;
unordered_map <node,bool,HASH> my;

int dijkstra(){
	//printf("%d %d\n",p,tans);
	node s;
	s.mask.reset();
	s.d=per[1];s.v=1;s.mask[1]=1;
	for(auto v:e[1]) {
		s.d+=per[v];
		s.mask[v]=1;
	}
	q.push(s);
	node now,tmp;
	while(!q.empty()) {
		now=q.top();q.pop();
		my[now]=1;
		if(now.v==n)return now.d;
		for(auto v:e[now.v]) {
			tmp=now;
			tmp.v=v;
			for(auto v2:e[v])
				if(tmp.mask[v2]==0) {
					tmp.mask[v2]=1;
					tmp.d+=per[v2];
				}			
			if(!my.count(tmp))
				q.push(tmp);
		}
	}
	return -1;
}
	
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&per[i]);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	printf("%d\n",dijkstra());
	return 0;
}

