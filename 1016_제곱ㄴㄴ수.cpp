#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main(void)
{
	long long int max;
	long long int min;
	cin >> min >> max;
	for (int i = 1; i * i <= 1000000; i++)
	{
		v.push_back(i * i);
	}
	
	return 0;
}