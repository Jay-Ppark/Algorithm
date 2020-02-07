#include<iostream>
#include<algorithm>
using namespace std;
int arr[500000];
int findValue(int start_index, int end_index, int find_num)
{
	while (start_index <= end_index)
	{
		int mid = (start_index + end_index) / 2;
		int midvalue = arr[mid];
		if (midvalue < find_num)
		{
			start_index = mid + 1;
		}
		else if (midvalue > find_num)
		{
			end_index = mid - 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int answer_num = 0;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cin >> answer_num;
	sort(arr, arr + N);
	for (int i = 1; i <= answer_num; i++)
	{
		cin >> num;
		cout << findValue(0, N - 1, num) <<" ";
	}
	return 0;
}