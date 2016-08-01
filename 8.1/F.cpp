#include<bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
using namespace std;
const int inf=(1e9)+7;
struct edge{
    int v,w,nxt;
}e[2005];
int en;
int b[25];
void addedge(int u,int v,int w) {
    e[en].v=v;
    e[en].w=w;
    e[en].nxt=b[u];
    b[u]=en++;
}
int dis[25];
int n,m;
queue<int> q;
bool bfs() {
    while(!q.empty())q.pop();
    ms(dis,-1);
    q.push(1);
    dis[1]=0;
    while(!q.empty()) {
        int now=q.front();
        q.pop();
        for(int i=b[now];i!=-1;i=e[i].nxt)
            if(e[i].w>0 && dis[e[i].v]==-1) {
                dis[e[i].v]=dis[now]+1;
                q.push(e[i].v);
            }
    }
    if(dis[n]==-1)return false;
    return true;
}

int dfs(int p,int lim) {
    if(p==n)return lim;
    int tmp,flow=0;
    for(int i=b[p];i!=-1;i=e[i].nxt)
        if(e[i].w>0 && dis[e[i].v]==dis[p]+1) {
            tmp=dfs(e[i].v,min(lim-flow,e[i].w));
            if(tmp>0) {
                e[i].w-=tmp;
                e[i^1].w+=tmp;
                flow+=tmp;
                if(flow==lim)return flow;
            }
            else
                dis[e[i].v]=-1;
        }
    return flow;
}



int main(){
    int tc;
    scanf("%d",&tc);
    for(int tt=1;tt<=tc;tt++) {
        scanf("%d%d",&n,&m);
        en=0;
        ms(b,-1);
        int u,v,w;
        for(int i=1;i<=m;i++) {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,0);
        }
        int flow=0;
        while(bfs())
            flow+=dfs(1,inf);
        printf("Case %d: %d\n",tt,flow);
    }
    return 0;
}
