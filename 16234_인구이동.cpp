#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;
int grd[50][50];
bool visited[50][50];
int mapsize;
int lnum, rnum;
bool finished;
int tmpsum;
int nationnum;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> v;
void BFS(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int tmpy = q.front().first;
			int tmpx = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ttmpy = tmpy + dy[j];
				int ttmpx = tmpx + dx[j];
				if (ttmpy >= 0 && ttmpy < mapsize && ttmpx >= 0 && ttmpx < mapsize) {
					if (!visited[ttmpy][ttmpx]) {
						if (abs(grd[tmpy][tmpx] - grd[ttmpy][ttmpx]) >= lnum && abs(grd[tmpy][tmpx] - grd[ttmpy][ttmpx]) <= rnum) {
							q.push({ ttmpy,ttmpx });
							v.push_back({ ttmpy,ttmpx });
							visited[ttmpy][ttmpx] = true;
							nationnum++;
							tmpsum = tmpsum + grd[ttmpy][ttmpx];
						}
					}
				}
			}
		}
	}
}
int main(void) {
	cin >> mapsize >> lnum >> rnum;
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			cin >> grd[i][j];
		}
	}
	int result = 0;
	while (!finished) {
		finished = true;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < mapsize; i++) {
			for (int j = 0; j < mapsize; j++) {
				if (!visited[i][j]) {
					nationnum = 1;
					tmpsum = grd[i][j];
					v.push_back({ i,j });
					BFS(i,j);
					if (nationnum >= 2) {
						finished = false;
						for (int i = 0; i < v.size(); i++) {
							grd[v[i].first][v[i].second] = (tmpsum / nationnum);
						}
					}
					v.clear();
				}
			}
		}
		result++;
	}
	cout << result - 1;
	return 0;
}