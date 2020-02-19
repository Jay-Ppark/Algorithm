#include<iostream>
#include<deque>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	int k;
	cin >> k;
	deque <int> arr;
	int cnt = 1;
	for (int i = 1; i <= N; i++)
	{
		arr.push_back(i);
	}
	if (N == 1 && k == 1)
	{
		cout << "<1>";
	}
	else
	{
		while (!arr.empty())
		{
			for (int i = 1; i <= k; i++)
			{
				int temp = arr.front();
				arr.pop_front();
				if (i == k)
				{
					if (cnt == 1)
					{
						cout << "<" << temp << ", ";
					}
					else if (cnt == N)
					{
						cout << temp << ">";
					}
					else
					{
						cout << temp << ", ";
					}
					cnt++;
				}
				else
				{
					arr.push_back(temp);
				}
			}
		}
	}
	return 0;
}