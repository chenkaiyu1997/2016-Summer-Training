#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
int v[100005];
int n,m,q;
int main() {
    int tc;
    cin>>tc;
    while(tc--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d%*d%*d",&v[i]);
        sort(v+1,v+n+1);
        scanf("%d",&q);
        int t,k;
        for(int i=1;i<=q;i++){
            scanf("%d%d",&t,&k);
            printf("%.3lf\n",sqrt(2.0*m*t + 1.0*v[k]*v[k]));
        }
    }
    return 0;
}
