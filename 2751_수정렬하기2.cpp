#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> >arr;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push(temp);
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << arr.top() << '\n';
		arr.pop();
	}
	return 0;
}