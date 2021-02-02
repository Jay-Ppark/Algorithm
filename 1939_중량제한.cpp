#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int citynum, roadnum;
bool visitedcity[100001];
vector<pair<int, int>> v[100001];
int highwei;
int sfac, efac;
void init() {
	for (int i = 1; i <= 100000; i++) {
		visitedcity[i] = false;
	}
}
bool BFS(int w) {
	queue<int> q;
	visitedcity[sfac] = true;
	q.push(sfac);
	while (!q.empty()) {
		int tmps = q.front();
		q.pop();
		if (tmps == efac) {
			return true;
		}
		for (int i = 0; i < v[tmps].size(); i++) {
			int nextc = v[tmps][i].first;
			int tmpw = v[tmps][i].second;
			if (!visitedcity[nextc] && tmpw >= w) {
				visitedcity[nextc] = true;
				q.push(nextc);
			}
		}
	}
	return false;
}
int main(void) {
	cin >> citynum >> roadnum;
	for (int i = 0; i < roadnum; i++) {
		int startc, endc, wei;
		cin >> startc >> endc >> wei;
		if (highwei < wei) {
			highwei = wei;
		}
		v[startc].push_back({ endc,wei });
		v[endc].push_back({ startc,wei });
	}
	cin >> sfac >> efac;
	for (int i = 1; i <= citynum; i++) {
		sort(v[i].begin(), v[i].end());
	}
	//cout << "start" << '\n';
	int lowwei = 0;
	//cout << highwei << " " << lowwei << '\n';
	while (lowwei <= highwei) {
		int midwei = (lowwei + highwei) / 2;
		if (BFS(midwei)) {
			lowwei = midwei + 1;
		}
		else {
			highwei = midwei - 1;
		}
		init();
		//cout << highwei << " " << lowwei << '\n';
	}
	cout << highwei;
	return 0;
}