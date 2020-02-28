#include<iostream>
using namespace std;
int dp[2][41];
int main(void)
{
	int testcase;
	cin >> testcase;
	dp[0][0] = 1;
	dp[1][0] = 0;
	dp[0][1] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= 40; i++)
	{
		dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
		dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
	}
	for (int i = 0; i < testcase; i++)
	{
		int temp;
		cin >> temp;
		cout << dp[0][temp] << " " << dp[1][temp] << "\n";
	}
	return 0;
}