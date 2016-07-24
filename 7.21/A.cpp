#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100005];
ll gcd(ll A,ll B){
    if(B==0)return A;
    return gcd(B,A%B);
}
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--){
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        ll sum1=0,sum2=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum1+=a[i]*a[i];
            sum2+=fabs(a[i]);
        }
        ll nn=n;
        sum2=sum2*sum2;
        sum1=sum1*nn-sum2;
        if(sum1==0)
            printf("0/1\n");
        else{ll g=gcd(nn,sum1);
        cout<<sum1/g<<"/"<<nn/g<<endl;}
    }
    return 0;
}
