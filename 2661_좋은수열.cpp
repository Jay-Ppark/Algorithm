#include<iostream>
#include<string>
using namespace std;
int N;
bool goodsequence;
bool checksequence(string s)
{
	int len = s.length();
	int comindex = len - 1;
	for (int i = 1; i <= len / 2; i++)
	{
		string fronts = s.substr(comindex - i, i);
		string backs = s.substr(comindex, i);
		if (!fronts.compare(backs))
		{
			return false;
		}
		comindex--;
	}
	return true;
}
void makesequence(int line,string s)
{
	if (goodsequence)
	{
		return;
	}
	if (!checksequence(s))
	{
		return;
	}
	if (line == N)
	{
		goodsequence = true;
		cout << s;
		return;
	}
	makesequence(line + 1, s + "1");
	makesequence(line + 1, s + "2");
	makesequence(line + 1, s + "3");
}
int main(void)
{
	cin >> N;
	makesequence(1, "1");
	return 0;
}