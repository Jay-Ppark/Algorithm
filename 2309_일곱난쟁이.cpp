#include<iostream>
#include<algorithm>
using namespace std;
int height[9];
bool fakeheight[9];
int sum;
void calHeight()
{
	int temp = sum;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			temp = temp - height[i] - height[j];
			if (temp == 100)
			{
				fakeheight[i] = true;
				fakeheight[j] = true;
				break;
			}
			temp = sum;
		}
		if (temp == 100)
		{
			break;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		if (fakeheight[i] == false)
		{
			cout << height[i] << endl;
		}
	}
}
int main(void)
{
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum = sum + height[i];
	}
	sort(height, height + 9);
	calHeight();
	return 0;
}