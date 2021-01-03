#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
int lab[8][8];
int templab[8][8];
int tempvirus[8][8];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int maxresult = 0;
void spreadVirus() {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tempvirus[i][j] = templab[i][j];
			if (templab[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int tmpy = q.front().first;
		int tmpx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ttmpy = tmpy + dy[i];
			int ttmpx = tmpx + dx[i];
			if (ttmpy >= 0 && ttmpy < N && ttmpx >= 0 && ttmpx < M && tempvirus[ttmpy][ttmpx]==0) {
				tempvirus[ttmpy][ttmpx] = 2;
				q.push({ ttmpy,ttmpx });
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tempvirus[i][j] == 0) {
				temp++;
			}
		}
	}
	if (temp > maxresult) {
		maxresult = temp;
	}
}
void findsafe(int cnt) {
	if (cnt == 3) {
		spreadVirus();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (templab[i][j] == 0) {
				templab[i][j] = 1;
				findsafe(cnt + 1);
				templab[i][j] = 0;
			}
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			templab[i][j] = lab[i][j];
		}
	}
	findsafe(0);
	cout << maxresult;
	return 0;
}