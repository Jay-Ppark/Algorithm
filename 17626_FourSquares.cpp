#include<iostream>
using namespace std;
int dp[50001];
int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=50000;i++){
        dp[i]=dp[i-1]+1;
        for(int j=1;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[N];
    return 0;
}