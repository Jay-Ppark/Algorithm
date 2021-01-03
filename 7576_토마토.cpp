#include<iostream>
#include<queue>
using namespace std;
int M, N;
int tmtcnt;
int tbox[1000][1000];
bool visited[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<pair<int,int>> q;
int main(void) {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tbox[i][j];
			if (tbox[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = true;
			}
			if (tbox[i][j] == 0) {
				tmtcnt++;
			}
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int tmpy = q.front().first;
			int tmpx = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ttmpy = tmpy + dy[j];
				int ttmpx = tmpx + dx[j];
				if (ttmpy >= 0 && ttmpy < N && ttmpx >= 0 && ttmpx < M && !visited[ttmpy][ttmpx]) {
					if (tbox[ttmpy][ttmpx] == 0) {
						q.push({ ttmpy,ttmpx });
						visited[ttmpy][ttmpx] = true;
						tmtcnt--;
					}
				}
			}
		}
		cnt++;
	}
	if (tmtcnt != 0) {
		cout << -1;
	}
	else {
		cout << cnt - 1;
	}
	return 0;
}