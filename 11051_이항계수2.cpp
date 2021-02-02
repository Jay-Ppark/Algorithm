#include<iostream>
using namespace std;
int arr[1001][1001];
int main(void) {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j == 1) {
				arr[i][j] = i;
			}
			else if (i == j || j==0) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
				arr[i][j] = arr[i][j] % 10007;
			}
		}
	}
	cout << arr[N][K] % 10007;
	return 0;
}