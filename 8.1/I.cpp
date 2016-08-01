#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int inf=(1e9)+7;
struct node{

    int a,b;
}g[100005];

bool cmp(const node& A,const node& B) {
    return A.a<B.a;
}


int ma[100005];
int main() {
    int tc;
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++) {
        int n;
        int x,y;
        int a=0,b=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&g[i].a,&g[i].b);
        sort(g+1,g+1+n,cmp);
        ms(ma,0);
        for(int i=n;i>=1;i--)
            ma[i]=max(ma[i+1],g[i].b);
        int ma2=0;
        int ans=inf;
        g[0].a=0;
        for(int i=0;i<=n;i++){
            ma2=max(ma2,g[i].a);
            ans=min(ans,ma2+ma[i+1]);
        }
        printf("Case %d: ",tt);
        printf("%d\n",ans);
    }
    return 0;
}
