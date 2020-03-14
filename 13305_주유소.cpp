#include<iostream>
using namespace std;
long long int city[100001];
long long int road[100001];
int main(void)
{
	int citynum;
	cin >> citynum;
	for (int i = 1; i < citynum; i++)
	{
		cin >> road[i];
	}
	for (int i = 1; i <= citynum; i++)
	{
		cin >> city[i];
	}
	long long int result = 0;
	int tmpindex = 1;
	result = result + city[1] * road[1];
	for (int i = 2; i < citynum; i++)
	{
		if (city[tmpindex] > city[i])
		{
			tmpindex = i;
		}
		result = result + city[tmpindex] * road[i];
	}
	cout << result;
	return 0;
}