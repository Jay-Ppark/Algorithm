#include<iostream>
#include<vector>
using namespace std;
int grd[100][100];
bool visited[100][100];
int N;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int maxcnt;
int cnt;
void init()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = false;
		}
	}
}
void DFS(int y, int x,int height) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int tmpy = y + dy[i];
		int tmpx = x + dx[i];
		if (tmpy >= 0 && tmpy < N && tmpx >= 0 && tmpx < N && !visited[tmpy][tmpx]) {
			if (grd[tmpy][tmpx] >= height) {
				DFS(tmpy, tmpx, height);
			}
		}
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grd[i][j];
		}
	}
	for (int k = 1; k <= 100; k++) {
		cnt = 0;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && grd[i][j] >= k) {
					DFS(i, j, k);
					cnt++;
				}
			}
		}
		if (maxcnt < cnt) {
			maxcnt = cnt;
		}
	}
	cout << maxcnt;
	return 0;
}