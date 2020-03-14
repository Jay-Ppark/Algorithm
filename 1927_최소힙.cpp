#include<iostream>
using namespace std;
long long int arr[100001];
int arrcnt = 0;
void pushheap(long long int n)
{
	arrcnt++;
	arr[arrcnt] = n;
	int child = arrcnt;
	int parent = child / 2;
	while (child > 1 && arr[parent] > arr[child])
	{
		long long int tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
		child = parent;
		parent = child / 2;
	}
}
int deletheap()
{
	long long int result = arr[1];
	arr[1] = arr[arrcnt];
	arr[arrcnt] = 0;
	arrcnt--;
	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= arrcnt)
	{
		if (arr[child] > arr[child + 1])
		{
			child = child + 1;
		}
	}
	while (child <= arrcnt && arr[parent] > arr[child])
	{
		int tmp = arr[parent];
		arr[parent] = arr[child];
		arr[child] = tmp;
		parent = child;
		child = child * 2;
		if (child + 1 <= arrcnt)
		{
			if (arr[child] > arr[child + 1])
			{
				child = child + 1;
			}
		}
	}
	return result;
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++)
	{
		int command;
		cin >> command;
		if (command == 0)
		{
			if (arrcnt == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << deletheap() << '\n';
			}
		}
		else
		{
			pushheap(command);
		}
	}
	return 0;
}