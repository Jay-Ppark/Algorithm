#include<iostream>
#include<vector>
using namespace std;
vector <int> virusX;
vector <int> virusY;
int lab[8][8];
int templab[8][8];
int tempvirus[8][8];
int height;
int width;
int result;
void spreadVirus()
{
	vector<int> tempvirusX;
	vector<int> tempvirusY;
	tempvirusX.resize(virusX.size());
	tempvirusY.resize(virusY.size());
	copy(virusX.begin(), virusX.end(), tempvirusX.begin());
	copy(virusY.begin(), virusY.end(), tempvirusY.begin());
	int temp = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			tempvirus[i][j] = templab[i][j];
		}
	}
	while (!tempvirusX.empty())
	{
		int tempX = tempvirusX.back();
		tempvirusX.pop_back();
		int tempY = tempvirusY.back();
		tempvirusY.pop_back();
		if (tempY - 1 >= 0)
		{
			if (tempvirus[tempY - 1][tempX] == 0)
			{
				tempvirus[tempY - 1][tempX] = 2;
				tempvirusX.push_back(tempX);
				tempvirusY.push_back(tempY - 1);
			}
		}
		if (tempY + 1 < height)
		{
			if (tempvirus[tempY + 1][tempX] == 0)
			{
				tempvirus[tempY + 1][tempX] = 2;
				tempvirusX.push_back(tempX);
				tempvirusY.push_back(tempY + 1);
			}
		}
		if (tempX - 1 >= 0)
		{
			if (tempvirus[tempY][tempX - 1] == 0)
			{
				tempvirus[tempY][tempX - 1] = 2;
				tempvirusX.push_back(tempX - 1);
				tempvirusY.push_back(tempY);
			}
		}
		if (tempX + 1 < width)
		{
			if (tempvirus[tempY][tempX + 1] == 0)
			{
				tempvirus[tempY][tempX + 1] = 2;
				tempvirusX.push_back(tempX + 1);
				tempvirusY.push_back(tempY);
			}
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (tempvirus[i][j] == 0)
			{
				temp++;
			}
		}
	}
	if (temp > result)
	{
		result = temp;
	}
}
void findSafe(int cnt)
{
	if (cnt == 3)
	{
		spreadVirus();
		return;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (templab[i][j] == 0)
			{
				templab[i][j] = 1;
				findSafe(cnt + 1);
				templab[i][j] = 0;
			}
		}
	}
}
int main(void)
{
	vector<int> tempV;
	cin >> height >> width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cin >> lab[i][j];
			templab[i][j] = lab[i][j];
			if (lab[i][j] == 2)
			{
				virusX.push_back(j);
				virusY.push_back(i);
			}
		}
	}
	findSafe(0);
	cout << result;
	return 0;
}