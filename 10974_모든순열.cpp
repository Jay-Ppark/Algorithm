#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	do {
		for (int i = 0; i < N; i++) {
			cout << v[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}