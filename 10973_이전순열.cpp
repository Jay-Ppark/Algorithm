#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}
	}
	else {
		cout << -1;
	}
	return 0;
}