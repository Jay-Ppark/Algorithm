#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001];
int dp[100001];
int main(void)
{
	int n;
	int result = -1000;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(result, dp[i]);
	}
	result = max(result, dp[1]);
	cout << result;
	return 0;
}