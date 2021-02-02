#include<iostream>
using namespace std;
int dp[100001];
int main(void) {
	int N;
	cin >> N;
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1] * 2;
		dp[i] = dp[i] % 9901;
	}
	cout << dp[N];
	return 0;
}