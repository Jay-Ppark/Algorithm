#include<iostream>
using namespace std;
int dp[1000001];
int main(void) {
	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= 1000000; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i / 3]);
			dp[i] = min(dp[i], dp[i - 1]) + 1;
		}
		else if (i % 3 == 0 && i % 2 != 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 3 != 0 && i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	int N;
	cin >> N;
	cout << dp[N] << '\n';
	return 0;
}