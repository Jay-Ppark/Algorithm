#include<iostream>
using namespace std;
int card[1001];
int dp[1001];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> card[i];
	}
	dp[1] = card[1];
	for (int i = 2; i <= N; i++)
	{
		int temp = 0;
		for (int j = 1; j <= i; j++)
		{
			temp = card[j] + dp[i - j];
			if (temp > dp[i])
			{
				dp[i] = temp;
			}
		}
	}
	cout << dp[N];
	return 0;
}