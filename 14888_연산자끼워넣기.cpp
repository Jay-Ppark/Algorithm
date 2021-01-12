#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int opt[4];
vector<int> opts;
vector<int> nums;
int maxnum = -1000000000;
int minnum = 1000000000;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> opt[i];
	}
	for (int i = 0; i < 4; i++) {
		if (opt[i] != 0) {
			for (int j = 0; j < opt[i]; j++) {
				opts.push_back(i);
			}
		}
	}
	do {
		int result = nums[0];
		for (int i = 0; i < opts.size(); i++) {
			if (opts[i] == 0) {
				result = result + nums[i + 1];
			}
			else if (opts[i] == 1) {
				result = result - nums[i + 1];
			}
			else if (opts[i] == 2) {
				result = result * nums[i + 1];
			}
			else {
				result = result / nums[i + 1];
			}
		}
		if (result > maxnum) {
			maxnum = result;
		}
		if (result < minnum) {
			minnum = result;
		}
	} while (next_permutation(opts.begin(), opts.end()));
	cout << maxnum << '\n' << minnum;
	return 0;
}