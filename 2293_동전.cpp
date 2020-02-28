#include<iostream>
using namespace std;
int coin[1001];
int dp[10001];
int main(void)
{
	int n;
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - coin[i]];
		}
	}
	cout << dp[k];
	return 0;
}