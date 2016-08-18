#include<bits/stdc++.h> 
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x) & (-(x)))
#define lson l , mid , rt<<1
#define rson mid+1 , r ,rt<<1|1
using namespace std;
const int N=100005;
const int N2=200005;
const int inf=(1e9)+7;


struct edge{
	int v,nxt;
}e[N2];
struct event{
	int l,r;
	int y,ty;
	int w;
}ev[N2*4];
int tmax[N2*4],tc[N2*4];
int evcnt;

int b[N],dis[N],st;
int en;
int fa[N][20];
int n,m;
int L[N],R[N];
int ss[N],ssum;

void addedge(int u,int v){
	e[en].v=v;
	e[en].nxt=b[u];
	b[u]=en++;
}

void dfs(int now){
	L[now]=++st;
	for(int i=b[now];i!=-1;i=e[i].nxt)
		if(dis[e[i].v]==0){
			dis[e[i].v]=dis[now]+1;
			fa[e[i].v][0]=now;
			dfs(e[i].v);
		}
	R[now]=++st;
}


void da(){
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
}

int lca(int u,int v,int &typ){
	if(dis[v]>dis[u])swap(u,v);
	for(int j=18;j>=0;j--)
		if(dis[fa[u][j]] > dis[v])
			u=fa[u][j];
	if(fa[u][0]==v){
		typ=2;
		return u;
	}
	u=fa[u][0];
	for(int j=18;j>=0;j--)
		if(fa[u][j] != fa[v][j]){
			u=fa[u][j];
			v=fa[v][j];
		}
	typ=1;
	return fa[u][0];
}

bool cmp(const event& A,const event& B){
	return A.y<B.y || (A.y==B.y && A.ty<B.ty);
}
void addrec(int xl,int xr,int yl,int yr,int w){
	//if(w!=2  && w!=4)return;	
	//printf("addrec%d %d %d %d %d\n",xl,xr,yl,yr,w);
	evcnt++;
	ev[evcnt].l=xl;ev[evcnt].r=xr;
	ev[evcnt].ty=1;ev[evcnt].y=yl;
	ev[evcnt].w=w;

	evcnt++;
	ev[evcnt].l=xl;ev[evcnt].r=xr;
	ev[evcnt].ty=2;ev[evcnt].y=yr;
	ev[evcnt].w=-w;
}

void pushup(int rt){
	tmax[rt]=max(tmax[rt<<1]+tc[rt<<1],tmax[rt<<1|1]+tc[rt<<1|1]);
}

void add(int w,int dyhl,int dyhr,int l,int r,int rt){
//	if(rt==1)printf("add %d %d %d %d %d %d\n",w,dyhl,dyhr,l,r,rt);
	if(dyhl<=l && r<=dyhr){
		tc[rt]+=w;
		return;
	}
	int mid=(l+r)/2;
	if(dyhl<=mid)add(w,dyhl,dyhr,lson);
	if(dyhr>mid)add(w,dyhl,dyhr,rson);
	pushup(rt);
}

int main(){ 
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int tto;
	scanf("%d",&tto);
	for(int tt=1;tt<=tto;tt++){
		en=0;
		ms(b,-1);
		scanf("%d%d",&n,&m);
		int u,v,w;
		if(n==1){
			int ans=0;
			for(int i=1;i<=m;i++){
				scanf("%d %d %d",&u,&v,&w);
				ans+=w;
			}
			printf("Case #%d: %d\n",tt,ans);	
			continue;
		}
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		st=0;
		ms(fa,0);ms(dis,0);
		dis[1]=1;
		dfs(1);
		da();
		ms(ss,0);ssum=0;evcnt=0;
		int len=2*n,typ;

/*		for(int i=1;i<=n;i++){
			printf("%d%d ",L[i],R[i]);
		}
		printf("\n");*/
		int ssum=0;
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&u,&v,&w);
			if(u==v){
				ssum+=w;
				ss[u]+=w;
				continue;
			}
			int k=lca(u,v,typ);
			if(typ==1)
				addrec(L[u],R[u],L[v],R[v],w);
			else if(typ==2){
				if(dis[u]<dis[v]){
					addrec(1,L[k]-1,L[v],R[v],w);
					addrec(R[k]+1,len,L[v],R[v],w);
				}
				else{
					addrec(L[u],R[u],1,L[k]-1,w);
					addrec(L[u],R[u],R[k]+1,len,w);
				}
			}
		}
		for(int i=1;i<=n;i++)
			if(ss[i]!=0){
				for(int j=b[i];j!=-1;j=e[j].nxt){
					int tmpl=L[e[j].v],tmpr=R[e[j].v];
					if(e[j].v!=fa[i][0])
						addrec(tmpl,tmpr,tmpl,tmpr,-ss[i]);
					else{
						tmpl=L[i];tmpr=R[i];
						addrec(1,tmpl-1,1,tmpl-1,-ss[i]);
						addrec(1,tmpl-1,tmpr+1,len,-ss[i]);
						addrec(tmpr+1,len,1,tmpl-1,-ss[i]);
						addrec(tmpr+1,len,tmpr+1,len,-ss[i]);
					}
				}
			}
		sort(1+ev,1+evcnt+ev,cmp);
		ms(tmax,0);ms(tc,0);
		int ans=-inf;
		int evi=1;
		for(int i=1;i<=len;i++){
			for(;ev[evi].y==i && ev[evi].ty==1;evi++)
				add(ev[evi].w,ev[evi].l,ev[evi].r,1,len,1);
			ans=max(ans,tmax[1]+tc[1]);			
			for(;ev[evi].y==i && ev[evi].ty==2;evi++)
				add(ev[evi].w,ev[evi].l,ev[evi].r,1,len,1);				
		}
		printf("Case #%d: %d\n",tt,ssum+ans);
	}
	return 0;
}
