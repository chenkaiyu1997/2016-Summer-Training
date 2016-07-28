#include<bits/stdc++.h>
using namespace std;
//char s;
char s[201];
void yanzheng(){
    long long n;
    sscanf(s,"%I64d",&n);
    if(n>=4294967296LL || n==0){
        printf("TAT\n");    
        return;
    }
    for(int i=1;i<=5;i++){
        n=sqrt(n);
        if(n==1){
            printf("%d\n",i);
            return;
        }
    }
}
int main(){
    while(scanf("%s",s)!=EOF){
        if(strlen(s)>11)printf("TAT\n");
        else yanzheng();
    }
    return 0;
}
