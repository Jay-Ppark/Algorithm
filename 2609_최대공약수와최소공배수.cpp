#include<iostream>
using namespace std;
int bignum;
int smallnum;
int rest = 1;
int main(void)
{
	int a;
	int b;
	cin >> a >> b;
	if (a > b)
	{
		bignum = a;
		smallnum = b;
		while (smallnum != 0)
		{
			rest = bignum % smallnum;
			bignum = smallnum;
			smallnum = rest;
		}
		cout << bignum << '\n' << bignum * (a / bignum) * (b / bignum);
	}
	else if (a == b)
	{
		cout << a << '\n' << a;
	}
	else
	{
		bignum = b;
		smallnum = a;
		while (smallnum != 0)
		{
			rest = bignum % smallnum;
			bignum = smallnum;
			smallnum = rest;
		}
		cout << bignum << '\n' << bignum * (a / bignum) * (b / bignum);
	}
	return 0;
}