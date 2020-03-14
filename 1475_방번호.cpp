#include<iostream>
#include<string>
using namespace std;
int arr[9];
int main(void)
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			arr[0]++;
		}
		else if (s[i] == '1')
		{
			arr[1]++;
		}
		else if (s[i] == '2')
		{
			arr[2]++;
		}
		else if (s[i] == '3')
		{
			arr[3]++;
		}
		else if (s[i] == '4')
		{
			arr[4]++;
		}
		else if (s[i] == '5')
		{
			arr[5]++;
		}
		else if (s[i] == '6' || s[i] == '9')
		{
			arr[6]++;
		}
		else if (s[i] == '7')
		{
			arr[7]++;
		}
		else if (s[i] == '8')
		{
			arr[8]++;
		}
	}
	int maxnum = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == 6)
		{
			if (arr[i] % 2 == 0)
			{
				arr[i] = arr[i] / 2;
			}
			else
			{
				arr[i] = arr[i] / 2 + 1;
			}
		}
		if (maxnum < arr[i])
		{
			maxnum = arr[i];
		}
	}
	cout << maxnum;
	return 0;
}