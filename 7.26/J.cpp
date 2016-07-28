#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[100005],y[100005];
bool vis[200005];
int main(){
  int tc;
  scanf("%d",&tc);
  while(tc--){
      scanf("%d%d",&n,&m);
      memset(vis,0,sizeof(vis));
      for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    bool flag=false;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++) {
            int tmp=fabs(x[i]-x[j]) + fabs(y[i]-y[j]);
            if(vis[tmp]){
                flag=true;
                goto l1;
            }
            else
                vis[tmp]=true;
        }
    l1:if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    }
    return 0;
}
