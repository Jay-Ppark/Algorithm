#include<iostream>
#include<vector>
using namespace std;
int N, M;
int arr[8][8];
bool visited[8][8];
vector<pair<pair<int, int>,int>> cctv;
vector<int> cctvangle;
//int cctvcnt;
int minresult = 10000;
void calarr(int cnt) {
	if (cctv.size() == cnt) {
		int tempcnt = 0;
		bool tmpvisited[8][8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				tmpvisited[i][j] = visited[i][j];
			}
		}
		for (int i = 0; i < cctvangle.size(); i++) {
			int y = cctv[i].first.first;
			int x = cctv[i].first.second;
			//num1 cctv
			if (cctv[i].second == 1) {
				//right
				//cout << "cctv1" << '\n';
				if (cctvangle[i] == 0) {
					for (int j = x; j < M; j++) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
				}
				//left
				else if (cctvangle[i] == 1) {
					for (int j = x; j >= 0; j--) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
				}
				//up
				else if (cctvangle[i] == 2) {
					for (int j = y; j >= 0; j--) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
				//down
				else {
					for (int j = y; j < N; j++) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
			}
			//num2 cctv
			else if (cctv[i].second == 2) {
				//left to right
				//cout << "cctv2" << '\n';
				bool checksix = false;
				if (cctvangle[i] % 2 == 0) {
					for (int j = 0; j < M; j++) {
						if (arr[y][j] == 6) {
							if (j < x) {
								for (int k = j+1; k < M; k++) {
									if (!tmpvisited[y][k]) {
										tmpvisited[y][k] = true;
									}
								}
								checksix = true;
								break;
							}
							else {
								for (int k = 0; k < j; k++) {
									if (!tmpvisited[y][k]) {
										tmpvisited[y][k] = true;
									}
								}
								checksix = true;
								break;
							}
						}
					}
					if (!checksix) {
						for (int j = 0; j < M; j++) {
							if (!tmpvisited[y][j]) {
								tmpvisited[y][j] = true;
							}
						}
					}
				}
				//up to down
				else{
					for (int j = 0; j < N; j++) {
						if (arr[j][x] == 6) {
							if (j < y) {
								for (int k = j+1; k < N; k++) {
									if (!tmpvisited[k][x]) {
										tmpvisited[k][x] = true;
									}
								}
								checksix = true;
								break;
							}
							else {
								for (int k = 0; k < j; k++) {
									if (!tmpvisited[k][x]) {
										tmpvisited[k][x] = true;
									}
								}
								checksix = true;
								break;
							}
						}
					}
					if (!checksix) {
						for (int j = 0; j < N; j++) {
							if (!tmpvisited[j][x]) {
								tmpvisited[j][x] = true;
							}
						}
					}
				}
			}
			//num3 cctv
			else if (cctv[i].second == 3) {
				//up right
				//cout << "cctv3" << '\n';
				if (cctvangle[i] == 0) {
					//up
					for (int j = y; j >= 0; j--) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
					//right
					for (int j = x; j < M; j++) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
				}
				//right down
				else if (cctvangle[i] == 1) {
					//right
					for (int j = x; j < M; j++) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
					//down
					for (int j = y; j < N; j++) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
				//down left
				else if (cctvangle[i] == 2) {
					//left
					for (int j = x; j >= 0; j--) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
					//down
					for (int j = y; j < N; j++) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
				//left up
				else {
					//left
					for (int j = x; j >= 0; j--) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
					//up
					for (int j = y; j >= 0; j--) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
			}
			//num4 cctv
			else if (cctv[i].second == 4) {
				//left to right, up
				//cout << "cctv4" << '\n';
				bool checksix = false;
				if (cctvangle[i] == 0) {
					//left to right
					for (int j = 0; j < M; j++) {
						if (arr[y][j] == 6) {
							if (j < x) {
								for (int k = j + 1; k < M; k++) {
									if (!tmpvisited[y][k]) {
										tmpvisited[y][k] = true;
									}
								}
								checksix = true;
								break;
							}
							else {
								for (int k = 0; k < j; k++) {
									if (!tmpvisited[y][k]) {
										tmpvisited[y][k] = true;
									}
								}
								checksix = true;
								break;
							}
						}
					}
					if (!checksix) {
						for (int j = 0; j < M; j++) {
							if (!tmpvisited[y][j]) {
								tmpvisited[y][j] = true;
							}
						}
					}
					//up
					for (int j = y; j >= 0; j--) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
				//up to down, right
				else if (cctvangle[i] == 1) {
					//up to down
					for (int j = 0; j < N; j++) {
						if (arr[j][x] == 6) {
							if (j < y) {
								for (int k = j + 1; k < N; k++) {
									if (!tmpvisited[k][x]) {
										tmpvisited[k][x] = true;
									}
								}
								checksix = true;
								break;
							}
							else {
								for (int k = 0; k < j; k++) {
									if (!tmpvisited[k][x]) {
										tmpvisited[k][x] = true;
									}
								}
								checksix = true;
								break;
							}
						}
					}
					if (!checksix) {
						for (int j = 0; j < N; j++) {
							if (!tmpvisited[j][x]) {
								tmpvisited[j][x] = true;
							}
						}
					}
					//right
					for (int j = x; j < M; j++) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
				}
				//left to right, down
				else if (cctvangle[i] == 2) {
					//left to right
					for (int j = 0; j < M; j++) {
						if (arr[y][j] == 6) {
							if (j < x) {
								for (int k = j+1; k < M; k++) {
									if (!tmpvisited[y][k]) {
										tmpvisited[y][k] = true;
									}
								}
								checksix = true;
								break;
							}
							else {
								for (int k = 0; k < j; k++) {
									if (!tmpvisited[y][k]) {
										tmpvisited[y][k] = true;
									}
								}
								checksix = true;
								break;
							}
						}
					}
					if (!checksix) {
						for (int j = 0; j < M; j++) {
							if (!tmpvisited[y][j]) {
								tmpvisited[y][j] = true;
							}
						}
					}
					//down
					for (int j = y; j < N; j++) {
						if (arr[j][x] == 6) {
							break;
						}
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
				//up to down, left
				else {
					//up to down
					for (int j = 0; j < N; j++) {
						if (arr[j][x] == 6) {
							if (j < y) {
								for (int k = j + 1; k < N; k++) {
									if (!tmpvisited[k][x]) {
										tmpvisited[k][x] = true;
									}
								}
								checksix = true;
								break;
							}
							else {
								for (int k = 0; k < j; k++) {
									if (!tmpvisited[k][x]) {
										tmpvisited[k][x] = true;
									}
								}
								checksix = true;
								break;
							}
						}
					}
					if (!checksix) {
						for (int j = 0; j < N; j++) {
							if (!tmpvisited[j][x]) {
								tmpvisited[j][x] = true;
							}
						}
					}
					//left
					for (int j = x; j >= 0; j--) {
						if (arr[y][j] == 6) {
							break;
						}
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
				}
			}
			//num5 cctv
			else {
				bool checksix = false;
				//cout << "cctv5" << '\n';
				//4way
				//left to right
				for (int j = 0; j < M; j++) {
					if (arr[y][j] == 6) {
						if (j < x) {
							for (int k = j + 1; k < M; k++) {
								if (!tmpvisited[y][k]) {
									tmpvisited[y][k] = true;
								}
							}
							checksix = true;
							break;
						}
						else {
							for (int k = 0; k < j; k++) {
								if (!tmpvisited[y][k]) {
									tmpvisited[y][k] = true;
								}
							}
							checksix = true;
							break;
						}
					}
				}
				if (!checksix) {
					for (int j = 0; j < M; j++) {
						if (!tmpvisited[y][j]) {
							tmpvisited[y][j] = true;
						}
					}
				}
				//up to down
				for (int j = 0; j < N; j++) {
					if (arr[j][x] == 6) {
						if (j < y) {
							for (int k = j + 1; k < N; k++) {
								if (!tmpvisited[k][x]) {
									tmpvisited[k][x] = true;
								}
							}
							checksix = true;
							break;
						}
						else {
							for (int k = 0; k < j; k++) {
								if (!tmpvisited[k][x]) {
									tmpvisited[k][x] = true;
								}
							}
							checksix = true;
							break;
						}
					}
				}
				if (!checksix) {
					for (int j = 0; j < N; j++) {
						if (!tmpvisited[j][x]) {
							tmpvisited[j][x] = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!tmpvisited[i][j]) {
					tempcnt++;
				}
			}	
		}
		//cout << "--------------" << '\n';
		//cout << tempcnt << '\n';
		if (tempcnt < minresult) {
			minresult = tempcnt;
		}
		return;
	}
	//cctv 개수 만큼
	for (int i = 0; i < 4; i++) {
		cctvangle.push_back(i);
		calarr(cnt + 1);
		cctvangle.pop_back();
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ { i,j },arr[i][j] });
				visited[i][j] = true;
				//cctvcnt++;
			}
			else if (arr[i][j] == 6) {
				visited[i][j] = true;
			}
		}
	}
	calarr(0);
	cout << minresult;
	//cout << cctv.size() << " " << cctvcnt;
	return 0;
}