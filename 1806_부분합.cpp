#include<iostream>
#include<algorithm>
using namespace std;
int arr[100000];
int main(void) {
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int leftn = 0;
	int rightn = 0;
	int result = 10000000;
	int tmpsum = arr[0];
	//int c = 0;
	while (leftn <= rightn && rightn < N) {
		if (tmpsum < S) {
			rightn++;
			tmpsum += arr[rightn];
		}
		else if (tmpsum == S) {
			result = min(result, (rightn - leftn + 1));
			rightn++;
			tmpsum += arr[rightn];
		}
		else if (tmpsum > S) {
			result = min(result, (rightn - leftn + 1));
			tmpsum -= arr[leftn];
			leftn++;
		}
	}
	if (result != 10000000) {
		cout << result;
	}
	else {
		cout << 0;
	}
	return 0;
}