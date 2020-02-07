#include<iostream>
#include<algorithm>
using namespace std;
long long int stair[300];
long long int dp[300];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> stair[i];
	}
	dp[0] = dp[0] + stair[0];
	dp[1] = dp[0] + stair[1];
	dp[2] = max(stair[1] + stair[2], stair[0] + stair[2]);
	for (int i = 3; i < N; i++)
	{
		dp[i] = max(dp[i-2]+stair[i],dp[i-3]+stair[i-1]+stair[i]);
	}
	cout << dp[N - 1];
	return 0;
}