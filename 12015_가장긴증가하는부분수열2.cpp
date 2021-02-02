#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main(void) {
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (v.empty()) {
			v.push_back(tmp);
			cnt++;
		}
		else {
			if (v.back() < tmp) {
				v.push_back(tmp);
				cnt++;
			}
			else {
				vector<int>::iterator it = lower_bound(v.begin(), v.end(), tmp);
				*it = tmp;
			}
		}
	}
	cout << cnt;
	return 0;
}