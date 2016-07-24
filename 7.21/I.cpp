#include<bits/stdc++.h>
using namespace std;
int a[105];
int gcd(int A,int B){
    if(B==0)return A;
    return gcd(B,A%B);
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--){
            memset(a,0,sizeof(a));
            int n,m;
            scanf("%d%d",&n,&m);
            int x,y;
            for(int i=1;i<=m;i++){
                cin>>x>>y;
                a[x]=y;
            }
            int sum=0,req=0;
            for(int i=n;i>=3;i--){
                if(a[i])req=a[i];
                else a[i]=req;
                sum+=a[i];
            }
            int sum0=0;
            if(a[1]){
                if(a[2])
                    sum0=a[1]+a[2];
                else
                    sum0=a[1]+a[1];
            }
            else{
                if(a[2])
                    sum0=100+a[2];
                else
                    sum0=200;
            }
            sum+=sum0;
            int g=gcd(sum0,sum);
            printf("%d/%d\n",sum0/g,sum/g);
    }
    return 0;
}
