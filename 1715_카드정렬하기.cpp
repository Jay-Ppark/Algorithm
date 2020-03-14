#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;
int main(void)
{
	int cardcnt;
	cin >> cardcnt;
	long long int cnt = 0;
	priority_queue<long long int,vector<long long int>,greater<int>> arr;
	for (int i = 0; i < cardcnt; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push(tmp);
	}
	while (arr.size() > 1)
	{
		long long int topf = arr.top();
		arr.pop();
		long long int topb = arr.top();
		arr.pop();
		cnt = cnt + topf + topb;
		arr.push(topf + topb);
	}
	cout << cnt;
	return 0;
}