#include<iostream>
using namespace std;
int arr[100][100];
bool visited[100];
int N, L;
int result;
void garo(int y) {
	int cur = arr[y][0];
	for (int i = 0; i < N; i++) {
		if (cur != arr[y][i]) {
			//범위가 넘어가는 경우
			if (abs(cur - arr[y][i]) != 1) {
				return;
			}
			//경사로 설치가능 확인
			else {
				//내리막길
				if (cur > arr[y][i]) {
					if (i + L <= N) {
						for (int j = i; j < i + L; j++) {
							if (arr[y][i] == arr[y][j]) {
								if (!visited[j]) {
									visited[j] = true;
								}
								else {
									return;
								}
							}
							else {
								return;
							}
						}
						i = i + L - 1;
					}
					else {
						return;
					}
				}
				//오르막길
				else {
					if (i - L >= 0) {
						for (int j = i - 1; j >= i - L; j--) {
							if (cur == arr[y][j]) {
								if (!visited[j]) {
									visited[j] = true;
								}
								else {
									return;
								}
							}
							else {
								return;
							}
						}
					}
					else {
						return;
					}
				}
			}
		}
		cur = arr[y][i];
	}
	result++;
}
void sero(int x) {
	int cur = arr[0][x];
	for (int i = 0; i < N; i++) {
		if (cur != arr[i][x]) {
			//범위가 넘어가는 경우
			if (abs(cur - arr[i][x]) != 1) {
				return;
			}
			//경사로 설치가능 확인
			else {
				//내리막길
				if (cur > arr[i][x]) {
					if (i + L <= N) {
						for (int j = i; j < i + L; j++) {
							if (arr[i][x] == arr[j][x]) {
								if (!visited[j]) {
									visited[j] = true;
								}
								else {
									return;
								}
							}
							else {
								return;
							}
						}
						i = i + L - 1;
					}
					else {
						return;
					}
				}
				//오르막길
				else {
					if (i - L >= 0) {
						for (int j = i - 1; j >= i - L; j--) {
							if (cur == arr[j][x]) {
								if (!visited[j]) {
									visited[j] = true;
								}
								else {
									return;
								}
							}
							else {
								return;
							}
						}
					}
					else {
						return;
					}
				}
			}
		}
		cur = arr[i][x];
	}
	result++;
}
void init() {
	for (int i = 0; i < 100; i++) {
		visited[i] = false;
	}
}
int main(void) {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	int temp = result;
	for (int i = 0; i < N; i++) {
		init();
		garo(i);
		init();
		sero(i);
	}
	cout << result;
	return 0;
}