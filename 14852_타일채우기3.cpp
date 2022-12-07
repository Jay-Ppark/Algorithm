#include<iostream>
using namespace std;
long long int dp[1000001][2];
int main(void){
    int n;
    cin>>n;
    dp[1][0]=2;
    dp[2][1]=1;
    dp[2][0]=7;
    for(int i=3;i<=n;i++){
        dp[i][1]=(dp[i-1][1]+dp[i-3][0])%1000000007;
        dp[i][0]=(dp[i-1][0]*2+dp[i-2][0]*3+dp[i][1]*2)%1000000007;
    }
    cout<<dp[n][0];
    return 0;
}