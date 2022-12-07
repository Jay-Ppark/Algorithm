#include<iostream>
using namespace std;
int dp[31];
int main(void){
    int n;
    cin>>n;
    dp[2]=3;
    if(n%2==0){
        for(int i=4;i<=n;i++){
            dp[i]=dp[i-2]*3;
            int j=i-4;
            while(j>=0){
                dp[i]=dp[i]+dp[j]*2;
                j=j-2;
            }
            dp[i]=dp[i]+2;
        }
    }
    cout<<dp[n];
    return 0;
}