#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int mapsize;
int treenum;
int years;
int addnut[10][10];
int grd[10][10];
int dead[10][10];
vector<int>trees[10][10];
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
void spring() {
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			sort(trees[i][j].begin(), trees[i][j].end());
		}
	}
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (!trees[i][j].empty()) {
				for (int t = 0; t < trees[i][j].size(); t++) {
					if (trees[i][j][t] <= grd[i][j]) {
						//나이만큼 양분이 있을 경우
						grd[i][j] = grd[i][j] - trees[i][j][t];
						trees[i][j][t]++;
					}
					else {
						//양분이 부족한 경우
						for (int k = trees[i][j].size() - 1; k >= t; k--) {
							dead[i][j] = dead[i][j] + (trees[i][j][k]/2);
							trees[i][j].pop_back();
							treenum--;
						}
						break;
					}
				}
			}
		}
	}
}
void summer() {
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			grd[i][j] = grd[i][j] + dead[i][j];
			dead[i][j] = 0;
		}
	}
}
void fall() {
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			if (!trees[i][j].empty()) {
				for (int k = 0; k < trees[i][j].size(); k++) {
					if (trees[i][j][k] % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							int tmpy = i + dy[d];
							int tmpx = j + dx[d];
							if (tmpy >= 0 && tmpy < mapsize && tmpx >= 0 && tmpx < mapsize) {
								trees[tmpy][tmpx].push_back(1);
								treenum++;
							}
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			grd[i][j] = grd[i][j] + addnut[i][j];
		}
	}
}
int main(void) {
	cin >> mapsize >> treenum >> years;
	for (int i = 0; i < mapsize; i++) {
		for (int j = 0; j < mapsize; j++) {
			cin >> addnut[i][j];
			grd[i][j] = 5;
		}
	}
	for (int i = 0; i < treenum; i++) {
		int tmpy, tmpx, tmpage;
		cin >> tmpy >> tmpx >> tmpage;
		trees[tmpy-1][tmpx-1].push_back(tmpage);
	}
	for (int i = 0; i < years; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	cout << treenum;
	return 0;
}