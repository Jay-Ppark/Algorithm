#include<iostream>
#include<cstdlib>
using namespace std;
int N;
int arr[20][20];
bool visited[20];
int minnum = 1000000;
void findteam(int cnt,int next) {
	if (cnt == N / 2) {
		int steam = 0;
		int lteam = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visited[i]) {
					if (visited[j]) {
						steam = steam + arr[i][j] + arr[j][i];
					}
				}
				else {
					if (!visited[j]) {
						lteam = lteam + arr[i][j] + arr[j][i];
					}
				}
			}
		}
		int temp = abs(steam - lteam);
		if (temp < minnum) {
			minnum = temp;
		}
	}
	for (int i = next; i < N; i++) {
		visited[i] = true;
		findteam(cnt + 1, i+1);
		visited[i] = false;
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	findteam(0, 0);
	cout << minnum;
	return 0;
}