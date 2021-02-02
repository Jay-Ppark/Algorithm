#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> v;
void Hanoi(int diskN, int from, int by, int to) {
	if (diskN == 1) {
		v.push_back({ from,to });
	}
	else {
		Hanoi(diskN - 1, from, to, by);
		v.push_back({ from,to });
		Hanoi(diskN - 1, by, from, to);
	}
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	Hanoi(N, 1, 2, 3);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}