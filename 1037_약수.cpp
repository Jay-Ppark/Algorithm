#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int> v;
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	if (N == 1)
	{
		cout << v[0] * v[0];
	}
	else
	{
		sort(v.begin(), v.end());
		cout << v.front() * v.back();
	}
	return 0;
}