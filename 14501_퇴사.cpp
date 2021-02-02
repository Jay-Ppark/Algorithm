#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int times[16];
int pay[16];
int dp[16];
int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> times[i] >> pay[i];
		dp[i] = pay[i];
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= times[j]) {
				dp[i] = max(dp[i], dp[j] + pay[i]);
			}
		}
	}
	int maxp = 0;
	for (int i = 1; i <= N; i++) {
		if (times[i] + i - 1<= N) {
			if (maxp < dp[i]) {
				maxp = dp[i];
			}
		}
	}
	cout << maxp;
	return 0;
}