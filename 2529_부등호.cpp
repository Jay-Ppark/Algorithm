#include<iostream>
#include<string>
#include<vector>
using namespace std;
string command;
vector<int> minNum;
vector<int> maxNum;
bool Isvalid(vector<int> &v)
{
	for (int i = 0; i < command.size(); i++)
	{
		if (command[i] == '<' && v[i] > v[i + 1])
		{
			int tmp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = tmp;
			return false;
		}
		if (command[i] == '>' && v[i] < v[i + 1])
		{
			int tmp = v[i];
			v[i] = v[i + 1];
			v[i + 1] = tmp;
			return false;
		}
	}
	return true;
}
int main(void)
{
	int signnum;
	cin >> signnum;
	for (int i = 0; i < signnum; i++)
	{
		char tmp;
		cin >> tmp;
		command = command + tmp;
	}
	for (int i = 0; i <= signnum; i++)
	{
		minNum.push_back(i);
	}
	for (int i = 9; i >= 9 - signnum; i--)
	{
		maxNum.push_back(i);
	}
	while (1)
	{
		if (Isvalid(minNum))
		{
			break;
		}
	}
	while (1)
	{
		if (Isvalid(maxNum))
		{
			break;
		}
	}
	for (int i = 0; i < maxNum.size(); i++)
	{
		cout << maxNum[i];
	}
	cout << '\n';
	for (int i = 0; i < minNum.size(); i++)
	{
		cout << minNum[i];
	}
	return 0;
}