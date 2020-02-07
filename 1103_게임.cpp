#include<iostream>
using namespace std;
char board[50][50];
int main(void)
{
	int N;
	int M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	return 0;
}