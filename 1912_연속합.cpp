#include<iostream>
using namespace std;
int arr[100000];
int dp[100000];
int maxnum = -1000000;
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	if (maxnum < dp[0]) {
		maxnum = dp[0];
	}
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		if (maxnum < dp[i]) {
			maxnum = dp[i];
		}
	}
	cout << maxnum;
	return 0;
}