#include<iostream>
using namespace std;
int N;
int times[16];
int money[16];
int dp[16];
int main(void){
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>times[i]>>money[i];
	}
	for(int i=N;i>=1;i--){
		if(i==N){
			if(i+times[i]<=N+1){
				dp[i]=dp[i]+money[i];
			}
		}
		if(i+times[i]<=N+1){
			dp[i]=max(dp[i+1],dp[i+times[i]]+money[i]);
		}
		else{
			dp[i]=dp[i+1];
		}
	}
	cout<<dp[1];
	return 0;
}