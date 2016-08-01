#include<bits/stdc++.h>
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof(x))
const int N=100005;
using namespace std;
const double eps=1e-8;
int n;
vector<int> g;
int px[1005],py[1005];
double dis[1005][1005];
void init(){
    for(int i=1;i<=n;i++) 
        for(int j=i+1;j<=n;j++)
            dis[i][j]=sqrt((px[i]-px[j])*(px[i]-px[j]) + (py[i]-py[j])*(py[i]-py[j]));
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            dis[i][j]=dis[j][i];
}

inline int cross(int i1,int i2,int i3) {
    int v1x=px[i2]-px[i1],v1y=py[i2]-py[i1];
    int v2x=px[i3]-px[i1],v2y=py[i3]-py[i1];
    return v1x*v2y-v1y*v2x;
}

bool check() {
    for(int i=3;i<=n;i++)
        if(fabs(cross(1,2,i))>0)
            return false;
    return true;
}
int globalp1;
bool cmp(int i1,int i2){
    return dis[globalp1,i1]<dis[globalp1,i2];
}


int main(){ 
    int tc;
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&px[i],&py[i]);
        printf("Case %d: ",tt);
        if(check()) {
            printf("No Solution\n");
            continue;
        }
        init();

        double ans=1e50;
        for(int p1=n;p1>=1;p1--){
            g.clear(); 
            for(int i=1;i<=n;i++){
                if(i!=p1 && dis[p1][i]<=ans/2.0+eps)
                    g.push_back(i);
            }
            globalp1=p1;
            sort(g.begin(),g.end(),cmp);
            int len=g.size();
            for(int i=0;i<len;i++)
                for(int j=i+1;j<len;j++) {
                    if(fabs(cross(p1,g[i],g[j]))<eps)continue;
                    double tmp=dis[g[i]][g[j]] + dis[p1][g[i]] + dis[p1][g[j]];
                    if(tmp<ans){
                        ans=tmp;
                        while(len>0 && dis[p1][g[len-1]]>ans/2.0+eps)len--;
                    }
                }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
