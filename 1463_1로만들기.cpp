#include<iostream>
using namespace std;
int N;
int dp[1000001];
int main(void){
	cin>>N;
	for(int i=2;i<=1000000;i++){
		if(i%3==0&&i%2==0){
			dp[i]=min(min(dp[i/2],dp[i/3]),dp[i-1])+1;
		}
		else if(i%3==0){
			dp[i]=min(dp[i/3],dp[i-1])+1;
		}
		else if(i%2==0){
			dp[i]=min(dp[i/2],dp[i-1])+1;
		}
		else{
			dp[i]=dp[i-1]+1;
		}
	}
	cout<<dp[N];
	return 0;
}