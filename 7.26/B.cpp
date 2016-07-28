#include<bits/stdc++.h>
using namespace std;
double c[1005];
int n;
int main(){
  while (scanf("%d", &n) != EOF) {
    for(int i = 1; i <= n; i++) scanf("%lf", &c[i]);
    if(n==1){
        printf("%.6lf\n",(double)(c[1]));
        continue;
    }
        double t1=0;
    for(int i=1;i<=n;i++){
        int less=i-1;
        t1+=(double)less/(double)(n-1);
    }
    t1/=n;
    double t2=0;
    for(int i=3;i<=n;i++) {
        int less=i-1;
        t2+=(double)(less*(less-1))/(double)((n-1)*(n-2));
    }
    t2/=n;
    double ans=0;
    for(int i=2;i<n;i++)
        ans+=c[i]*t2;
    ans+=c[1]*t1+c[n]*t1;
    printf("%.6lf\n",ans);
  }
} 
