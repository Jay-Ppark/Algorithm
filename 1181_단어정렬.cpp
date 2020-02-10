#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> arr;
bool compare(string s1, string s2)
{
	if (s1.size() == s2.size())
	{
		return s1 < s2;
	}
	else
	{
		return s1.size() < s2.size();
	}
}
int main(void)
{
	int N;
	cin >> N;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end(), compare);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << '\n';
	}
	return 0;
}