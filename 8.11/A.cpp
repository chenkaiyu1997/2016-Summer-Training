#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;

const int N=1005;
int cnt[N],cnt2[N];

struct point{
    int u,v,ha;
}a[N],b[N];

int rnk[1002005];
int n,m;

bool cmp2(const point& A,const point& B) {
    return rnk[A.ha]<rnk[B.ha];
}

bool check(){
    for(int i=2;i<=n;i++)
        if(!cmp2(a[i-1],a[i]))
            return false;
    return true;
}

bool check1(int maxn) {
    for(int i=1;i<=maxn;i++)
        if(cnt[i]!=cnt2[i])
            return false;
    return true;
}

int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int maxn=0;
        ms(cnt,0);
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].u);
            maxn=max(maxn,a[i].u);
            a[i].v=++cnt[a[i].u];
            a[i].ha=a[i].u * 1001 + a[i].v;
        }
        ms(cnt2,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i].u);
            maxn=max(maxn,b[i].u);
            b[i].v=++cnt2[b[i].u];
            rnk[b[i].u*1001 + b[i].v]=i;
        }

        int l,r;
        if(!check1(maxn)){
            printf("No\n");
            for(int i=1;i<=m;i++) {
                scanf("%d%d",&l,&r);
            }
            continue;
        }
            
        for(int i=1;i<=m;i++) {
            scanf("%d%d",&l,&r);
            sort(a+l,a+r+1,cmp2);
        }
        if(check())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
