#include<iostream>
#include<vector>
using namespace std;
vector <int> v;
bool visited[21];
int answer;
int cnt;
int answerCnt;
int N;
void findAnswer(int start,int result)
{
	if (cnt > 0)
	{
		if (result == answer)
		{
			answerCnt++;
		}
	}
	for (int i = start; i <= N; i++)
	{
		if (!visited[i])
		{
			cnt++;
			visited[i] = true;
			findAnswer(i, result + v[i]);
			visited[i] = false;
		}
	}
}
int main(void)
{
	cin >> N >> answer;
	v.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	findAnswer(1, 0);
	cout << answerCnt;
	return 0;
}