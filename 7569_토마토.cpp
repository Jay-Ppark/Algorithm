#include<iostream>
#include<queue>
using namespace std;
int tbox[100][100][100];
bool visited[100][100][100];
int M, N, H;
queue<pair<int, pair<int, int>>> q;
int tmtcnt;
int dz[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dx[6] = { 0,0,0,0,-1,1 };
int main(void) {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tbox[i][j][k];
				if (tbox[i][j][k] == 1) {
					q.push({ i,{j,k} });
					visited[i][j][k] = true;
				}
				if (tbox[i][j][k] == 0) {
					tmtcnt++;
				}
			}
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int tmpz = q.front().first;
			int tmpy = q.front().second.first;
			int tmpx = q.front().second.second;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int ttmpz = tmpz + dz[j];
				int ttmpy = tmpy + dy[j];
				int ttmpx = tmpx + dx[j];
				if (ttmpz >= 0 && ttmpz < H && ttmpy >= 0 && ttmpy < N && ttmpx >= 0 && ttmpx < M && !visited[ttmpz][ttmpy][ttmpx]) {
					if (tbox[ttmpz][ttmpy][ttmpx] == 0) {
						q.push({ ttmpz,{ttmpy,ttmpx} });
						visited[ttmpz][ttmpy][ttmpx] = true;
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