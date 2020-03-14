#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
priority_queue<int, vector<int>, less<int>> arrf;
priority_queue<int, vector<int>, greater<int>> arrb;
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	int cnt = 0;
	for (int i = 0; i < testcase; i++)
	{
		int tmp;
		cin >> tmp;
		cnt++;
		if (arrf.size() == arrb.size())
		{
			arrf.push(tmp);
		}
		else
		{
			arrb.push(tmp);
		}
		if (!arrf.empty() && !arrb.empty() && arrf.top() > arrb.top())
		{
			int a = arrf.top();
			int b = arrb.top();
			arrf.pop();
			arrb.pop();
			arrf.push(b);
			arrb.push(a);
		}
		cout << arrf.top() << '\n';
	}
	return 0;
}