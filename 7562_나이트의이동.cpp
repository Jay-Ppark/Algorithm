#include<iostream>
#include<queue>
using namespace std;
int gamesize;
bool visited[300][300];
int starty, startx;
int endy, endx;
int cnt;
int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
void init() {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			visited[i][j] = false;
		}
	}
}
void BFS() {
	cnt = 0;
	queue<pair<int, int>> q;
	q.push({ starty, startx });
	visited[starty][startx] = true;
	while (!q.empty()) {
		int qsize = q.size();
		for (int k = 0; k < qsize; k++) {
			int tmpy = q.front().first;
			int tmpx = q.front().second;
			q.pop();
			if (tmpy == endy && tmpx == endx) {
				return;
			}
			for (int i = 0; i < 8; i++) {
				int ttmpy = tmpy + dy[i];
				int ttmpx = tmpx + dx[i];
				if (ttmpy >= 0 && ttmpy < gamesize && ttmpx >= 0 && ttmpx < gamesize && !visited[ttmpy][ttmpx]) {
					visited[ttmpy][ttmpx] = true;
					q.push({ ttmpy,ttmpx });
				}
			}
		}
		cnt++;
	}
}
int main(void) {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> gamesize;
		cin >> starty >> startx;
		cin >> endy >> endx;
		if (startx == endx && starty == endy) {
			cout << 0 << '\n';
		}
		else {
			BFS();
			cout << cnt << '\n';
		}
		init();
	}
	return 0;
}