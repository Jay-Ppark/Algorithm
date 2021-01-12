#include<iostream>
#include<algorithm>
using namespace std;
int arr[8];
bool visited[8];
int N, M;
void findarr(int cnt, int next) {
	if (cnt == M) {
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				cout << arr[i] << " ";
			}
		}
		cout << '\n';
		return;
	}
	for (int i = next; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			findarr(cnt + 1, i);
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	findarr(0, 0);
	return 0;
}