#include<iostream>
#include<queue>
using namespace std;
bool visited[100001];
queue<int> q;
int startp, endp;
int cnt;
void BFS() {
	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int tmp = q.front();
			q.pop();
			if (tmp == endp) {
				return;
			}
			if (tmp - 1 >= 0 && !visited[tmp-1]) {
				q.push(tmp - 1);
				visited[tmp - 1] = true;
			}
			if (tmp + 1 <= 100000 && !visited[tmp+1]) {
				q.push(tmp + 1);
				visited[tmp + 1] = true;
			}
			if (tmp * 2 >= 0 && tmp * 2 <= 100000 && !visited[tmp*2]) {
				q.push(tmp * 2);
				visited[tmp * 2];
			}
		}
		cnt++;
	}
}
int main(void) {
	cin >> startp >> endp;
	q.push(startp);
	visited[startp] = true;
	BFS();
	cout << cnt;
	return 0;
}