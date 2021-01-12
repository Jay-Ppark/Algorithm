#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
bool visited[9];
void findN(int cnt,int next) {
	if (cnt == M) {
		for (int i = 1; i <= N; i++) {
			if (visited[i]) {
				cout << i << " ";
			}
		}
		cout << '\n';
		return;
	}
	for (int i = next; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			findN(cnt + 1,i);
			visited[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> M;
	findN(0,1);
	return 0;
}