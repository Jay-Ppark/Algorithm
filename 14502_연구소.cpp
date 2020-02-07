#include<iostream>
using namespace std;
int height;
int width;
int lab[8][8];
int templab[8][8];
int tempcopylab[8][8];
int result;
void copyLab()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			templab[i][j] = lab[i][j];
		}
	}
}
void resettemplab()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			tempcopylab[i][j] = templab[i][j];
		}
	}
}
void spreadVirus()
{
	resettemplab();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tempcopylab[i][j] == 2)
			{
				if (j - 1 >= 0 && tempcopylab[i][j - 1] == 0)
				{
					tempcopylab[i][j - 1] = 2;
				}
				if (j + 1 <= width && tempcopylab[i][j + 1] == 0)
				{
					tempcopylab[i][j + 1] = 2;
				}
				if (i - 1 >= 0 && tempcopylab[i - 1][j] == 0)
				{
					tempcopylab[i - 1][j] = 2;
				}
				if (i + 1 <= height && tempcopylab[i + 1][j] == 0)
				{
					tempcopylab[i + 1][j] = 2;
				}
			}
		}
	}
	int tempsum = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tempcopylab[i][j] == 0)
			{
				tempsum++;
			}
		}
	}
	if (result < tempsum)
	{
		result = tempsum;
	}
}
void makeWall(int cnt)
{
	if (cnt == 3)
	{
		cout << "----------------½ÃÀÛ------------------" << endl;
		for (int m = 0; m < height; m++) {
			for (int n = 0; n < width; n++)
			{
				cout << templab[m][n];
			}
			cout << endl;
		}
		cout << "------------------³¡-------------------" << endl;
		spreadVirus();
	}
	else
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (templab[i][j] == 0)
				{
					templab[i][j] = 1;
					cnt++;
					makeWall(cnt);
					templab[i][j] = 0;
				}
			}
		}
	}
}
int main(void)
{
	cin >> height >> width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> lab[i][j];
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (lab[i][j] == 0)
			{
				copyLab();
				templab[i][j] = 1;
				makeWall(1);
				templab[i][j] = 0;
			}
		}
	}
	cout << result;
	return 0;
}