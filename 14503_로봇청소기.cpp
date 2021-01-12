#include<iostream>
#include<queue>
using namespace std;
int N, M;
int arr[50][50];
bool cleaned[50][50];
int startd, endd, dir;
int result;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
queue<pair<pair<int, int>, int>> q;
void BFS() {
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int d = q.front().second;
		q.pop();
		if (arr[y][x] == 0 && !cleaned[y][x]) {
			cleaned[y][x] = true;
			result++;
		}
		bool goback = false;
		for (int i = 0; i < 4; i++) {
			int tempd = (d + 3 - i) % 4;
			int tempy = y + dy[tempd];
			int tempx = x + dx[tempd];
			if (tempy >= 0 && tempy < N && tempx >= 0 && tempx < M && !cleaned[tempy][tempx]) {
				if (arr[tempy][tempx] == 0) {
					q.push({ {tempy,tempx},tempd });
					goback = true;
					break;
				}
			}
		}
		if (!goback) {
			int tempy = y + dy[(d + 2) % 4];
			int tempx = x + dx[(d + 2) % 4];
			if (tempy >= 0 && tempy < N && tempx >= 0 && tempx < M) {
				if (arr[tempy][tempx] == 1) {
					return;
				}
				else {
					q.push({ {tempy,tempx},d });
				}
			}
		}
	}
}
int main(void) {
	cin >> N >> M;
	cin >> startd >> endd >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	q.push({ {startd,endd},dir });
	BFS();
	cout << result;
	return 0;
}