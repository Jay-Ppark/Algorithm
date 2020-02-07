#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
int A[50];
int B[50];
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	sort(A, A + N, greater<int>());
	sort(B, B + N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = sum + A[i] * B[i];
	}
	cout << sum;
	return 0;
}