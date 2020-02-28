#include<iostream>
using namespace std;
int dp[1001];
int main(void)
{
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	int n;
	cin >> n;
	cout << dp[n];
	return 0;
}