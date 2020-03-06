#include<iostream>
using namespace std;
int main(void)
{
	long long int A;
	long long int B;
	long long int V;
	cin >> A >> B >> V;
	long long int days = 0;
	if ((V - A) % (A - B) == 0)
	{
		days = (V - A) / (A - B) + 1;
	}
	else
	{
		days = (V - A) / (A - B) + 2;
	}
	cout << days;
	return 0;
}