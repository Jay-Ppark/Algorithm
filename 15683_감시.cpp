#include<iostream>
#include<vector>
using namespace std;
//{{ y, x }, cctv_num }
vector <pair<pair<int, int>, int >> cctv;
vector<int> angle;
int height, width;
int arr[8][8];
bool visited[8][8];
bool tmpvisited[8][8];
int minresult = 1000000;
void watch(int angledir, int y, int x) {
	//right
	if (angledir == 0) {
		for (int i = x; i < width; i++) {
			if (arr[y][i] == 6) {
				break;
			}
			if (!tmpvisited[y][i]) {
				tmpvisited[y][i] = true;
			}
		}
	}
	//down
	else if (angledir == 1) {
		for (int i = y; i < height; i++) {
			if (arr[i][x] == 6) {
				break;
			}
			if (!tmpvisited[i][x]) {
				tmpvisited[i][x] = true;
			}
		}
	}
	//left
	else if (angledir == 2) {
		for (int i = x; i >= 0; i--) {
			if (arr[y][i] == 6) {
				break;
			}
			if (!tmpvisited[y][i]) {
				tmpvisited[y][i] = true;
			}
		}
	}
	//up
	else if (angledir == 3) {
		for (int i = y; i >= 0; i--) {
			if (arr[i][x] == 6) {
				break;
			}
			if (!tmpvisited[i][x]) {
				tmpvisited[i][x] = true;
			}
		}
	}
}
void selectangle(int cnt) {
	if (cnt == cctv.size()) {
		//init tmpvisited
		int tmpresult = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				tmpvisited[i][j] = visited[i][j];
			}
		}
		for (int i = 0; i < cctv.size(); i++) {
			//cctv1
			//one dir
			int tmpy = cctv[i].first.first;
			int tmpx = cctv[i].first.second;
			int cctvnum = cctv[i].second;
			if (cctvnum == 1) {
				//angle[i] �������� watch
				watch(angle[i], tmpy, tmpx);
			}
			//left,right / up,down
			else if (cctvnum == 2) {
				//left,right
				if (angle[i] % 2 == 0) {
					watch(0, tmpy, tmpx);
					watch(2, tmpy, tmpx);
				}
				//up,down
				else {
					watch(1, tmpy, tmpx);
					watch(3, tmpy, tmpx);
				}
			}
			//90 angle two dir
			else if (cctv[i].second == 3) {
				//0 right, 1 down, 2 left, 3 up
				//up,right
				if (angle[i] == 0) {
					watch(3, tmpy, tmpx);
					watch(0, tmpy, tmpx);
				}
				//right,down
				else if (angle[i] == 1) {
					watch(0, tmpy, tmpx);
					watch(1, tmpy, tmpx);
				}
				//down,left
				else if (angle[i] == 2) {
					watch(1, tmpy, tmpx);
					watch(2, tmpy, tmpx);
				}
				//left,up
				else {
					watch(2, tmpy, tmpx);
					watch(3, tmpy, tmpx);
				}
			}
			//three dir
			else if (cctv[i].second == 4) {
				//left, up, right
				if (angle[i] == 0) {
					watch(2, tmpy, tmpx);
					watch(3, tmpy, tmpx);
					watch(0, tmpy, tmpx);
				}
				//up, right, down
				else if (angle[i] == 1) {
					watch(3, tmpy, tmpx);
					watch(0, tmpy, tmpx);
					watch(1, tmpy, tmpx);
				}
				//right, down, left
				else if (angle[i] == 2) {
					watch(0, tmpy, tmpx);
					watch(1, tmpy, tmpx);
					watch(2, tmpy, tmpx);
				}
				//down, left, up
				else {
					watch(1, tmpy, tmpx);
					watch(2, tmpy, tmpx);
					watch(3, tmpy, tmpx);
				}
			}
			//four dir
			else {
				watch(0, tmpy, tmpx);
				watch(1, tmpy, tmpx);
				watch(2, tmpy, tmpx);
				watch(3, tmpy, tmpx);
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (!tmpvisited[i][j]) {
					tmpresult++;
				}
			}
		}
		if (tmpresult < minresult) {
			minresult = tmpresult;
		}
		return;
	}
	// ��� ���� try
	for (int i = 0; i < 4; i++) {
		angle.push_back(i);
		selectangle(cnt + 1);
		angle.pop_back();
	}
}
int main(void) {
	//���� ���� �ִ� ũ�� �Է�
	cin >> height >> width;
	//�繫�� �� ĭ�� ���� �Է�
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> arr[i][j];
			//cctv�� ��� cctv vector�� �߰�
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ {i,j},arr[i][j] });
				visited[i][j] = true;
			}
			else if (arr[i][j] == 6) {
				visited[i][j] = true;
			}
		}
	}
	selectangle(0);
	cout << minresult;
	return 0;
}