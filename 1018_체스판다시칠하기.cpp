#include<iostream>
#include<string>
using namespace std;
char board[50][50];
int M, N;
string opt1 = "WBWBWBWB";
string opt2 = "BWBWBWBW";
int DFS(int h, int w) {
	if (h + 7 >= M || w + 7 >= N) {
		return -1;
	}
	else {
		int cnt1 = 0;
		int cnt2 = 0;
		int index = 0;
		for (int i = h; i < h + 8; i++) {
			for (int j = w; j < w + 8; j++) {
				if (i % 2 == 0) {
					if (board[i][j] != opt1[index]) {
						cnt1++;
					}
					if (board[i][j] != opt2[index]) {
						cnt2++;
					}
				}
				else {
					if (board[i][j] != opt2[index]) {
						cnt1++;
					}
					if (board[i][j] != opt1[index]) {
						cnt2++;
					}
				}
				index++;
			}
			index = 0;
		}
		if (cnt1 >= cnt2) {
			return cnt2;
		}
		else {
			return cnt1;
		}
	}
}
int main(void) {
	cin >> M >> N;
	for (int i = 0;  i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	int mintmp = 100;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = DFS(i, j);
			if (tmp != -1) {
				if (mintmp > tmp) {
					mintmp = tmp;
				}
			}
		}
	}
	cout << mintmp;
	return 0;
}