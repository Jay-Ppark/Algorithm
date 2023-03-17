#include<iostream>
using namespace std;
long long int dp[100001];
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,testcase;
    cin>>n>>testcase;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        dp[i]=dp[i-1]+tmp;
    }
    for(int t=1;t<=testcase;t++){
        int s,e;
        cin>>s>>e;
        cout<<dp[e]-dp[s-1]<<'\n';
    }
    return 0;
}