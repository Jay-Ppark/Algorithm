#include<iostream>
#include<queue>
using namespace std;
bool visited[100][100];
char miro[100][100];
int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cnt = 1;
queue<pair<int, int>> q;
void BFS() {
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int tmpy = q.front().first;
			int tmpx = q.front().second;
			q.pop();
			if (tmpy == N - 1 && tmpx == M - 1) {
				return;
			}
			for (int j = 0; j < 4; j++) {
				int ttmpy = tmpy + dy[j];
				int ttmpx = tmpx + dx[j];
				if (ttmpy >= 0 && ttmpy < N && ttmpx >= 0 && ttmpx < M && !visited[ttmpy][ttmpx]) {
					if (miro[ttmpy][ttmpx] == '1') {
						q.push({ ttmpy,ttmpx });
						visited[ttmpy][ttmpx] = true;
					}
				}
			}
		}
		cnt++;
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> miro[i][j];
		}
	}
	visited[0][0] = true;
	q.push({ 0,0 });
	BFS();
	cout << cnt;
	return 0;
}