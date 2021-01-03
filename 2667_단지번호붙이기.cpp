#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char amap[25][25];
bool visited[25][25];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int cnt;
vector<int> result;
void DFS(int y, int x) {
	visited[y][x] = true;
	if (amap[y][x] == '0') {
		return;
	}
	else {
		cnt++;
		for (int i = 0; i < 4; i++) {
			int tmpy = y + dy[i];
			int tmpx = x + dx[i];
			if (tmpy >= 0 && tmpy < N && tmpx >= 0 && tmpx < N && !visited[tmpy][tmpx]) {
				DFS(tmpy, tmpx);
			}
		}
	}
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> amap[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && amap[i][j]=='1') {
				DFS(i, j);
				result.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	
	return 0;
}