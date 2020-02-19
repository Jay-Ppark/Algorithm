#include<iostream>
using namespace std;
int tree[100000];
int treeGap[100000];
int getGcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		if (i >= 1)
		{
			treeGap[i] = tree[i] - tree[i - 1];
		}
	}
	int gap = 100000001;
	for (int i = 2; i < N; i++)
	{
		if (gap > getGcd(treeGap[i], treeGap[i - 1]))
		{
			gap = getGcd(treeGap[i], treeGap[i - 1]);
		}
	}
	int result = 0;
	for (int i = 1; i < N; i++)
	{
		result = result + treeGap[i] / gap - 1;
	}
	cout << result;
	return 0;
}