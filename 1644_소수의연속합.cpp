#include<iostream>
#include<deque>
using namespace std;
bool isnotprime[4000001];
deque<int> dq;
int N;
void findprime() {
	for (int i = 2; i <= N; i++) {
		if (!isnotprime[i]) {
			//dq.push_back(i);
			for (int j = i + i; j <= N; j += i) {
				isnotprime[j] = true;
			}
		}
	}
	
	for (int i = 2; i <= N; i++) {
		if (!isnotprime[i]) {
			dq.push_back(i);
		}
	}
	
}
int main(void) {
	cin >> N;
	findprime();
	/*
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i] << " ";
	}
	*/
	int result = 0;
	int dqsize = dq.size();
	while (dqsize!=0) {
		int tmpsum = 0;
		for (int i = 0; i < dqsize; i++) {
			tmpsum = tmpsum + dq[i];
			if (tmpsum == N) {
				result++;
				break;
			}
			if (tmpsum > N) {
				break;
			}
		}
		dq.pop_front();
		dqsize--;
	}
	cout << result;
	return 0;
}