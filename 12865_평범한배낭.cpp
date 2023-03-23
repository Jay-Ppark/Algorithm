#include<iostream>
using namespace std;
int w[101];
int v[101];
int dp[101][100001];
int main(void){
    int N,maxw;
    cin>>N>>maxw;
    for(int i=0;i<N;i++){
        cin>>w[i+1]>>v[i+1];   
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<=maxw;j++){
            if(j>=w[i]){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[N][maxw];
    return 0;
}