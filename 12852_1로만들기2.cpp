#include<iostream>
using namespace std;
int dp[1000001];
int route[1000001];
int main(void){
    int N;
    cin>>N;
    dp[1]=0;
    for(int i=2;i<=N;i++){
        if(i%2==0&&i%3==0){
            if(dp[i/2]<dp[i/3]){
                route[i]=i/2;
                dp[i]=dp[i/2]+1;
            }
            else{
                route[i]=i/3;
                dp[i]=dp[i/3]+1;
            }
        }
        else if(i%3==0){
            if(dp[i-1]<dp[i/3]){
                route[i]=i-1;
                dp[i]=dp[i-1]+1;
            }
            else{
                route[i]=i/3;
                dp[i]=dp[i/3]+1;
            }
        }
        else if(i%2==0){
            if(dp[i/2]<dp[i-1]){
                route[i]=i/2;
                dp[i]=dp[i/2]+1;
            }
            else{
                route[i]=i-1;
                dp[i]=dp[i-1]+1;
            }
        }
        else{
            route[i]=i-1;
            dp[i]=dp[i-1]+1;
        }
    }
    cout<<dp[N]<<'\n';
    cout<<N<<' ';
    while(N!=1){
        N=route[N];
        cout<<N<<' ';
    }
    return 0;
}