#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000001];
int main(void)
{
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 1000000; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
		{
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		else if (i % 2 == 0 && i % 3 != 0)
		{
			dp[i] = min(dp[i - 1] + 1, dp[i / 2] + 1);
		}
		else if (i % 2 != 0 && i % 3 == 0)
		{
			dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
		}
		else
		{
			dp[i] = 1 + dp[i - 1];
		}
	}
	int N;
	cin >> N;
	cout << dp[N];
	return 0;
}