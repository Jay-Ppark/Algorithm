#include<iostream>
using namespace std;
int N;
int red[1000];
int green[1000];
int blue[1000];
int dp[3][1000];
int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>red[i]>>green[i]>>blue[i];
	}
	dp[0][0]=red[0];
	dp[1][0]=green[0];
	dp[2][0]=blue[0];
	for(int i=1;i<N;i++){
		dp[0][i]=red[i]+min(dp[1][i-1],dp[2][i-1]);
		dp[1][i]=green[i]+min(dp[0][i-1],dp[2][i-1]);
		dp[2][i]=blue[i]+min(dp[0][i-1],dp[1][i-1]);
	}
	cout<<min(dp[2][N-1],min(dp[0][N-1],dp[1][N-1]));
	return 0;
}