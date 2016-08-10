#include<bits/stdc++.h> 
#define lson l , mid , rt<<1
#define rson mid + 1 , r , rt << 1 | 1
using namespace std;

const int N=500005;
struct point {
	int x,y,id;
}a[N];

struct event {
	int pos,ty,l,r;
}e[N*3];
int en,n;
int u[N],d[N],l[N];
int t[200005];

bool cmp1(const point &A,const point &B){
	return A.x<B.x || (A.x==B.x && A.y<B.y);
}

bool cmp2(const point &A,const point &B){
	return A.y<B.y || (A.y==B.y && A.x<B.x);
}

bool cmp3(const point &A,const point &B){
	return A.id < B.id;
}


bool cmpeve(const event &A,const event &B){
	return A.pos<B.pos || (A.pos==B.pos && A.ty<B.ty);
}


void add(int c,int L,int R,int l,int r,int rt) {
//	printf("add%d %d %d %d %d %d\n",c,L,R,l,r,rt);

	if(L<=l && r<=R){
		t[rt]+=c;
	//	printf("addon%d %d %d %d %d %d\n",c,L,R,l,r,rt);
		return;
	}
	int mid=(l+r)/2;
	if(L <= mid) add(c,L,R,lson);
	if(R > mid) add(c,L,R,rson);
}
bool query(int pos,int l,int r,int rt){
//	printf("query%d %d %d %d %d\n",pos,l,r,rt,t[rt]);
	
	if(t[rt] > 0) return true;
	if(l==r)
		return t[rt];
	int mid = ( l + r ) / 2 ;
	if (pos <= mid) return query(pos , lson);
	return query(pos , rson);
}

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	while(scanf("%d",&n),n!=0){
		memset(e,0,sizeof(e));
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].id=i;
		}
		sort(a+1,a+n+1,cmp1);
		a[0].x=0;
		a[n+1].x=50001;
		for(int i=1;i<=n+1;++i){
			if(a[i].x==a[i-1].x){
				u[a[i-1].id]=a[i].id;
				d[a[i].id]=a[i-1].id;
			}
			else{
				u[a[i-1].id]=n+1;
				d[a[i].id] = 0;
			}
		}

		sort(a+1,a+n+1,cmp2);
		a[0].y=0;
		a[n+1].y=50001;
		for(int i=1;i<=n;++i){
			if(a[i].y==a[i-1].y)
				l[a[i].id]=a[i-1].id;
			else
				l[a[i].id]=0;
		}


		sort(a+1,a+n+1,cmp3);
		en=0;
		a[0].x=0;a[0].y=0;
		a[n+1].x=50001;a[n+1].y=50001;

		for(int i=1;i<=n;++i){
			e[++en].pos=a[i].y;
			e[en].ty=1;
			e[en].l=a[i].x;

			if(a[i].x-a[l[i]].x<=1)continue;
			if(a[d[i]].y == a[u[i]].y)continue;

			e[++en].l=a[l[i]].x;
			e[en].r=a[i].x;
			e[en].ty=2;
			e[en].pos=a[d[i]].y;

			//eliminate
			++en;
			e[en].l=e[en-1].l;
			e[en].r=e[en-1].r;
			e[en].ty=0;
			e[en].pos=a[u[i]].y;

		}

		sort(e+1,e+1+en,cmpeve);

		for(int i=1;i<=en;++i){
			
//			printf("%d %d %d %d\n",e[i].l,e[i].r,e[i].pos,e[i].ty);
			if(e[i].ty==0)
				add(-1,e[i].l+1,e[i].r-1,1,50000,1);
			else if(e[i].ty==2)
				add(1,e[i].l+1,e[i].r-1,1,50000,1);
			else if(query(e[i].l,1,50000,1)){
				printf("NO\n");
				goto l1;
			}
		}

		printf("YES\n");
l1: 	;
	}
	return 0;
}
	

