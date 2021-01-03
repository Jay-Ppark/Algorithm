#include<iostream>
#include<vector>
using namespace std;
vector<int> result;
bool visited[50][50];
int grd[50][50];
int M, N, K;
int cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visited[i][j] = false;
			grd[i][j] = 0;
		}
	}
}
void DFS(int y, int x) {
	if (visited[y][x]) {
		return;
	}
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tmpy = y + dy[i];
		int tmpx = x + dx[i];
		if (tmpy >= 0 && tmpy < M && tmpx >= 0 && tmpx < N && !visited[tmpy][tmpx]) {
			if (grd[tmpy][tmpx] == 1) {
				DFS(tmpy, tmpx);
			}
		}
	}
}
int main(void) {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		init();
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int tmpy, tmpx;
			cin >> tmpy >> tmpx;
			grd[tmpy][tmpx] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && grd[i][j]==1 ) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		result.push_back(cnt);
		cnt = 0;
	}
	for (int j = 0; j < result.size(); j++) {
		cout << result[j] << '\n';
	}
	return 0;
}