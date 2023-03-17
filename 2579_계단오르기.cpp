#include<iostream>
using namespace std;
int stair[301];
int dp[301][3];
int main(void){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stair[i];
	}
	dp[1][1]=stair[1];
	dp[2][2]=stair[1]+stair[2];
	dp[2][1]=stair[2];
	for(int i=3;i<=n;i++){
		dp[i][1]=max(dp[i-2][1],dp[i-2][2])+stair[i];
		dp[i][2]=dp[i-1][1]+stair[i];
	}
	cout<<max(dp[n][1],dp[n][2]);
	return 0;
}