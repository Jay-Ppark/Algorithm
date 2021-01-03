#include<iostream>
using namespace std;
int paper[500][500];
bool visited[500][500];
int n, m;
int piccnt;
int maxpic;
int tmppic;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
void DFS(int y, int x) {
	tmppic++;
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tmpy = y + dy[i];
		int tmpx = x + dx[i];
		if (tmpy >= 0 && tmpy < n && tmpx >= 0 && tmpx < m && !visited[tmpy][tmpx]) {
			if (paper[tmpy][tmpx] == 1) {
				DFS(tmpy, tmpx);
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 1 && !visited[i][j]) {
				DFS(i, j);
				piccnt++;
				if (maxpic < tmppic) {
					maxpic = tmppic;
				}
				tmppic = 0;
			}
		}
	}
	cout << piccnt << '\n' << maxpic;
	return 0;
}