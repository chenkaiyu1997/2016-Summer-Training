#include <bits/stdc++.h>
#define ms(x,y) memset(x,y,sizeof(x))
#define ll long long
#define lb(x) ((x)&(-(x)))
using namespace std;
const int mod = 1e9 + 7;
const int N=50005;
int n;

struct node{
    int v;
    int id;
}a[N];

bool cmp(const node& A,const node& B) {
    return A.v<B.v;
}

int b[N];
int ld[N],rd[N],ls[N],lu[N],ru[N],rs[N];
int c[N],rnk;

int query(int pos) {
    int tmp=0;
    while(pos) {
        tmp+=c[pos];
        pos-=lb(pos);
    }
    return tmp;
}

void add(int pos) {
    while(pos<=rnk) {
        c[pos]++;
        pos+=lb(pos);
    }
}

int main() {

    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i){
            a[i].id=i;
            scanf("%d", &a[i].v);
        }
        sort(a+1,a+n+1,cmp);
        rnk=1;
        b[a[1].id]=rnk;
        for(int i=2;i<=n;i++){
            if(a[i].v==a[i-1].v)
                b[a[i].id]=rnk;
            else
                b[a[i].id]=++rnk;
        }

        //left
        ms(c,0);
        ms(ls,0);
        for(int i=1;i<=n;i++) {
            ld[i]=query(b[i]-1);
            lu[i]=i-1-ls[b[i]] - ld[i];
            ls[b[i]]++;
            add(b[i]);
        }


        //right
        ms(c,0);
        ms(rs,0);
        for(int i=n;i>=1;i--) {
            rd[i]=query(b[i]-1);
            ru[i]=n-i - rs[b[i]] - rd[i];
            rs[b[i]]++;
            add(b[i]);
        }
        ll ans1=0,ans2=0;
        
        for(int i=1;i<=n;i++){
            ans1+=ru[i];    
            ans2+=rd[i];
        }
        ll ans=ans1*ans2;

        for(int i=1;i<=n;i++) {
            ans-=(ll)rd[i] * (ll)ld[i];
            ans-=(ll)lu[i] * (ll)ld[i];
            ans-=(ll)ru[i] * (ll)rd[i];
            ans-=(ll)ru[i] * (ll)lu[i];
        }

        cout<<ans<<endl;
    }
    return 0;
}
