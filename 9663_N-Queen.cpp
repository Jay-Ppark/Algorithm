#include<iostream>
#include<cstdlib>
using namespace std;
int queens[14];
int N;
int result;
bool checkqueen(int q) {
	for (int j = 0; j < q; j++) {
		if ((queens[q] == queens[j]) || (q - j == abs(queens[q] - queens[j]))) {
			return false;
		}
	}
	return true;
}
void movequeen(int queen) {
	if (queen == N) {
		result++;
		return;
	}
	for (int i = 0; i < N; i++) {
		queens[queen] = i;
		if (checkqueen(queen)) {
			movequeen(queen + 1);
		}
	}
}
int main(void) {
	cin >> N;
	movequeen(0);
	cout << result;
	return 0;
}