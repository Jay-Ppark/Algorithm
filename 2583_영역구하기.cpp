#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int M, N, K;
int rg[100][100];
bool visited[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cnt;
vector<int> result;
void DFS(int y, int x) {
	visited[y][x] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int tmpy = y + dy[i];
		int tmpx = x + dx[i];
		if (tmpy >= 0 && tmpy < M && tmpx >= 0 && tmpx < N && !visited[tmpy][tmpx]) {
			if (rg[tmpy][tmpx] == 0) {
				DFS(tmpy, tmpx);
			}
		}
	}
}
int main(void) {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++) {
			for (int k = x1; k < x2; k++) {
				rg[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (rg[i][j] == 0 && !visited[i][j]) {
				DFS(i, j);
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}