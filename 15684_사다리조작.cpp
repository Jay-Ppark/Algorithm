#include<iostream>
using namespace std;
int seronum, garonum, garoH;
bool visited[30][11];
int stage;
bool haveroute;
void findroute(int cnt, int y) {
	if (stage == cnt) {
		if (haveroute) {
			return;
		}
		bool findanswer = true;
		for (int i = 1; i <= seronum; i++) {
			int startx = i;
			for (int j = 0; j < garoH; j++) {
				if (visited[j][startx]) {
					startx++;
				}
				else if (startx > 1 && visited[j][startx - 1]) {
					startx--;
				}
			}
			if (startx != i) {
				findanswer = false;
				break;
			}
		}
		if (findanswer) {
			haveroute = true;
		}
		return;
	}
	for (int i = y; i < garoH; i++) {
		for (int j = 1; j < seronum; j++) {
			if (!visited[i][j] && !visited[i][j - 1] && !visited[i][j + 1]) {
				visited[i][j] = true;
				findroute(cnt + 1, i);
				visited[i][j] = false;
			}
		}
	}
}
int main(void) {
	cin >> seronum >> garonum >> garoH;
	for (int i = 0; i < garonum; i++) {
		int a, b;
		cin >> a >> b;
		visited[a - 1][b] = true;
	}
	for (int i = 0; i < 4; i++) {
		stage = i;
		findroute(0, 0);
		if (haveroute) {
			cout << stage;
			break;
		}
	}
	if (!haveroute) {
		cout << -1;
	}
	return 0;
}