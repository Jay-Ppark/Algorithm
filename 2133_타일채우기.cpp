#include<iostream>
using namespace std;
int dp[31];
int main(void){
    int n;
    cin>>n;
    dp[2]=3;
    for(int i=4;i<=n;i=i+2){
        dp[i]=dp[i-2]*3+2;
        for(int j=i-4;j>=2;j=j-2){
            dp[i]=dp[i]+dp[j]*2;
        }
    }
    cout<<dp[n];
    return 0;
}