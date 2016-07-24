#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct point{
    int px;
    int py;
    friend bool operator<(const point &,const point &);
};

bool operator<(const point& A,const point& B){
    return A.px<B.px || (A.px==B.px && A.py<B.py);
}
map<point,int> a;


int gcd(int A,int B){
    if(B==0)return A;
    return gcd(B,A%B);
}


ll mod=(1e9)+7;
ll mi2[1005],mi2j1[1005];
void init() {
    mi2[0]=1;
    for(int i=1;i<=1002;i++){
        mi2[i]=mi2[i-1]*2;
        mi2j1[i]=(mi2[i]-1)%mod;
        mi2[i]%=mod;
    }
}

int x[1005],y[1005];
int main() {
    int tc;
    init();
    scanf("%d",&tc);
    while(tc--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&x[i],&y[i]);
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            a.clear();
            int chong=0;
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                int vx=x[j]-x[i],vy=y[j]-y[i];
                if(vx==0 && vy==0)
                {
                    if(j>i)chong++;
                    continue;
                }
                if(vx<0 || (vx==0 && vy<0))continue;
                
                if(vx==0)vy=1;
                else if(vy==0)vx=1;
                else {
                    int g=gcd(fabs(vx),fabs(vy));
                    vx/=g;vy/=g;
                }
                
                point tmp;tmp.px=vx;tmp.py=vy;
                if(a.count(tmp)>0)a[tmp]++;
                else a[tmp]=1;
            }
            for(map<point,int>::iterator it=a.begin();it!=a.end();it++){
                int ge=it->second+chong;
                ans=(ans+mi2j1[ge]-mi2j1[chong])%mod;
            }
            ans=(ans+mi2j1[chong])%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
