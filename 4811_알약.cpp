#include<iostream>
using namespace std;
//īŻ���� �̿��ؼ� Ǯ�ų�, dfs+dp �̿��ؼ� Ǯ��
long long medi[31][61];
long long cntmedi(int whole, int half)
{
	if (whole == 0)
	{
		return 1;
	}
	if (half == 0)
	{
		return cntmedi(whole - 1, half + 1);
	}
	if (medi[whole][half] > 0)
	{
		return medi[whole][half];
	}
	return medi[whole][half] = cntmedi(whole - 1, half + 1) + cntmedi(whole, half - 1);
}

int main(void)
{
	int medi;
	while (1)
	{
		cin >> medi;
		if (medi == 0)
		{
			break;
		}
		else
		{
			cout << cntmedi(medi, 0) << endl;
		}
	}
	return 0;
}