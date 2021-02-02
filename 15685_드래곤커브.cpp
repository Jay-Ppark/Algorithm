#include<iostream>
#include<vector>
using namespace std;
bool visited[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		vector<int> dragond;
		dragond.push_back(d);
		for (int i = 0; i < g; i++) {
			int dsize = dragond.size();
			for (int i = dsize-1; i >= 0; i--) {
				dragond.push_back((dragond[i] + 1) % 4);
			}
		}
		visited[x][y] = true;
		for (int i = 0; i < dragond.size(); i++) {
			x = x + dx[dragond[i]];
			y = y + dy[dragond[i]];
			visited[x][y] = true;
		}
	}
	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
				result++;
			}
		}
	}
	cout << result;
	return 0;
}