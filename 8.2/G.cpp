#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x)&(-(x)))
using namespace std;
const int mod = 1e9 + 7;
ll f[20][15000][2][2];
int a[20];
bool ok[15000][10];
int n,lim;


ll dfs(int p,int s,int upper,int quan0) {
    if(p==n+1)return 1;
    if(f[p][s][upper][quan0]!=-1) return f[p][s][upper][quan0];
    ll tmpans=0;
    int r=upper?a[p]:9;
    for(int i=0;i<=r;i++) {
        if(ok[s][i])
            tmpans+=dfs(p+1,s*11%lim+((i!=0)?(i):(quan0?10:0)),upper && i==r,quan0 && i==0);
    }
    return f[p][s][upper][quan0]=tmpans;
}


bool check(int s,int p,int k) {
    while(k--) {
        int tmp=s%11;
        if(tmp==p)return false;
        s/=11;
    }
    return true;
}


void init(int k) {
    ms(ok,0);
    lim=1;
    for(int i=1;i<=k;i++)
        lim*=11;
    for(int i=0;i<lim;i++) {
        for(int j=0;j<=9;j++)
            if(check(i,j,k))
                ok[i][j]=true;
    }
}

int main() {

    long long ls,rs;
    int k;
    int tmp[20];
    while (cin>>ls>>rs>>k){
        init(k-1);
        ll ans1=0;
        ls--;
        n=0;
        while(ls){
            tmp[++n]=ls%10;
            ls/=10;
        }
        for(int i=1;i<=n;i++)
            a[i]=tmp[n+1-i];
        ms(f,-1);
        ans1=dfs(1,lim-1,1,1);

            
        ll ans2=0;
        n=0;
        while(rs) {
            tmp[++n]=rs%10;
            rs/=10;
        }
        for(int i=1;i<=n;i++)
            a[i]=tmp[n+1-i];
        ms(f,-1);
        ans2=dfs(1,lim-1,1,1);
        cout<<ans2-ans1<<endl;
    }
    return 0;
}
